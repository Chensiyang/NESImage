//
//  NESGLFramebuffer.m
//  NESImage
//
//  Created by chen on 2018/8/15.
//  Copyright © 2018年 chen. All rights reserved.
//

#import "NESGLFramebuffer.h"
#import "NESCGLFramebuffer.hpp"

@interface NESGLFramebuffer()
{
    
    
}

@property (assign, nonatomic) NESCGL::NESCGLFramebuffer *cnative_framebuffer;

@end

void *NES_get_native_framebuffer(NESGLFramebuffer *framebuffer)
{
    if(!framebuffer){
        return NULL;
    }
    return framebuffer.cnative_framebuffer;
}

@implementation NESGLFramebuffer

-(void)dealloc
{
    [self cleanNativeFramebuffer];
}

- (void)cleanNativeFramebuffer
{
    if(_cnative_framebuffer){
        nes_glDeleteFramebuffers(1, &(_cnative_framebuffer->framebufferid));
        delete _cnative_framebuffer;
    }
}

-(instancetype)init
{
    if(!(self = [super init])){
        return nil;
    }
    
    [self createNativeFramebuffer];
    
    return self;
}

- (void)createNativeFramebuffer{
    
    _cnative_framebuffer = NESCGL::NESCGLFramebuffer::createFramebuffer();
    
}

-(uint32_t)framebufferId
{
    if(_cnative_framebuffer){
        return _cnative_framebuffer->framebufferid;
    }
    return 0;
}

- (void)bindtoFramebuffer
{
    if(_cnative_framebuffer){
        _cnative_framebuffer->bindtoFramebuffer();
    }
}
- (void)bindtoFramebufferViewPort:(CGRect)rect
{
    if(_cnative_framebuffer){
        NESCGL::NESRecti r_rect = NESCGL::NESRecti{
            static_cast<NESCGL::NESint>(rect.origin.x),
            static_cast<NESCGL::NESint>(rect.origin.y),
            static_cast<NESCGL::NESint>(rect.size.width),
            static_cast<NESCGL::NESint>(rect.size.height)
        };
        _cnative_framebuffer->bindtoFramebufferViewPort(&r_rect);
    }
}

- (void)framebufferAttatchColorTexture:(NESGLTexture*)texture
{
    if(_colorAttatchMent_0 != texture){
        _colorAttatchMent_0 = texture;
        if(_cnative_framebuffer){
            _cnative_framebuffer->
            framebufferAttatchColorTexture((NESCGL::NESCGLTexture*)NES_get_native_texture(texture));
        }
    }
}

@end




