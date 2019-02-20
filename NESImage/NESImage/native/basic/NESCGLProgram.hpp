//
//  NESCGLProgram.hpp
//  NESImage
//
//  Created by chen on 2018/7/31.
//  Copyright © 2018年 chen. All rights reserved.
//

#ifndef NESCGLProgram_hpp
#define NESCGLProgram_hpp

#include <stdio.h>
#include <string>
#include "NESCGLTypes.hpp"
#include "NESCGL.hpp"

namespace NESCGL {
    
class NESCGLProgram{

public:
    NESCGLProgram(void);
    NESCGLProgram(const NESchar* ver, const NESchar* fra);//vertex shader fragment shader
    virtual ~NESCGLProgram(void);
    
public:
    bool native_malloc = false;
    NESuint programid;// gl program id, represent the native gl program
    
public:
    void linkProgram(void); //link programid for render ready
    void useProgram(void);//active programid and set as the current render program
    
private:
    NESuint v_shader;
    NESuint f_shader;
    std::string vertexshaderLog;
    std::string fragmentshaderLog;
    
};
    
inline NESCGLProgram::NESCGLProgram()
{
    programid = 0;
}

inline bool compileshader(NESuint* shader, NESenum type, const NESchar* shaderstr, std::string& shaderlog){
    if(shader && shaderstr && (GL_VERTEX_SHADER == type||GL_FRAGMENT_SHADER == type)){
        *shader = nes_glCreateShader(type);
        
        nes_glShaderSource(*shader, 1, &shaderstr, NULL);
        nes_glCompileShader(*shader);
        
        NESint status;
        nes_glGetShaderiv(*shader, GL_COMPILE_STATUS, &status);
        
        if (status != GL_TRUE)
        {
            NESint infoLength = 0;
            nes_glGetShaderiv(*shader, GL_INFO_LOG_LENGTH, &infoLength);
            if(infoLength > 0){
                NESchar *infoLog = (NESchar*)calloc(infoLength, sizeof(NESchar));
                NESint loglength = 0;
                nes_glGetShaderInfoLog(*shader, infoLength, &loglength, infoLog);
                
                shaderlog = std::string(infoLog);
                
                free(infoLog);
            }
            
            return false;
        }
        
        return true;
    }
    
    return false;
}
    
inline NESCGLProgram::NESCGLProgram(const NESchar* ver,const  NESchar* fra)
{
    if(ver && fra){
        
        bool ver_state = compileshader(&v_shader, GL_VERTEX_SHADER, ver, vertexshaderLog);
        if(!ver_state){
            printf("error:%s\n", vertexshaderLog.c_str());
        }
        bool fra_state = compileshader(&f_shader, GL_FRAGMENT_SHADER, fra, fragmentshaderLog);
        if(!fra_state){
            printf("error:%s\n", fragmentshaderLog.c_str());
        }
        
        if(ver_state && fra_state){
            programid = nes_glCreateProgram();
            if(0 >= programid){
                printf("error occur on nes_glCreateProgram()\n");
                assert(false);
            }
            
            nes_glAttachShader(programid, v_shader);
            nes_glAttachShader(programid, f_shader);
            
        }
        
    }
    else{
        if(!ver){
            printf("error:vertex shader null, on NESCGLProgram()\n");
        }
        if(!fra){
            printf("error:fragment shader null, on NESCGLProgram()\n");
        }
    }
    
    native_malloc = true;
}
    
inline NESCGLProgram::~NESCGLProgram(void)
{
    if(native_malloc){
        if(0 < programid){
            nes_glDeleteProgram(programid);
        }
    }
    
}
    
inline void NESCGLProgram::linkProgram(void)
{
    GLint state;
    nes_glLinkProgram(programid);
    
    nes_glGetProgramiv(programid, GL_LINK_STATUS, &state);
    if (state == GL_FALSE){
        NESint infoLength;
        nes_glGetProgramiv(programid, GL_INFO_LOG_LENGTH, &infoLength);
    
        if(infoLength > 0){
            NESchar *infoLog = (NESchar*)calloc(infoLength, sizeof(NESchar));
            NESint loglength = 0;
            nes_glGetProgramInfoLog(programid, infoLength, &loglength, infoLog);
            
            printf("error:%s\n", infoLog);
            free(infoLog);
            assert(false);
        }
    }
    //auto delete shader object
    if(v_shader){
        nes_glDeleteShader(v_shader);
        v_shader = 0;
    }
    if(f_shader){
        nes_glDeleteShader(f_shader);
        f_shader = 0;
    }
}
    
inline void NESCGLProgram::useProgram(void)
{
    nes_glUseProgram(programid);
}
    
    
    
    
}//end NESCGL


#endif /* NESCGLProgram_hpp */
