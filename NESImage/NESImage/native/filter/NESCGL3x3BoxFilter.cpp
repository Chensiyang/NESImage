//
//  NESCGLBoxFilter.cpp
//  NESImage
//
//  Created by chen on 2019/2/21.
//  Copyright © 2019年 chen. All rights reserved.
//

#include "NESCGL3x3BoxFilter.hpp"

namespace NESCGL {
    
    const char* boxfilter_vertex_shader = NES_GL_SHADER
    (
     attribute vec4 position;
     attribute vec2 inputTextureCoordinate;
     
     varying vec2 textureCoordinates[3];
     
     uniform vec2 step;
     
     void main()
     {
         gl_Position = position;
         textureCoordinates[0] = inputTextureCoordinate.xy-step;
         textureCoordinates[1] = inputTextureCoordinate.xy;
         textureCoordinates[2] = inputTextureCoordinate.xy+step;
     }
     );
    
    const char* boxfilter_fragment_shader = NES_GL_SHADER
    (
     precision highp float;
     varying highp vec2 textureCoordinates[3];
     
     uniform sampler2D inputImageTexture;
     
     void main()
     {
         lowp vec4 rgb0 = texture2D(inputImageTexture, textureCoordinates[0]);
         lowp vec4 rgb1 = texture2D(inputImageTexture, textureCoordinates[1]);
         lowp vec4 rgb2 = texture2D(inputImageTexture, textureCoordinates[2]);
         gl_FragColor = (rgb0+rgb1+rgb2)/3.0;
     }
     );
    
    NESCGL3x3BoxFilter::NESCGL3x3BoxFilter():
    NESCGLFilter(box3x3filter_vertex_shader, box3x3filter_fragment_shader)
    {
        gl_blurstep_id = nes_glGetUniformLocation(program->programid, "step");
    }
    
    void NESCGL3x3BoxFilter::render(NESCGLFramebuffer* renderBuffer, NESRecti* viewport, NESCGLTexture* inputTexture)
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

