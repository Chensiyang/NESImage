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

@interface NESGLFilter : NESOutput<NESInput>
{
    NESGLFramebuffer *mRenderFramebuffer;
    NESImageOrientation mInputRotation;
    NESGLTexture *mInputTexture;
    
}

-(instancetype)initWithVertexShader:(const char*)vertexshader fragmentShader:(const char*)fragmentShader;



@end

