//
//  NESFilter.h
//  NESImage
//
//  Created by chen on 2018/9/28.
//  Copyright © 2018年 chen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <NESOutput.h>
#import <NESInput.h>
#import <NESGLFramebuffer.h>

@protocol NESGLFilterNativeBridgeProtocol <NSObject>

//return the pointer of native filter object
- (void*)createNativeFilter:(const char*)vertexshader fragmentShader:(const char*)fragmentShader;

@end


@class NESGLTexture;

/**
 access the native NESCGLTexture object representing the texture,
 useful for further gl texture control
 @param texture object whose native object you want to obtain
 @return pointer to NESCGLTexture, may be NULL if the native object cant be not successfully created
 */
extern void* NES_get_native_texture(NESGLTexture *texture);

@interface NESGLFilter : NESOutput<NESInput, NESGLFilterNativeBridgeProtocol>
{
    NESGLFramebuffer *mRenderFramebuffer;
    NESImageOrientation mInputRotation;
    NESGLTexture *mInputTexture;
    
}

-(instancetype)initWithVertexShader:(const char*)vertexshader fragmentShader:(const char*)fragmentShader;


- (void)setupBufferForTargets;


@end






