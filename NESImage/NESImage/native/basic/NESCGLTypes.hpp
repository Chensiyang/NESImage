//
//  NESCGLTypes.hpp
//  NESImage
//
//  Created by chen on 2018/7/31.
//  Copyright © 2018年 chen. All rights reserved.
//

#ifndef NESCGLTypes_hpp
#define NESCGLTypes_hpp


#include <stdio.h>

#include <OpenGLES/gltypes.h>
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

namespace NESCGL {
    
    typedef GLubyte     NESubyte;
    typedef GLbyte      NESbyte;
    typedef GLchar      NESchar;
    typedef GLushort    NESushort;
    typedef GLshort     NESshort;
    typedef GLuint      NESuint;
    typedef GLint       NESint;
    typedef GLfloat     NESfloat;
    typedef GLboolean   NESbool;
    typedef GLenum      NESenum;
    
    typedef struct NESVec2i{
        NESint x;
        NESint y;
    }NESVec2i;
    
    typedef struct NESVec2f{
        NESfloat x;
        NESfloat y;
    }NESVec2f;
    
    typedef struct NESRecti{
        NESint x;
        NESint y;
        NESint width;
        NESint height;
    }NESRecti;
    
    typedef struct NESRectf{
        NESfloat x;
        NESfloat y;
        NESfloat width;
        NESfloat height;
    }NESRectf;
    
    
#define NES_GLOPERATION_SKIP INT8_MIN       /* operation being skipped */
    
    
    
}//end NESCGL


#define NES_GL_SHADER(x) #x        //marco to define gl shader object

//---------------&&&  warning lable  &&&---------------//
//---------------***  error lable    ***---------------//


#endif /* NESCGLTypes_hpp */



