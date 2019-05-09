//
//  NESGaussianFilter.m
//  NESImage
//
//  Created by chen on 2019/3/24.
//  Copyright © 2019年 chen. All rights reserved.
//

#import "NESGLGaussianFilter.h"
#import "NESCGLGaussianFilter.hpp"
#import "NESGLTexturePool.h"

@interface NESGLGaussianFilter()
{
    NESCGL::NESCGLGaussianFilter* cnative_gaussian_filter;
    
    NESGLTexture* mVertialTexture;
}

@end


@implementation NESGLGaussianFilter

- (void*)createNativeFilter:(const char*)vertexshader fragmentShader:(const char*)fragmentShader
{
    cnative_gaussian_filter = new NESCGL::NESCGLGaussianFilter();
    return cnative_gaussian_filter;
}

- (void)setInputTexture:(NESGLTexture*)texture atIndex:(NSUInteger)index
{
    [super setInputTexture:texture atIndex:index];
    if(!mVertialTexture || !CGSizeEqualToSize(texture.textureSize, mVertialTexture.textureSize)){
        [self recreate_vertical_texture:texture.textureSize];
        
        if(cnative_gaussian_filter){
            NESCGL::NESCGLTexture* t_native_texture =
            (NESCGL::NESCGLTexture*)NES_get_native_texture(mVertialTexture);
            cnative_gaussian_filter->update_vertical_texture(t_native_texture);
        }
    }
}

- (void)recreate_vertical_texture:(CGSize)size
{
    [[NESGLContext sharedContext] activeAsCurrentContext];
    mVertialTexture = nil;
    
    mVertialTexture = [[NESGLTexture alloc] initWithImageSize:size];
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
    
    if(cnative_gaussian_filter){
        NESCGL::NESRecti render_rect;
        render_rect.x = 0;
        render_rect.y = 0;
        render_rect.width = (int)rect.size.width;
        render_rect.height = (int)rect.size.height;
        
        NESCGL::NESCGLFramebuffer *cnative_render_framebuffer = (NESCGL::NESCGLFramebuffer*)NES_get_native_framebuffer(mRenderFramebuffer);
        NESCGL::NESCGLTexture *cnative_inputtexture = (NESCGL::NESCGLTexture*)NES_get_native_texture(mInputTexture);
        
        cnative_gaussian_filter->render(cnative_render_framebuffer, &render_rect, cnative_inputtexture);
    }
    
    [self setupBufferForTargets];
    [self notifyTargetsNewRenderReady:time];
    
}

@end


