//
//  NESTexture.h
//  NESImage
//
//  Created by chen on 2018/7/31.
//  Copyright © 2018年 chen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreVideo/CoreVideo.h>

@class NESGLTexture;

/**
 access the native NESCGLTexture object representing the texture,
 useful for further gl texture control
 @param texture object whose native object you want to obtain
 @return pointer to NESCGLTexture, may be NULL if the native object cant be not successfully created
 */
extern void* NES_get_native_texture(NESGLTexture *texture);


typedef struct NESGLTextureOptions{
    uint32_t wrap_s;
    uint32_t wrap_t;
    uint32_t min_filter;
    uint32_t mag_filter;
}NESGLTextureOptions;

@interface NESGLTexture : NSObject
{
    int reference_count;
}

@property (assign, nonatomic) uint32_t textureId;
@property (assign, nonatomic) CGSize textureSize;

@property (assign, nonatomic) CVPixelBufferRef textureBuffer;//texture databuffer, only available for ios5.0 above
@property (assign, nonatomic) CVOpenGLESTextureRef textureRef;//texture handle object, only available for ios5.0 above


-(instancetype)initWithImage:(UIImage *)image;
-(instancetype)initWithImageRef:(CGImageRef)imageref;

-(instancetype)initWithImageSize:(CGSize)imagesize;

-(instancetype)initWithTextureBuffer:(CVPixelBufferRef)imagebuffer;
-(BOOL)refreshContentWithTextureBuffer:(CVPixelBufferRef)imagebuffer;


- (CGImageRef)createImageFromTexture;

- (void)textureRetain;
- (void)textureRelease;
- (int)getReferenceCount;


@end


