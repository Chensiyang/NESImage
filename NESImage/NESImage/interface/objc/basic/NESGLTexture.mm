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




