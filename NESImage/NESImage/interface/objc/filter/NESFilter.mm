//
//  NESFilter.m
//  NESImage
//
//  Created by chen on 2018/9/28.
//  Copyright © 2018年 chen. All rights reserved.
//

#import "NESFilter.h"
#import "NESCGLTypes.hpp"

const char* default_glprogram_vertex_shader = NES_GL_SHADER
(
 attribute vec4 position;
 attribute vec4 inputTextureCoordinate;
 
 varying vec2 textureCoordinate;
 
 void main()
 {
     gl_Position = position;
     textureCoordinate = inputTextureCoordinate.xy;
 }
);

const char* default_glprogram_fragment_shader = NES_GL_SHADER
(
 varying highp vec2 textureCoordinate;
 
 uniform sampler2D inputImageTexture;
 
 void main()
 {
     gl_FragColor = texture2D(inputImageTexture, textureCoordinate);
 }
);


@interface NESFilter ()
{
    
    
}

@end


@implementation NESFilter

-(instancetype)init
{
    return [self initWithVertexShader:default_glprogram_vertex_shader
                       fragmentShader:default_glprogram_fragment_shader];
}

-(instancetype)initWithVertexShader:(const char*)vertexshader fragmentShader:(const char*)fragmentShader
{
    if(!(self = [super init])){
        return nil;
    }
    mProgram = [[NESGLProgram alloc] initWithVertexShader:vertexshader fragmentShader:fragmentShader];
    if(!mProgram){
        NSLog(@"can not successfully create glprogram on for NESFilter");
        return nil;
    }
    
    inputRotation = NESImageOrientationPortrait;
    
    return self;
}


- (void)setRenderFramebuffer:(NESGLFramebuffer*)framebuffer
{
    mRenderFramebuffer = framebuffer;
}
- (void)setRotation:(NESImageOrientation)rotation atIndex:(NSUInteger)index
{
    inputRotation = rotation;
}
- (void)setInputTexture:(NESGLTexture*)texture atIndex:(NSUInteger)index
{
    inputTexture = texture;
}

- (void)renderFrame:(CGRect)rect atTime:(CMTime)time
{
    if(!inputTexture){
        NSLog(@"input texture not ready");
        return;
    }
    
    [mProgram useProgram];
    [mRenderFramebuffer framebufferAttatchColorTexture:self.outputTexture];
    [mRenderFramebuffer bindtoFramebufferViewPort:CGRectMake(0, 0, self.outputTexture.textureSize.width,
                                                             self.outputTexture.textureSize.height)];
    
    
    
}


@end

