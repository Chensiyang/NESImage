//
//  NESTexture.m
//  NESImage
//
//  Created by chen on 2018/7/31.
//  Copyright © 2018年 chen. All rights reserved.
//

#import "NESGLTexture.h"
#import "NESCGLTexture.hpp"
#import "NESGLContext.h"
#import "NESGLTexturePool.h"

//default gl texture options for 2D texture
static const NESCGL::NESCGLTexture::NESCGLTextureOptions NESDefault2DTextureOptions =
{
    GL_RGBA,
    GL_CLAMP_TO_EDGE,
    GL_CLAMP_TO_EDGE,
    GL_LINEAR,
    GL_LINEAR
};

@interface NESGLTexture()
{
    NESCGL::NESCGLTexture::NESCGLTextureOptions texture_options;
    
    BOOL isGLTextureMemoryShared;
    
}

@property (assign, nonatomic) NESCGL::NESCGLTexture *cnative_texture;

@end


void* NES_get_native_texture(NESGLTexture *texture)
{
    if(!texture){
        return NULL;
    }
    return texture.cnative_texture;
}


@implementation NESGLTexture

-(void)dealloc
{
    [self cleanTextureRef];
    
    [self cleanNativeTexture];
    
}

- (void)cleanTextureRef
{
    if(_textureRef){
        CFRelease(_textureRef);
        _textureRef = NULL;
    }
    if(_textureBuffer){
        CFRelease(_textureBuffer);
        _textureBuffer = NULL;
    }
    
    CVOpenGLESTextureCacheFlush([NESGLTexturePool sharedTexturePool].textureCacheRef, 0);
}

- (void)cleanNativeTexture
{
    if(_cnative_texture){
        if(!isGLTextureMemoryShared){
            nes_glDeleteTextures(1, &(_cnative_texture->textureid));
        }
        delete _cnative_texture;
    }
}

-(instancetype)initWithImage:(UIImage *)image
{
    return [self initWithImageRef:image.CGImage];
}
-(instancetype)initWithImageRef:(CGImageRef)imageref
{
    if(!(self = [super init])){
        return nil;
    }
    if(!imageref){
        return nil;
    }
    
    int img_width = (int)CGImageGetWidth(imageref);
    int img_height = (int)CGImageGetHeight(imageref);
    if(0 >= img_width || 0 >= img_height){
        NSAssert(NO, @"receive zero size image on initWithImageRef");
        return nil;
    }
    
    _textureSize = CGSizeMake(img_width, img_height);
    CGSize pixelSizeToUseForTexture = _textureSize;
    
    int max_side = MAX(img_width, img_height);
    
    BOOL should_redraw_image = NO;
    GLint max_texture_for_device = [NESGLContext maxTextureSizeForCurrentDevice];
    if(max_side > max_texture_for_device){
        should_redraw_image = YES;
        if(_textureSize.width > _textureSize.height){
            _textureSize.height = _textureSize.height*(_textureSize.width/(CGFloat)max_texture_for_device);
            _textureSize.width = max_texture_for_device;
        }
        else{
            _textureSize.width = _textureSize.width*(_textureSize.height/(CGFloat)max_texture_for_device);
            _textureSize.height = max_texture_for_device;
        }
        pixelSizeToUseForTexture = _textureSize;
    }
    
    //copy form GPUImage
    //https://github.com/BradLarson/GPUImage
    //thanks BradLarson
    GLubyte *imageData = NULL;
    CFDataRef dataFromImageDataProvider = NULL;
    GLenum format = GL_BGRA;
    BOOL isLitteEndian = YES;
    BOOL alphaFirst = NO;
    BOOL premultiplied = NO;
    
    if (!should_redraw_image) {
        /* Check that the memory layout is compatible with GL, as we cannot use glPixelStore to
         * tell GL about the memory layout with GLES.
         */
        if (CGImageGetBytesPerRow(imageref) != CGImageGetWidth(imageref) * 4 ||
            CGImageGetBitsPerPixel(imageref) != 32 ||
            CGImageGetBitsPerComponent(imageref) != 8)
        {
            should_redraw_image = YES;
        } else {
            /* Check that the bitmap pixel format is compatible with GL */
            CGBitmapInfo bitmapInfo = CGImageGetBitmapInfo(imageref);
            if ((bitmapInfo & kCGBitmapFloatComponents) != 0) {
                /* We don't support float components for use directly in GL */
                should_redraw_image = YES;
            } else {
                CGBitmapInfo byteOrderInfo = bitmapInfo & kCGBitmapByteOrderMask;
                if (byteOrderInfo == kCGBitmapByteOrder32Little) {
                    /* Little endian, for alpha-first we can use this bitmap directly in GL */
                    CGImageAlphaInfo alphaInfo = (CGImageAlphaInfo)(bitmapInfo & kCGBitmapAlphaInfoMask);
                    if (alphaInfo != kCGImageAlphaPremultipliedFirst && alphaInfo != kCGImageAlphaFirst &&
                        alphaInfo != kCGImageAlphaNoneSkipFirst) {
                        should_redraw_image = YES;
                    }
                } else if (byteOrderInfo == kCGBitmapByteOrderDefault || byteOrderInfo == kCGBitmapByteOrder32Big) {
                    isLitteEndian = NO;
                    /* Big endian, for alpha-last we can use this bitmap directly in GL */
                    CGImageAlphaInfo alphaInfo = (CGImageAlphaInfo)(bitmapInfo & kCGBitmapAlphaInfoMask);
                    if (alphaInfo != kCGImageAlphaPremultipliedLast && alphaInfo != kCGImageAlphaLast &&
                        alphaInfo != kCGImageAlphaNoneSkipLast) {
                        should_redraw_image = YES;
                    } else {
                        /* Can access directly using GL_RGBA pixel format */
                        premultiplied = alphaInfo == kCGImageAlphaPremultipliedLast || alphaInfo == kCGImageAlphaPremultipliedLast;
                        alphaFirst = alphaInfo == kCGImageAlphaFirst || alphaInfo == kCGImageAlphaPremultipliedFirst;
                        format = GL_RGBA;
                    }
                }
            }
        }
    }
    
    if (should_redraw_image)
    {
        // For resized or incompatible image: redraw
        imageData = (GLubyte *) calloc(1, (int)pixelSizeToUseForTexture.width * (int)pixelSizeToUseForTexture.height * 4);
        
        CGColorSpaceRef genericRGBColorspace = CGColorSpaceCreateDeviceRGB();
        
        CGContextRef imageContext = CGBitmapContextCreate(imageData, (size_t)pixelSizeToUseForTexture.width, (size_t)pixelSizeToUseForTexture.height, 8, (size_t)pixelSizeToUseForTexture.width * 4, genericRGBColorspace,  kCGBitmapByteOrder32Little | kCGImageAlphaPremultipliedFirst);
        //        CGContextSetBlendMode(imageContext, kCGBlendModeCopy); // From Technical Q&A QA1708: http://developer.apple.com/library/ios/#qa/qa1708/_index.html
        CGContextDrawImage(imageContext, CGRectMake(0.0, 0.0, pixelSizeToUseForTexture.width, pixelSizeToUseForTexture.height), imageref);
        CGContextRelease(imageContext);
        CGColorSpaceRelease(genericRGBColorspace);
        isLitteEndian = YES;
        alphaFirst = YES;
        premultiplied = YES;
    }
    else
    {
        // Access the raw image bytes directly
        dataFromImageDataProvider = CGDataProviderCopyData(CGImageGetDataProvider(imageref));
        imageData = (GLubyte *)CFDataGetBytePtr(dataFromImageDataProvider);
    }
    
    texture_options = NESDefault2DTextureOptions;
    
    //for fastTexture, can not refresh texture data presented by gl
    _cnative_texture = NESCGL::NESCGLTexture::createTextureWithOptions((NESCGL::NESuint)_textureSize.width,
                                                                       (NESCGL::NESuint)_textureSize.height,
                                                                       texture_options);
    isGLTextureMemoryShared = NO;
    
    reference_count = 0;
    nes_glBindTexture(GL_TEXTURE_2D, _cnative_texture->textureid);
    nes_glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (int)pixelSizeToUseForTexture.width, (int)pixelSizeToUseForTexture.height, 0, format, GL_UNSIGNED_BYTE, imageData);
    nes_glBindTexture(GL_TEXTURE_2D, 0);
    
    if (should_redraw_image)
    {
        free(imageData);
    }
    else
    {
        if (dataFromImageDataProvider)
        {
            CFRelease(dataFromImageDataProvider);
        }
    }
    
    return self;
}

-(instancetype)initWithTextureBuffer:(CVPixelBufferRef)imagebuffer
{
    if(!(self = [super init])){
        return nil;
    }
    if(!imagebuffer){
        return nil;
    }
    
    CFRetain(imagebuffer);
    _textureBuffer = imagebuffer;
    
    _textureSize = CGSizeMake(CVPixelBufferGetWidth(imagebuffer),
                              CVPixelBufferGetHeight(imagebuffer));
    texture_options = NESDefault2DTextureOptions;
    
    CVOpenGLESTextureCacheCreateTextureFromImage(kCFAllocatorDefault,
                                                 [NESGLTexturePool sharedTexturePool].textureCacheRef,
                                                 _textureBuffer,
                                                 NULL,
                                                 GL_TEXTURE_2D,
                                                 GL_RGBA,
                                                 (int)_textureSize.width,
                                                 (int)_textureSize.height,
                                                 GL_BGRA,
                                                 GL_UNSIGNED_BYTE,
                                                 0,
                                                 &_textureRef);
    nes_glBindTexture(CVOpenGLESTextureGetTarget(_textureRef), CVOpenGLESTextureGetName(_textureRef));
    nes_glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, texture_options.wrap_s);
    nes_glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, texture_options.wrap_t);
    nes_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, texture_options.min_filter);
    nes_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, texture_options.mag_filter);
    nes_glBindTexture(GL_TEXTURE_2D, 0);
    
    if(_textureRef){
        _cnative_texture = new NESCGL::NESCGLTexture(CVOpenGLESTextureGetName(_textureRef),
                                                     (NESCGL::NESuint)_textureSize.width,
                                                     (NESCGL::NESuint)_textureSize.height);
    }
    
    isGLTextureMemoryShared = YES;
    
    reference_count = 0;
    
    return self;
}

-(instancetype)initWithImageSize:(CGSize)imagesize
{
    if(!(self = [super init])){
        return nil;
    }
    
    _textureSize = imagesize;
    texture_options = NESDefault2DTextureOptions;
    
    if([NESGLContext supportsSharedMemoryTexture]){
        
        [self createMemorySharedGLTexture];
        
        if(_textureRef){
            _cnative_texture = new NESCGL::NESCGLTexture(CVOpenGLESTextureGetName(_textureRef),
                                                        (NESCGL::NESuint)_textureSize.width,
                                                        (NESCGL::NESuint)_textureSize.height);
        }
        
        isGLTextureMemoryShared = YES;
    }
    else{
        
        _cnative_texture = NESCGL::NESCGLTexture::createTextureWithOptions((NESCGL::NESuint)_textureSize.width,
                                                        (NESCGL::NESuint)_textureSize.height,
                                                        texture_options);
        isGLTextureMemoryShared = NO;
    }
    
    reference_count = 0;
    
    return self;
}

-(instancetype)initWithImageSize:(CGSize)imagesize sharedMemory:(BOOL)sharedMemory
{
    if(!(self = [super init])){
        return nil;
    }
    
    _textureSize = imagesize;
    texture_options = NESDefault2DTextureOptions;
    
    if([NESGLContext supportsSharedMemoryTexture] && sharedMemory){
        
        [self createMemorySharedGLTexture];
        
        if(_textureRef){
            _cnative_texture = new NESCGL::NESCGLTexture(CVOpenGLESTextureGetName(_textureRef),
                                                         (NESCGL::NESuint)_textureSize.width,
                                                         (NESCGL::NESuint)_textureSize.height);
        }
        
        isGLTextureMemoryShared = YES;
    }
    else{
        
        _cnative_texture = NESCGL::NESCGLTexture::createTextureWithOptions((NESCGL::NESuint)_textureSize.width,
                                                                           (NESCGL::NESuint)_textureSize.height,
                                                                           texture_options);
        isGLTextureMemoryShared = NO;
    }
    
    reference_count = 0;
    
    return self;
}

-(BOOL)refreshContentWithTextureBuffer:(CVPixelBufferRef)imagebuffer
{
    if(!imagebuffer){
        return NO;
    }
    
    [self cleanTextureRef];
    
    CFRetain(imagebuffer);
    _textureBuffer = imagebuffer;
    
    _textureSize = CGSizeMake(CVPixelBufferGetWidth(imagebuffer),
                              CVPixelBufferGetHeight(imagebuffer));
    texture_options = NESDefault2DTextureOptions;
    
    CVOpenGLESTextureCacheCreateTextureFromImage(kCFAllocatorDefault,
                                                 [NESGLTexturePool sharedTexturePool].textureCacheRef,
                                                 _textureBuffer,
                                                 NULL,
                                                 GL_TEXTURE_2D,
                                                 GL_RGBA,
                                                 (int)_textureSize.width,
                                                 (int)_textureSize.height,
                                                 GL_BGRA,
                                                 GL_UNSIGNED_BYTE,
                                                 0,
                                                 &_textureRef);
    nes_glBindTexture(CVOpenGLESTextureGetTarget(_textureRef), CVOpenGLESTextureGetName(_textureRef));
    nes_glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, texture_options.wrap_s);
    nes_glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, texture_options.wrap_t);
    nes_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, texture_options.min_filter);
    nes_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, texture_options.mag_filter);
    nes_glBindTexture(GL_TEXTURE_2D, 0);
    
    if(_cnative_texture){
        _cnative_texture->textureid = CVOpenGLESTextureGetName(_textureRef);
        _cnative_texture->size.x = _textureSize.width;
        _cnative_texture->size.y = _textureSize.height;
    }
    isGLTextureMemoryShared = YES;
    
    reference_count = 0;
    
    return YES;
}

- (void)createMemorySharedGLTexture
{
    CFDictionaryRef empty;
    CFMutableDictionaryRef attrs;
    empty = CFDictionaryCreate(kCFAllocatorDefault, NULL, NULL, 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
    attrs = CFDictionaryCreateMutable(kCFAllocatorDefault, 1, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
    CFDictionarySetValue(attrs, kCVPixelBufferIOSurfacePropertiesKey, empty);
    
    CVReturn err = CVPixelBufferCreate(kCFAllocatorDefault,
                                       (int)_textureSize.width,
                                       (int)_textureSize.height,
                                       kCVPixelFormatType_32BGRA,   //should be bgra
                                       attrs, &_textureBuffer);
    if (err)
    {
        NSAssert(NO, @"Error at CVPixelBufferCreate %d, size: %f, %f",
                 err, _textureSize.width, _textureSize.height);
    }
    CVOpenGLESTextureCacheCreateTextureFromImage(kCFAllocatorDefault,
                                                 [NESGLTexturePool sharedTexturePool].textureCacheRef,
                                                 _textureBuffer,
                                                 NULL,
                                                 GL_TEXTURE_2D,
                                                 GL_RGBA,
                                                 (int)_textureSize.width,
                                                 (int)_textureSize.height,
                                                 GL_BGRA,
                                                 GL_UNSIGNED_BYTE,
                                                 0,
                                                 &_textureRef);
    
    nes_glBindTexture(CVOpenGLESTextureGetTarget(_textureRef), CVOpenGLESTextureGetName(_textureRef));
    nes_glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, texture_options.wrap_s);
    nes_glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, texture_options.wrap_t);
    nes_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, texture_options.min_filter);
    nes_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, texture_options.mag_filter);
    nes_glBindTexture(GL_TEXTURE_2D, 0);
}

-(uint32_t)textureId
{
    if(_cnative_texture){
        return _cnative_texture->textureid;
    }
    return 0;
}

- (void)textureRetain
{
    reference_count++;
}
- (void)textureRelease
{
    reference_count--;
    if(0 > reference_count){
        NSAssert(NO, @"over release texture on [textureRelease]");
    }
}
- (int)getReferenceCount
{
    return reference_count;
}


@end




