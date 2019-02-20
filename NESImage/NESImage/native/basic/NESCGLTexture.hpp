//
//  NESTexture.hpp
//  NESImage
//
//  Created by chen on 2018/7/31.
//  Copyright © 2018年 chen. All rights reserved.
//

#ifndef NESCGLTexture_hpp
#define NESCGLTexture_hpp

#include <stdio.h>
#include "NESCGLTypes.hpp"
#include "NESCGL.hpp"

namespace NESCGL {

class NESCGLTexture{
    
public:
    typedef struct NESCGLTextureOptions{
        NESenum internelFormat;
        NESenum wrap_s;
        NESenum wrap_t;
        NESenum min_filter;
        NESenum mag_filter;
        
    }NESCGLTextureOptions;
    
public:
    // empty
    NESCGLTexture(void);
    NESCGLTexture(NESuint id, NESuint width, NESuint height);
    NESCGLTexture(NESuint id, NESVec2i texSize);
    // virtual destructor
    virtual ~NESCGLTexture();
    
public:
    bool native_malloc = false;
    NESVec2i size; //size of texture in pixel
    NESuint textureid; // gl texture id represent the native gl texure
    
public:
    void bindToTextureUnit(NESenum TextureUnit);//bind the textureid to TextureUnit for use
    
    
    static NESCGLTexture* createTextureWithOptions(NESuint width,
                                                   NESuint height,
                                                   NESCGLTextureOptions options){
        NESuint texture;
        nes_glGenTextures(1, &texture);
        if(0 >= texture){
            printf("can not create texture on createTextureWithOptions\n");
            return NULL;
        }
        nes_glActiveTexture(GL_TEXTURE1);
        nes_glBindTexture(GL_TEXTURE_2D, texture);
        nes_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, options.wrap_s);
        nes_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, options.wrap_t);
        nes_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, options.min_filter);
        nes_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, options.mag_filter);
        nes_glBindTexture(GL_TEXTURE_2D, 0);
        
        NESCGLTexture *output_texture = new NESCGLTexture(texture, width, height);
        output_texture->native_malloc = true;
        return output_texture;
    }
    static NESCGLTexture* createTextureWithOptions(NESuint width,
                                                   NESuint height,
                                                   NESCGLTextureOptions options,
                                                   NESenum dataformat,
                                                   NESenum datatype,
                                                   const NESubyte* data){
        if(!data){
            return NULL;
        }
        NESuint texture;
        nes_glGenTextures(1, &texture);
        if(0 >= texture){
            printf("can not create texture on createTextureWithOptions\n");
            return NULL;
        }
        nes_glActiveTexture(GL_TEXTURE1);
        nes_glBindTexture(GL_TEXTURE_2D, texture);
        nes_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, options.wrap_s);
        nes_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, options.wrap_t);
        nes_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, options.min_filter);
        nes_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, options.mag_filter);
        nes_glTexImage2D(GL_TEXTURE_2D, 0, options.internelFormat, width, height,
                         0, dataformat, datatype, data);
        nes_glBindTexture(GL_TEXTURE_2D, 0);
        
        NESCGLTexture *output_texture = new NESCGLTexture(texture, width, height);
        output_texture->native_malloc = true;
        return output_texture;
    }
    
};
    
inline NESCGLTexture::~NESCGLTexture(void)
{
    if(native_malloc){
        if(textureid){
            nes_glDeleteTextures(1, &textureid);
        }
    }
}
    
inline NESCGLTexture::NESCGLTexture(void)
{
    textureid = 0;
    size.x = 0;
    size.y = 0;
}

inline NESCGLTexture::NESCGLTexture(NESuint id, NESuint width, NESuint height)
{
    textureid   = id;
    size.x      = width;
    size.y      = height;
};
    
inline NESCGLTexture::NESCGLTexture(NESuint id, NESVec2i texSize)
{
    textureid   = id;
    size = texSize;
}

inline void NESCGLTexture::bindToTextureUnit(NESenum TextureUnit)
{
    nes_glBindTexture(TextureUnit, textureid);
}
    
}//end NESCGL

#endif /* NESCGLTexture_hpp */


