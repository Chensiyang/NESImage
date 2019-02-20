//
//  NESFilter.m
//  NESImage
//
//  Created by chen on 2018/9/28.
//  Copyright © 2018年 chen. All rights reserved.
//

#import "NESGLFilter.h"
#import "NESCGLTypes.hpp"
#import "NESCGLFilter.hpp"
#import "NESGLTexturePool.h"

@interface NESGLFilter ()
{
    NESCGL::NESCGLFramebuffer *cnative_render_framebuffer;
    NESCGL::NESCGLTexture *cnative_inputtexture;
    
    NESCGL::NESRecti render_rect;
    
}

@property (assign, nonatomic) NESCGL::NESCGLFilter *cnative_filter;

@end


@implementation NESGLFilter

-(void)dealloc
{
    [self cleanNativeFilter];
}

- (void)cleanNativeFilter
{
    if(_cnative_filter){
        delete _cnative_filter;
    }
}

-(instancetype)init
{
    return [self initWithVertexShader:NESCGL::default_glprogram_vertex_shader
                       fragmentShader:NESCGL::default_glprogram_fragment_shader];
}

-(instancetype)initWithVertexShader:(const char*)vertexshader fragmentShader:(const char*)fragmentShader
{
    if(!(self = [super init])){
        return nil;
    }
    
    [self setupNativeFilter:vertexshader fragmentShader:fragmentShader];
    
    [self commonInit];
    
    mInputRotation = NESImageOrientationPortrait;
    
    return self;
}

- (void)setupNativeFilter:(const char*)vertexshader fragmentShader:(const char*)fragmentShader{
    
    _cnative_filter = new NESCGL::NESCGLFilter(vertexshader, fragmentShader);
    
}

- (void)commonInit{
    
    
}

- (void)setRenderFramebuffer:(NESGLFramebuffer*)framebuffer
{
    mRenderFramebuffer = framebuffer;
    cnative_render_framebuffer = (NESCGL::NESCGLFramebuffer*)NES_get_native_framebuffer(mRenderFramebuffer);
}
- (void)setRotation:(NESImageOrientation)rotation atIndex:(NSUInteger)index
{
    mInputRotation = rotation;
}
- (void)setInputTexture:(NESGLTexture*)texture atIndex:(NSUInteger)index
{
    mInputTexture = texture;
    cnative_inputtexture = (NESCGL::NESCGLTexture*)NES_get_native_texture(mInputTexture);
}

- (void)renderFrame:(CGRect)rect atTime:(CMTime)time
{
    if(!mInputTexture){
        NSLog(@"input texture not ready");
        return;
    }
    
    if(!self.outputTexture){
        self.outputTexture = [[NESGLTexturePool sharedTexturePool]
                              fetchTextureFromPool:mInputTexture.textureSize.width
                              height:mInputTexture.textureSize.height];
    }
    if(CGRectIsNull(self.renderRect)){
        self.renderRect = CGRectMake(0, 0,
                                     self.outputTexture.textureSize.width,
                                     self.outputTexture.textureSize.height);
    }
    [mRenderFramebuffer framebufferAttatchColorTexture:self.outputTexture];
    
    if(_cnative_filter){
        render_rect.x = 0;
        render_rect.y = 0;
        render_rect.width = (int)rect.size.width;
        render_rect.height = (int)rect.size.height;
        _cnative_filter->render(cnative_render_framebuffer, &render_rect, cnative_inputtexture);
    }
    
    [self setupBufferForTargets];
    [self notifyTargetsNewRenderReady:time];
    
}

- (void)setupBufferForTargets
{
    for(int i = 0; i < mtargets.count; i++){
        id<NESInput> i_t = [mtargets objectAtIndex:i];
        int i_i = [mtargetsOutputIndices objectAtIndex:i].intValue;
        [self setInputTextureForTarget:i_t atIndex:i_i];
        [i_t setRenderFramebuffer:mRenderFramebuffer];
    }
}


@end

