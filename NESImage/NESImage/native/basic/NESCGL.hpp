//
//  NESGL.hpp
//  NESImage
//
//  Created by chen on 2018/8/1.
//  Copyright © 2018年 chen. All rights reserved.
//
//
//              OpenGL ES interface encapsulation
//
//
//


#ifndef NESCGL_hpp
#define NESCGL_hpp

#include "NESCGLTypes.hpp"
#include "NESCGLHelper.hpp"

#ifdef __cplusplus
extern "C" {
#endif
    
/*-------------------------------------------------------------------------
 * Entrypoint definitions
 *-----------------------------------------------------------------------*/
    
void   nes_glActiveTexture (GLenum texture)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glActiveTexture(texture);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glActiveTexture(texture);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glActiveTexture(texture);
        }
    }
}
    
void   nes_glAttachShader (GLuint program, GLuint shader)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glAttachShader(program, shader);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glAttachShader(program, shader);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glAttachShader(program, shader);
        }
    }
}
    
void   nes_glBindAttribLocation (GLuint program, GLuint index, const GLchar* name)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glBindAttribLocation(program, index, name);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glBindAttribLocation(program, index, name);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glBindAttribLocation(program, index, name);
        }
    }
}
    
void    nes_glBindBuffer (GLenum target, GLuint buffer)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glBindBuffer(target, buffer);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glBindBuffer(target, buffer);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glBindBuffer(target, buffer);
        }
    }
}
    
void    nes_glBindFramebuffer (GLenum target, GLuint framebuffer)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glBindFramebuffer(target, framebuffer);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glBindFramebuffer(target, framebuffer);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glBindFramebuffer(target, framebuffer);
        }
    }
}
    
void    nes_glBindRenderbuffer (GLenum target, GLuint renderbuffer)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glBindRenderbuffer (target, renderbuffer);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glBindRenderbuffer (target, renderbuffer);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glBindRenderbuffer (target, renderbuffer);
        }
    }
}
    
void    nes_glBindTexture (GLenum target, GLuint texture)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glBindTexture(target, texture);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glBindTexture(target, texture);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glBindTexture(target, texture);
        }
    }
}
    
void    nes_glBlendColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glBlendColor (red, green, blue, alpha);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glBlendColor (red, green, blue, alpha);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glBlendColor (red, green, blue, alpha);
        }
    }
}
    
void    nes_glBlendEquation (GLenum mode)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glBlendEquation(mode);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glBlendEquation(mode);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glBlendEquation(mode);
        }
    }
}
    
void    nes_glBlendEquationSeparate (GLenum modeRGB, GLenum modeAlpha)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glBlendEquationSeparate(modeRGB, modeAlpha);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glBlendEquationSeparate(modeRGB, modeAlpha);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glBlendEquationSeparate(modeRGB, modeAlpha);
        }
    }
}
    
void    nes_glBlendFunc (GLenum sfactor, GLenum dfactor)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glBlendFunc(sfactor, dfactor);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glBlendFunc(sfactor, dfactor);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glBlendFunc(sfactor, dfactor);
        }
    }
}
    
void    nes_glBlendFuncSeparate (GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
        }
    }
}
    
void    nes_glBufferData (GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glBufferData(target, size, data, usage);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glBufferData(target, size, data, usage);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glBufferData(target, size, data, usage);
        }
    }
}
    
void    nes_glBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid* data)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glBufferSubData(target, offset, size, data);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glBufferSubData(target, offset, size, data);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glBufferSubData(target, offset, size, data);
        }
    }
}
    
GLenum  nes_glCheckFramebufferStatus (GLenum target)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        return glCheckFramebufferStatus(target);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            return glCheckFramebufferStatus(target);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            return glCheckFramebufferStatus(target);
        }
    }
    return NES_GLOPERATION_SKIP;
}
    
void    nes_glClear (GLbitfield mask)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glClear(mask);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glClear(mask);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glClear(mask);
        }
    }
}
    
void    nes_glClearColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glClearColor(red, green, blue, alpha);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glClearColor(red, green, blue, alpha);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glClearColor(red, green, blue, alpha);
        }
    }
}
    
void    nes_glClearDepthf (GLclampf depth)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glClearDepthf(depth);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glClearDepthf(depth);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glClearDepthf(depth);
        }
    }
}
    
void    nes_glClearStencil (GLint s)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glClearStencil(s);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glClearStencil(s);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glClearStencil(s);
        }
    }
}
    
void    nes_glColorMask (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glColorMask(red, green, blue, alpha);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glColorMask(red, green, blue, alpha);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glColorMask(red, green, blue, alpha);
        }
    }
}
    
void    nes_glCompileShader (GLuint shader)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glCompileShader(shader);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glCompileShader(shader);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glCompileShader(shader);
        }
    }
}
    
void   nes_glCompressedTexImage2D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid* data)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
        }
    }
}
    
void    nes_glCompressedTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid* data)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glCompressedTexSubImage2D(target, level, xoffset, yoffset,
                                  width, height, format, imageSize, data);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glCompressedTexSubImage2D(target, level, xoffset, yoffset,
                                      width, height, format, imageSize, data);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glCompressedTexSubImage2D(target, level, xoffset, yoffset,
                                      width, height, format, imageSize, data);
        }
    }
}

void    nes_glCopyTexImage2D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
        }
    }
}

void    nes_glCopyTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
        }
    }
}

GLuint  nes_glCreateProgram (void)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        return glCreateProgram();
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            return glCreateProgram();
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            return glCreateProgram();
        }
    }
    return NES_GLOPERATION_SKIP;
}
    
GLuint  nes_glCreateShader (GLenum type)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        return glCreateShader(type);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            return glCreateShader(type);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            return glCreateShader(type);
        }
    }
    return NES_GLOPERATION_SKIP;
}
    
void    nes_glCullFace (GLenum mode)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glCullFace(mode);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glCullFace(mode);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glCullFace(mode);
        }
    }
}

void    nes_glDeleteBuffers (GLsizei n, const GLuint* buffers)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glDeleteBuffers(n, buffers);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glDeleteBuffers(n, buffers);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glDeleteBuffers(n, buffers);
        }
    }
}
    
void    nes_glDeleteFramebuffers (GLsizei n, const GLuint* framebuffers)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glDeleteFramebuffers(n, framebuffers);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glDeleteFramebuffers(n, framebuffers);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glDeleteFramebuffers(n, framebuffers);
        }
    }
}
    
void    nes_glDeleteProgram (GLuint program)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glDeleteProgram(program);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glDeleteProgram(program);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glDeleteProgram(program);
        }
    }
}
    
void    nes_glDeleteRenderbuffers (GLsizei n, const GLuint* renderbuffers)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glDeleteRenderbuffers(n, renderbuffers);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glDeleteRenderbuffers(n, renderbuffers);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glDeleteRenderbuffers(n, renderbuffers);
        }
    }
}
    
void    nes_glDeleteShader (GLuint shader)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glDeleteShader(shader);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glDeleteShader(shader);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glDeleteShader(shader);
        }
    }
}
    
void    nes_glDeleteTextures (GLsizei n, const GLuint* textures)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glDeleteTextures(n, textures);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glDeleteTextures(n, textures);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glDeleteTextures(n, textures);
        }
    }
}
    
void    nes_glDepthFunc (GLenum func)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glDepthFunc(func);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glDepthFunc(func);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glDepthFunc(func);
        }
    }
}
    
void    nes_glDepthMask (GLboolean flag)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glDepthMask(flag);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glDepthMask(flag);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glDepthMask(flag);
        }
    }
}
    
void    nes_glDepthRangef (GLclampf zNear, GLclampf zFar)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glDepthRangef(zNear, zFar);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glDepthRangef(zNear, zFar);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glDepthRangef(zNear, zFar);
        }
    }
}
    
void    nes_glDetachShader (GLuint program, GLuint shader)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glDetachShader(program, shader);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glDetachShader(program, shader);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glDetachShader(program, shader);
        }
    }
}
    
void    nes_glDisable (GLenum cap)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glDisable(cap);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glDisable(cap);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glDisable(cap);
        }
    }
}
    
void    nes_glDisableVertexAttribArray (GLuint index)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glDisableVertexAttribArray(index);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glDisableVertexAttribArray(index);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glDisableVertexAttribArray(index);
        }
    }
}
    
void    nes_glDrawArrays (GLenum mode, GLint first, GLsizei count)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glDrawArrays(mode, first, count);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glDrawArrays(mode, first, count);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glDrawArrays(mode, first, count);
        }
    }
}
void    nes_glDrawElements (GLenum mode, GLsizei count, GLenum type, const GLvoid* indices)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glDrawElements(mode, count, type, indices);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glDrawElements(mode, count, type, indices);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glDrawElements(mode, count, type, indices);
        }
    }
}
    
void    nes_glEnable (GLenum cap)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glEnable(cap);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glEnable(cap);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glEnable(cap);
        }
    }
}
    
void    nes_glEnableVertexAttribArray (GLuint index)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glEnableVertexAttribArray(index);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glEnableVertexAttribArray(index);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glEnableVertexAttribArray(index);
        }
    }
}
    
void    nes_glFinish (void)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glFinish();
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glFinish();
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glFinish();
        }
    }
}
    
void    nes_glFlush (void)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glFlush();
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glFlush();
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glFlush();
        }
    }
}
    
void    nes_glFramebufferRenderbuffer (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
        }
    }
}
    
void    nes_glFramebufferTexture2D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glFramebufferTexture2D(target, attachment, textarget, texture, level);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glFramebufferTexture2D(target, attachment, textarget, texture, level);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glFramebufferTexture2D(target, attachment, textarget, texture, level);
        }
    }
}
    
void    nes_glFrontFace (GLenum mode)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glFrontFace(mode);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glFrontFace(mode);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glFrontFace(mode);
        }
    }
}
    
void    nes_glGenBuffers (GLsizei n, GLuint* buffers)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glGenBuffers(n, buffers);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glGenBuffers(n, buffers);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glGenBuffers(n, buffers);
        }
    }
}
    
void    nes_glGenerateMipmap (GLenum target)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glGenerateMipmap(target);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glGenerateMipmap(target);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glGenerateMipmap(target);
        }
    }
}
    
void    nes_glGenFramebuffers (GLsizei n, GLuint* framebuffers)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glGenFramebuffers(n, framebuffers);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glGenFramebuffers(n, framebuffers);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glGenFramebuffers(n, framebuffers);
        }
    }
}
    
void    nes_glGenRenderbuffers (GLsizei n, GLuint* renderbuffers)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glGenRenderbuffers(n, renderbuffers);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glGenRenderbuffers(n, renderbuffers);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glGenRenderbuffers(n, renderbuffers);
        }
    }
}
    
void    nes_glGenTextures (GLsizei n, GLuint* textures)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glGenTextures(n, textures);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glGenTextures(n, textures);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glGenTextures(n, textures);
        }
    }
}
    
void    nes_glGetActiveAttrib (GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, GLchar* name)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glGetActiveAttrib(program, index, bufsize, length, size, type, name);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glGetActiveAttrib(program, index, bufsize, length, size, type, name);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glGetActiveAttrib(program, index, bufsize, length, size, type, name);
        }
    }
}
    
void    nes_glGetActiveUniform (GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, GLchar* name)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glGetActiveUniform(program, index, bufsize, length, size, type, name);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glGetActiveUniform(program, index, bufsize, length, size, type, name);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glGetActiveUniform(program, index, bufsize, length, size, type, name);
        }
    }
}
    
void    nes_glGetAttachedShaders (GLuint program, GLsizei maxcount, GLsizei* count, GLuint* shaders)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glGetAttachedShaders(program, maxcount, count, shaders);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glGetAttachedShaders(program, maxcount, count, shaders);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glGetAttachedShaders(program, maxcount, count, shaders);
        }
    }
}
    
int     nes_glGetAttribLocation (GLuint program, const GLchar* name)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        return glGetAttribLocation(program, name);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            return glGetAttribLocation(program, name);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            return glGetAttribLocation(program, name);
        }
    }
    return NES_GLOPERATION_SKIP;
}
    
void    nes_glGetBooleanv (GLenum pname, GLboolean* params)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glGetBooleanv(pname, params);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glGetBooleanv(pname, params);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glGetBooleanv(pname, params);
        }
    }
}
    
void    nes_glGetBufferParameteriv (GLenum target, GLenum pname, GLint* params)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glGetBufferParameteriv(target, pname, params);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glGetBufferParameteriv(target, pname, params);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glGetBufferParameteriv(target, pname, params);
        }
    }
}
    
GLenum  nes_glGetError (void)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        return glGetError();
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            return glGetError();
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            return glGetError();
        }
    }
    return NES_GLOPERATION_SKIP;
}
    
void    nes_glGetFloatv (GLenum pname, GLfloat* params)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glGetFloatv(pname, params);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glGetFloatv(pname, params);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glGetFloatv(pname, params);
        }
    }
}
    
void    nes_glGetFramebufferAttachmentParameteriv (GLenum target, GLenum attachment, GLenum pname, GLint* params)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
        }
    }
}
    
void    nes_glGetIntegerv (GLenum pname, GLint* params)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glGetIntegerv(pname, params);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glGetIntegerv(pname, params);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glGetIntegerv(pname, params);
        }
    }
}
    
void    nes_glGetProgramiv (GLuint program, GLenum pname, GLint* params)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glGetProgramiv(program, pname, params);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glGetProgramiv(program, pname, params);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glGetProgramiv(program, pname, params);
        }
    }
}
    
void    nes_glGetProgramInfoLog (GLuint program, GLsizei bufsize, GLsizei* length, GLchar* infolog)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glGetProgramInfoLog(program, bufsize, length, infolog);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glGetProgramInfoLog(program, bufsize, length, infolog);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glGetProgramInfoLog(program, bufsize, length, infolog);
        }
    }
}
    
void    nes_glGetRenderbufferParameteriv (GLenum target, GLenum pname, GLint* params)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glGetRenderbufferParameteriv(target, pname, params);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glGetRenderbufferParameteriv(target, pname, params);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glGetRenderbufferParameteriv(target, pname, params);
        }
    }
}
    
void    nes_glGetShaderiv (GLuint shader, GLenum pname, GLint* params)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glGetShaderiv(shader, pname, params);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glGetShaderiv(shader, pname, params);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glGetShaderiv(shader, pname, params);
        }
    }
}
    
void    nes_glGetShaderInfoLog (GLuint shader, GLsizei bufsize, GLsizei* length, GLchar* infolog)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glGetShaderInfoLog(shader, bufsize, length, infolog);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glGetShaderInfoLog(shader, bufsize, length, infolog);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glGetShaderInfoLog(shader, bufsize, length, infolog);
        }
    }
}
    
void    nes_glGetShaderPrecisionFormat (GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
        }
    }
}
    
void    nes_glGetShaderSource (GLuint shader, GLsizei bufsize, GLsizei* length, GLchar* source)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glGetShaderSource(shader, bufsize, length, source);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glGetShaderSource(shader, bufsize, length, source);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glGetShaderSource(shader, bufsize, length, source);
        }
    }
}
    
const GLubyte*  nes_glGetString (GLenum name)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        return glGetString(name);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            return glGetString(name);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            return glGetString(name);
        }
    }
    return nullptr;
}
    
void    nes_glGetTexParameterfv (GLenum target, GLenum pname, GLfloat* params)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glGetTexParameterfv(target, pname, params);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glGetTexParameterfv(target, pname, params);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glGetTexParameterfv(target, pname, params);
        }
    }
}
    
void    nes_glGetTexParameteriv (GLenum target, GLenum pname, GLint* params)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glGetTexParameteriv(target, pname, params);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glGetTexParameteriv(target, pname, params);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glGetTexParameteriv(target, pname, params);
        }
    }
}
    
void    nes_glGetUniformfv (GLuint program, GLint location, GLfloat* params)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glGetUniformfv(program, location, params);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glGetUniformfv(program, location, params);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glGetUniformfv(program, location, params);
        }
    }
}
    
void    nes_glGetUniformiv (GLuint program, GLint location, GLint* params)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glGetUniformiv(program, location, params);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glGetUniformiv(program, location, params);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glGetUniformiv(program, location, params);
        }
    }
}
    
int     nes_glGetUniformLocation (GLuint program, const GLchar* name)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        return glGetUniformLocation(program, name);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            return glGetUniformLocation(program, name);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            return glGetUniformLocation(program, name);
        }
    }
    
    return NES_GLOPERATION_SKIP;
}
    
void    nes_glGetVertexAttribfv (GLuint index, GLenum pname, GLfloat* params)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glGetVertexAttribfv(index, pname, params);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glGetVertexAttribfv(index, pname, params);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glGetVertexAttribfv(index, pname, params);
        }
    }
}
    
void    nes_glGetVertexAttribiv (GLuint index, GLenum pname, GLint* params)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glGetVertexAttribiv(index, pname, params);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glGetVertexAttribiv(index, pname, params);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glGetVertexAttribiv(index, pname, params);
        }
    }
}
    
void    nes_glGetVertexAttribPointerv (GLuint index, GLenum pname, GLvoid** pointer)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glGetVertexAttribPointerv(index, pname, pointer);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glGetVertexAttribPointerv(index, pname, pointer);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glGetVertexAttribPointerv(index, pname, pointer);
        }
    }
}
    
void    nes_glHint (GLenum target, GLenum mode)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glHint(target, mode);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glHint(target, mode);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glHint(target, mode);
        }
    }
}
    
GLboolean   nes_glIsBuffer (GLuint buffer)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        return glIsBuffer(buffer);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            return glIsBuffer(buffer);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            return glIsBuffer(buffer);
        }
    }
    return NES_GLOPERATION_SKIP;
}
    
GLboolean   nes_glIsEnabled (GLenum cap)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        return glIsEnabled(cap);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            return glIsEnabled(cap);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            return glIsEnabled(cap);
        }
    }
    return NES_GLOPERATION_SKIP;
}
    
GLboolean   nes_glIsFramebuffer (GLuint framebuffer)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        return glIsFramebuffer(framebuffer);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            return glIsFramebuffer(framebuffer);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            return glIsFramebuffer(framebuffer);
        }
    }
    return NES_GLOPERATION_SKIP;
}
    
GLboolean   nes_glIsProgram (GLuint program)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        return glIsProgram(program);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            return glIsProgram(program);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            return glIsProgram(program);
        }
    }
    return NES_GLOPERATION_SKIP;
}
    
GLboolean   nes_glIsRenderbuffer (GLuint renderbuffer)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        return glIsRenderbuffer(renderbuffer);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            return glIsRenderbuffer(renderbuffer);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            return glIsRenderbuffer(renderbuffer);
        }
    }
    return NES_GLOPERATION_SKIP;
}
    
GLboolean   nes_glIsShader (GLuint shader)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        return glIsShader(shader);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            return glIsShader(shader);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            return glIsShader(shader);
        }
    }
    return NES_GLOPERATION_SKIP;
}
    
GLboolean   nes_glIsTexture (GLuint texture)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        return glIsTexture(texture);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            return glIsTexture(texture);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            return glIsTexture(texture);
        }
    }
    return NES_GLOPERATION_SKIP;
}
    
void    nes_glLineWidth (GLfloat width)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glLineWidth(width);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glLineWidth(width);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glLineWidth(width);
        }
    }
}
    
void    nes_glLinkProgram (GLuint program)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glLinkProgram(program);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glLinkProgram(program);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glLinkProgram(program);
        }
    }
}
    
void    nes_glPixelStorei (GLenum pname, GLint param)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glPixelStorei(pname, param);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glPixelStorei(pname, param);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glPixelStorei(pname, param);
        }
    }
}
    
void    nes_glPolygonOffset (GLfloat factor, GLfloat units)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glPolygonOffset(factor, units);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glPolygonOffset(factor, units);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glPolygonOffset(factor, units);
        }
    }
}
    
void    nes_glReadPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* pixels)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glReadPixels(x, y, width, height, format, type, pixels);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glReadPixels(x, y, width, height, format, type, pixels);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glReadPixels(x, y, width, height, format, type, pixels);
        }
    }
}
    
void    nes_glReleaseShaderCompiler (void)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glReleaseShaderCompiler();
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glReleaseShaderCompiler();
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glReleaseShaderCompiler();
        }
    }
}
    
void    nes_glRenderbufferStorage (GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glRenderbufferStorage(target, internalformat, width, height);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glRenderbufferStorage(target, internalformat, width, height);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glRenderbufferStorage(target, internalformat, width, height);
        }
    }
}
    
void    nes_glSampleCoverage (GLclampf value, GLboolean invert)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glSampleCoverage(value, invert);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glSampleCoverage(value, invert);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glSampleCoverage(value, invert);
        }
    }
}
    
void    nes_glScissor (GLint x, GLint y, GLsizei width, GLsizei height)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glScissor(x, y, width, height);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glScissor(x, y, width, height);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glScissor(x, y, width, height);
        }
    }
}
    
void    nes_glShaderBinary (GLsizei n, const GLuint* shaders, GLenum binaryformat, const GLvoid* binary, GLsizei length)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glShaderBinary(n, shaders, binaryformat, binary, length);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glShaderBinary(n, shaders, binaryformat, binary, length);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glShaderBinary(n, shaders, binaryformat, binary, length);
        }
    }
}
    
void    nes_glShaderSource (GLuint shader, GLsizei count, const GLchar* const *string, const GLint* length)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glShaderSource(shader, count, string, length);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glShaderSource(shader, count, string, length);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glShaderSource(shader, count, string, length);
        }
    }
}
    
void    nes_glStencilFunc (GLenum func, GLint ref, GLuint mask)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glStencilFunc(func, ref, mask);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glStencilFunc(func, ref, mask);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glStencilFunc(func, ref, mask);
        }
    }
}
    
void    nes_glStencilFuncSeparate (GLenum face, GLenum func, GLint ref, GLuint mask)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glStencilFuncSeparate(face, func, ref, mask);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glStencilFuncSeparate(face, func, ref, mask);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glStencilFuncSeparate(face, func, ref, mask);
        }
    }
}
    
void    nes_glStencilMask (GLuint mask)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glStencilMask(mask);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glStencilMask(mask);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glStencilMask(mask);
        }
    }
}
    
void    nes_glStencilMaskSeparate (GLenum face, GLuint mask)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glStencilMaskSeparate(face, mask);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glStencilMaskSeparate(face, mask);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glStencilMaskSeparate(face, mask);
        }
    }
}
    
void    nes_glStencilOp (GLenum fail, GLenum zfail, GLenum zpass)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glStencilOp(fail, zfail, zpass);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glStencilOp(fail, zfail, zpass);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glStencilOp(fail, zfail, zpass);
        }
    }
}
    
void    nes_glStencilOpSeparate (GLenum face, GLenum fail, GLenum zfail, GLenum zpass)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glStencilOpSeparate(face, fail, zfail, zpass);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glStencilOpSeparate(face, fail, zfail, zpass);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glStencilOpSeparate(face, fail, zfail, zpass);
        }
    }
}
    
void    nes_glTexImage2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* pixels)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
        }
    }
}
    
void    nes_glTexParameterf (GLenum target, GLenum pname, GLfloat param)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glTexParameterf(target, pname, param);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glTexParameterf(target, pname, param);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glTexParameterf(target, pname, param);
        }
    }
}
    
void    nes_glTexParameterfv (GLenum target, GLenum pname, const GLfloat* params)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glTexParameterfv(target, pname, params);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glTexParameterfv(target, pname, params);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glTexParameterfv(target, pname, params);
        }
    }
}
    
void    nes_glTexParameteri (GLenum target, GLenum pname, GLint param)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glTexParameteri(target, pname, param);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glTexParameteri(target, pname, param);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glTexParameteri(target, pname, param);
        }
    }
}
    
void    nes_glTexParameteriv (GLenum target, GLenum pname, const GLint* params)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glTexParameteriv(target, pname, params);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glTexParameteriv(target, pname, params);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glTexParameteriv(target, pname, params);
        }
    }
}
    
void    nes_glTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
        }
    }
}
    
void    nes_glUniform1f (GLint location, GLfloat x)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glUniform1f(location, x);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glUniform1f(location, x);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glUniform1f(location, x);
        }
    }
}
    
void    nes_glUniform1fv (GLint location, GLsizei count, const GLfloat* v)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glUniform1fv(location, count, v);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glUniform1fv(location, count, v);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glUniform1fv(location, count, v);
        }
    }
}
    
void    nes_glUniform1i (GLint location, GLint x)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glUniform1i(location, x);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glUniform1i(location, x);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glUniform1i(location, x);
        }
    }
}
    
void    nes_glUniform1iv (GLint location, GLsizei count, const GLint* v)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glUniform1iv(location, count, v);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glUniform1iv(location, count, v);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glUniform1iv(location, count, v);
        }
    }
}
    
void    nes_glUniform2f (GLint location, GLfloat x, GLfloat y)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glUniform2f(location, x, y);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glUniform2f(location, x, y);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glUniform2f(location, x, y);
        }
    }
}
    
void    nes_glUniform2fv (GLint location, GLsizei count, const GLfloat* v)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glUniform2fv(location, count, v);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glUniform2fv(location, count, v);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glUniform2fv(location, count, v);
        }
    }
}
    
void    nes_glUniform2i (GLint location, GLint x, GLint y)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glUniform2i(location, x, y);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glUniform2i(location, x, y);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glUniform2i(location, x, y);
        }
    }
}
    
void    nes_glUniform2iv (GLint location, GLsizei count, const GLint* v)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glUniform2iv(location, count, v);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glUniform2iv(location, count, v);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glUniform2iv(location, count, v);
        }
    }
}
    
void    nes_glUniform3f (GLint location, GLfloat x, GLfloat y, GLfloat z)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glUniform3f(location, x, y, z);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glUniform3f(location, x, y, z);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glUniform3f(location, x, y, z);
        }
    }
}

void    nes_glUniform3fv (GLint location, GLsizei count, const GLfloat* v)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glUniform3fv(location, count, v);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glUniform3fv(location, count, v);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glUniform3fv(location, count, v);
        }
    }
}
    
void    nes_glUniform3i (GLint location, GLint x, GLint y, GLint z)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glUniform3i(location, x, y, z);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glUniform3i(location, x, y, z);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glUniform3i(location, x, y, z);
        }
    }
}
    
void    nes_glUniform3iv (GLint location, GLsizei count, const GLint* v)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glUniform3iv(location, count, v);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glUniform3iv(location, count, v);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glUniform3iv(location, count, v);
        }
    }
}
    
void    nes_glUniform4f (GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glUniform4f(location, x, y, z, w);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glUniform4f(location, x, y, z, w);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glUniform4f(location, x, y, z, w);
        }
    }
}
    
void    nes_glUniform4fv (GLint location, GLsizei count, const GLfloat* v)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glUniform4fv(location, count, v);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glUniform4fv(location, count, v);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glUniform4fv(location, count, v);
        }
    }
}
    
void    nes_glUniform4i (GLint location, GLint x, GLint y, GLint z, GLint w)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glUniform4i(location, x, y, z, w);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glUniform4i(location, x, y, z, w);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glUniform4i(location, x, y, z, w);
        }
    }
}
    
void    nes_glUniform4iv (GLint location, GLsizei count, const GLint* v)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glUniform4iv(location, count, v);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glUniform4iv(location, count, v);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glUniform4iv(location, count, v);
        }
    }
}
    
void    nes_glUniformMatrix2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glUniformMatrix2fv(location, count, transpose, value);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glUniformMatrix2fv(location, count, transpose, value);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glUniformMatrix2fv(location, count, transpose, value);
        }
    }
}
    
void    nes_glUniformMatrix3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glUniformMatrix3fv(location, count, transpose, value);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glUniformMatrix3fv(location, count, transpose, value);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glUniformMatrix3fv(location, count, transpose, value);
        }
    }
}
    
void    nes_glUniformMatrix4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glUniformMatrix4fv(location, count, transpose, value);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glUniformMatrix4fv(location, count, transpose, value);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glUniformMatrix4fv(location, count, transpose, value);
        }
    }
}

void    nes_glUseProgram (GLuint program)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glUseProgram(program);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glUseProgram(program);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glUseProgram(program);
        }
    }
}
    
void    nes_glValidateProgram (GLuint program)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glValidateProgram(program);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glValidateProgram(program);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glValidateProgram(program);
        }
    }
}
    
void    nes_glVertexAttrib1f (GLuint indx, GLfloat x)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glVertexAttrib1f(indx, x);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glVertexAttrib1f(indx, x);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glVertexAttrib1f(indx, x);
        }
    }
}
    
void    nes_glVertexAttrib1fv (GLuint indx, const GLfloat* values)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glVertexAttrib1fv(indx, values);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glVertexAttrib1fv(indx, values);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glVertexAttrib1fv(indx, values);
        }
    }
}
    
void    nes_glVertexAttrib2f (GLuint indx, GLfloat x, GLfloat y)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glVertexAttrib2f(indx, x, y);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glVertexAttrib2f(indx, x, y);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glVertexAttrib2f(indx, x, y);
        }
    }
}

void    nes_glVertexAttrib2fv (GLuint indx, const GLfloat* values)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glVertexAttrib2fv(indx, values);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glVertexAttrib2fv(indx, values);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glVertexAttrib2fv(indx, values);
        }
    }
}
    
void    nes_glVertexAttrib3f (GLuint indx, GLfloat x, GLfloat y, GLfloat z)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glVertexAttrib3f(indx, x, y, z);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glVertexAttrib3f(indx, x, y, z);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glVertexAttrib3f(indx, x, y, z);
        }
    }
}
    
void    nes_glVertexAttrib3fv (GLuint indx, const GLfloat* values)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glVertexAttrib3fv(indx, values);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glVertexAttrib3fv(indx, values);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glVertexAttrib3fv(indx, values);
        }
    }
}
    
void    nes_glVertexAttrib4f (GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glVertexAttrib4f(indx, x, y, z, w);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glVertexAttrib4f(indx, x, y, z, w);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glVertexAttrib4f(indx, x, y, z, w);
        }
    }
}
    
void    nes_glVertexAttrib4fv (GLuint indx, const GLfloat* values)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glVertexAttrib4fv(indx, values);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glVertexAttrib4fv(indx, values);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glVertexAttrib4fv(indx, values);
        }
    }
}

void    nes_glVertexAttribPointer (GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* ptr)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glVertexAttribPointer(indx, size, type, normalized, stride, ptr);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glVertexAttribPointer(indx, size, type, normalized, stride, ptr);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glVertexAttribPointer(indx, size, type, normalized, stride, ptr);
        }
    }
}
    
void    nes_glViewport (GLint x, GLint y, GLsizei width, GLsizei height)
{
    NESCGL::NESCGLHelper* default_cglhelper_instance = NESCGL::access_shared_helper();
    if(NESCGL::NES_GLSAFE_LEVEL_NONE==default_cglhelper_instance->glInvokeSafeLevel){
        glViewport(x, y, width, height);
    }
    else{
        if(default_cglhelper_instance->isGLStateSafe){
            glViewport(x, y, width, height);
        }
        else if(NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE==default_cglhelper_instance->glInvokeSafeLevel){
            default_cglhelper_instance->blockThread();
            glViewport(x, y, width, height);
        }
    }
}
    
#ifdef __cplusplus
    }
#endif

#endif /* NESCGL_hpp */


