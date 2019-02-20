//
//  NESCGLFilter.cpp
//  NESImage
//
//  Created by chen on 2018/12/24.
//  Copyright © 2018年 chen. All rights reserved.
//

#include "NESCGLFilter.hpp"

namespace NESCGL {
    
    const char* default_glprogram_vertex_shader = NES_GL_SHADER
    (
        attribute vec4 position;
        attribute vec2 inputTextureCoordinate;
     
        varying vec2 textureCoordinate;
     
         void main()
         {
             gl_Position = position;
             textureCoordinate = inputTextureCoordinate.xy;
         }
     );
    
    const char* default_glprogram_fragment_shader = NES_GL_SHADER
    (
        precision highp float;
        varying highp vec2 textureCoordinate;
     
        uniform sampler2D inputImageTexture;
     
        void main()
        {
            gl_FragColor = texture2D(inputImageTexture, textureCoordinate);
        }
     );
    
    NESCGLFilter::NESCGLFilter(void){
        
    }
    NESCGLFilter::NESCGLFilter(const NESchar* ver, const NESchar* fra)
    {
        create_program(ver, fra);
        program->linkProgram();
        create_gl_buffer();
        
        gl_vertex_id = nes_glGetAttribLocation(program->programid, "position");
        gl_tex_coordinate_id = nes_glGetAttribLocation(program->programid, "inputTextureCoordinate");
        gl_input_texture_id = nes_glGetUniformLocation(program->programid, "inputImageTexture");
        
        nes_glEnableVertexAttribArray(gl_vertex_id);
        nes_glEnableVertexAttribArray(gl_tex_coordinate_id);
        
    }
    
    NESCGLFilter::~NESCGLFilter(void)
    {
        delete_program();
        delete_gl_buffer();
    }
    
    void NESCGLFilter::create_program(const NESchar *ver, const NESchar *fra)
    {
        program = new NESCGLProgram(ver, fra);

        if(!program){
            printf("can not success create NESCGLProgram on NESCGLFilter(*,*)\n");
            assert(0);
        }
    }
    void NESCGLFilter::create_gl_buffer()
    {
        nes_glGenBuffers(1, &vertex_buffer);
        if(!vertex_buffer){
            printf("error on create vertex buffer on NESCGLFilter::create_gl_buffer()\n");
            assert(0);
        }
        nes_glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
        nes_glBufferData(GL_ARRAY_BUFFER, sizeof(default_vertices)*sizeof(default_vertices[0]),
                         default_vertices, GL_STATIC_DRAW);
        nes_glGenBuffers(1, &coordinate_buffer);
        nes_glBindBuffer(GL_ARRAY_BUFFER, coordinate_buffer);
        nes_glBufferData(GL_ARRAY_BUFFER, sizeof(default_tex_coordinates)*sizeof(default_tex_coordinates[0]),
                         default_tex_coordinates, GL_STATIC_DRAW);
        
        nes_glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
    void NESCGLFilter::delete_program()
    {
        if(program){
            delete program;
        }
    }
    void NESCGLFilter::delete_gl_buffer()
    {
        if(vertex_buffer){
            nes_glDeleteBuffers(1, &vertex_buffer);
        }
        if(coordinate_buffer){
            nes_glDeleteBuffers(1, &coordinate_buffer);
        }
    }
    
    void NESCGLFilter::render(NESCGLFramebuffer* renderBuffer, NESRecti* viewport, NESCGLTexture* inputTexture)
    {
        renderBuffer->bindtoFramebufferViewPort(viewport);
        nes_glClear(GL_COLOR_BUFFER_BIT);
        
        nes_glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
        nes_glVertexAttribPointer(gl_vertex_id, 2, GL_FLOAT, 0, 0, (void*)0);
        
        nes_glBindBuffer(GL_ARRAY_BUFFER, coordinate_buffer);
        nes_glVertexAttribPointer(gl_tex_coordinate_id, 2, GL_FLOAT, 0, 0, (void*)0);
        
        program->useProgram();
        
        nes_glActiveTexture(GL_TEXTURE1);
        nes_glBindTexture(GL_TEXTURE_2D, inputTexture->textureid);
        nes_glUniform1i(gl_input_texture_id, 1);
        
        nes_glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        
        nes_glBindBuffer(GL_ARRAY_BUFFER, 0);
        
    }

}


