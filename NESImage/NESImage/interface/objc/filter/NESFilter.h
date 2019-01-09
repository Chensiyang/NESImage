//
//  NESFilter.h
//  NESImage
//
//  Created by chen on 2018/9/28.
//  Copyright © 2018年 chen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NESOutput.h"
#import "NESInput.h"
#import "NESGLProgram.h"
#import "NESGLFramebuffer.h"

extern const char* default_glprogram_vertex_shader;
extern const char* default_glprogram_fragment_shader;

@interface NESFilter : NESOutput<NESInput>
{
    NESGLProgram *mProgram;
    NESGLFramebuffer *mRenderFramebuffer;
    NESImageOrientation inputRotation;
    NESGLTexture *inputTexture;
    
}

-(instancetype)initWithVertexShader:(const char*)vertexshader fragmentShader:(const char*)fragmentShader;


@end

