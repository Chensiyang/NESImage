//
//  NESGLFramebuffer.h
//  NESImage
//
//  Created by chen on 2018/8/15.
//  Copyright © 2018年 chen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <NESGLTexture.h>

@class NESGLFramebuffer;

/**
 access the native NESCGLFramebuffer object representing the framebuffer,
 useful for further gl framebuffer control
 @param framebuffer object whose native object you want to obtain
 @return pointer to NESCGLFramebuffer, may be NULL if the native object cant be not successfully created
 */
extern void* NES_get_native_framebuffer(NESGLFramebuffer *framebuffer);


@interface NESGLFramebuffer : NSObject

@property (strong, nonatomic) NESGLTexture *colorAttatchMent_0;//current colorAttatchMent

@property (assign, nonatomic) uint32_t framebufferId;// gl framebuffer id, represent the native gl texure

- (void)bindtoFramebuffer;//bind the framebufferid to GL_FRAMEBUFFER for use
- (void)bindtoFramebufferViewPort:(CGRect)rect;//bind the framebufferid to GL_FRAMEBUFFER for use and set framebuffer viewport
- (void)framebufferAttatchColorTexture:(NESGLTexture*)texture;//attatch colorAttatchMent to framebufferid

@end


