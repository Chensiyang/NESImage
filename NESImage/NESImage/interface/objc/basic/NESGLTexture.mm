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

@interface NESGLTexture()
{
    NESCGL::NESCGLTexture::NESCGLTextureOptions texture_options;
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
    if(_textureRef){
        CFRelease(_textureRef);
        _textureRef = NULL;
    }
    if(_textureBuffer){
        CFRelease(_textureBuffer);
        _textureBuffer = NULL;
    }
    
    CVOpenGLESTextureCacheFlush([NESGLTexturePool sharedTexturePool].textureCacheRef, 0);
    
    if(_cnative_texture){
        nes_glDeleteTextures(1, &(_cnative_texture->textureid));
        delete _cnative_texture;
    }
}

-(instancetype)initWithImageSize:(CGSize)imagesize
{
    if(!(self = [super init])){
        return nil;
    }
    
    _textureSize = imagesize;
    texture_options = NESCGL::NESCGLTexture::NESDefault2DTextureOptions;
    
    if([NESGLContext supportsSharedMemoryTexture]){
        
        [self createMemorySharedGLTexture];
        
        if(_textureRef){
            _cnative_texture = new NESCGL::NESCGLTexture(CVOpenGLESTextureGetName(_textureRef),
                                                        (NESCGL::NESuint)imagesize.width,
                                                        (NESCGL::NESuint)imagesize.height);
        }
    }
    else{
        
        _cnative_texture = NESCGL::NESCGLTexture::createTextureWithOptions((NESCGL::NESuint)imagesize.width,
                                                        (NESCGL::NESuint)imagesize.height,
                                                        texture_options);
    }
    
    refrence_count = 0;
    
    return self;
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
    
}

-(uint32_t)textureId
{
    if(_textureRef){
        return CVOpenGLESTextureGetName(_textureRef);
    }
    if(_cnative_texture){
        return _cnative_texture->textureid;
    }
    return 0;
}

- (void)textureRetain
{
    refrence_count++;
}
- (void)textureRelease
{
    refrence_count--;
    if(0 > refrence_count){
        NSAssert(NO, @"over release texture on [textureRelease]");
    }
}
- (int)getRefrenceCount
{
    return refrence_count;
}


@end




