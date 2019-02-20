//
//  NESFramebuffer.hpp
//  NESImage
//
//  Created by chen on 2018/7/31.
//  Copyright © 2018年 chen. All rights reserved.
//

#ifndef NESCGLFramebuffer_hpp
#define NESCGLFramebuffer_hpp

#include <stdio.h>
#include "NESCGLTypes.hpp"
#include "NESCGLTexture.hpp"
#include "NESCGL.hpp"

namespace NESCGL {
    
class NESCGLFramebuffer{
    
public:
    NESCGLFramebuffer(void);
    NESCGLFramebuffer(NESuint id);
    
    virtual ~NESCGLFramebuffer();
    
public:
    bool native_malloc = false;
    NESuint framebufferid;// gl framebuffer id, represent the native gl texure
    
private:
    NESCGLTexture *colorAttatchMent_0;// for ES 2.0 just color_0 is supported
//    NESCGLTexture *depthStencilAttatch;
    
public:
    void bindtoFramebuffer(void);//bind the framebufferid to GL_FRAMEBUFFER for use
    void bindtoFramebufferViewPort(NESRecti* viewport);
    //---------------&&&  warning lable  &&&---------------//
    //this operation would simply unbind this->framebufferid and do not rebind the last framebuffer
    void unAttatchFramebufferColorTexture(void);//unattatch the current colorAttatchment on framebufferid
    //---------------&&&  warning lable  &&&---------------//
    //this operate would simply bind this->framebufferid and not rebind the last framebuffer on using
    void framebufferAttatchColorTexture(NESCGLTexture* colorAttatchMent);//attatch colorAttatchMent to framebufferid
    
    static NESCGLFramebuffer* createFramebuffer(){
        NESuint framebuffers;
        
        nes_glGenFramebuffers(1, &framebuffers);
        NESCGLFramebuffer *output_framebuffer = new NESCGLFramebuffer(framebuffers);
        output_framebuffer->native_malloc = true;
        return output_framebuffer;
    }
    
};
    
inline NESCGLFramebuffer::~NESCGLFramebuffer(void)
{
    if(native_malloc){
        if(framebufferid){
            nes_glDeleteFramebuffers(1, &framebufferid);
        }
    }
}
    
inline NESCGLFramebuffer::NESCGLFramebuffer(void)
{
    framebufferid = 0;
}
    
inline NESCGLFramebuffer::NESCGLFramebuffer(NESuint id)
{
    framebufferid = id;
}

inline void NESCGLFramebuffer::bindtoFramebuffer(void)
{
    nes_glBindFramebuffer(GL_FRAMEBUFFER, framebufferid);
}

inline void NESCGLFramebuffer::unAttatchFramebufferColorTexture(void)
{
    nes_glBindFramebuffer(GL_FRAMEBUFFER, framebufferid);
    nes_glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, 0, 0);
}
    
inline void NESCGLFramebuffer::bindtoFramebufferViewPort(NESRecti* viewport)
{
    nes_glBindFramebuffer(GL_FRAMEBUFFER, framebufferid);
    nes_glViewport(viewport->x, viewport->y, viewport->width, viewport->height);
}
    
inline void NESCGLFramebuffer::framebufferAttatchColorTexture(NESCGLTexture* colorAttatchMent)
{
    if(!colorAttatchMent){
        return;
    }
    
    if(colorAttatchMent_0){//unattatch first
        unAttatchFramebufferColorTexture();
    }
    colorAttatchMent_0 = colorAttatchMent;
    nes_glBindFramebuffer(GL_FRAMEBUFFER, framebufferid);
    nes_glBindTexture(GL_TEXTURE_2D, colorAttatchMent_0->textureid);
    nes_glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D,
                               colorAttatchMent_0->textureid, 0);
}
    
    
    
}//end NESCGL


#endif /* NESCGLFramebuffer_hpp */
