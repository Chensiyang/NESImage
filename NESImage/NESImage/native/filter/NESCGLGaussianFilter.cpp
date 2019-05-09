//
//  NESCGLGaussianFilter.cpp
//  NESImage
//
//  Created by chen on 2019/3/24.
//  Copyright © 2019年 chen. All rights reserved.
//

#include "NESCGLGaussianFilter.hpp"


namespace NESCGL {
    
    const char* gaussian_filter_vertex_shader = NES_GL_SHADER
    (
    
     attribute vec4 position;
     attribute vec4 inputTextureCoordinate;
     
     uniform float texelWidthOffset;
     uniform float texelHeightOffset;
     
     varying vec2 blurCoordinates[13];
     
     void main()
     {
         gl_Position = position;
         
         vec2 singleStepOffset = vec2(texelWidthOffset, texelHeightOffset);
         blurCoordinates[0] = inputTextureCoordinate.xy;
         blurCoordinates[1] = inputTextureCoordinate.xy + singleStepOffset * 1.485004;
         blurCoordinates[2] = inputTextureCoordinate.xy - singleStepOffset * 1.485004;
         blurCoordinates[3] = inputTextureCoordinate.xy + singleStepOffset * 3.465057;
         blurCoordinates[4] = inputTextureCoordinate.xy - singleStepOffset * 3.465057;
         blurCoordinates[5] = inputTextureCoordinate.xy + singleStepOffset * 5.445220;
         blurCoordinates[6] = inputTextureCoordinate.xy - singleStepOffset * 5.445220;
         blurCoordinates[7] = inputTextureCoordinate.xy + singleStepOffset * 7.425558;
         blurCoordinates[8] = inputTextureCoordinate.xy - singleStepOffset * 7.425558;
         blurCoordinates[9] = inputTextureCoordinate.xy + singleStepOffset * 9.406127;
         blurCoordinates[10] = inputTextureCoordinate.xy - singleStepOffset * 9.406127;
         blurCoordinates[11] = inputTextureCoordinate.xy + singleStepOffset * 11.386986;
         blurCoordinates[12] = inputTextureCoordinate.xy - singleStepOffset * 11.386986;
     }
    
    );
    const char* gaussian_filter_fragment_shader = NES_GL_SHADER
    (
     uniform sampler2D inputImageTexture;
     uniform highp float texelWidthOffset;
     uniform highp float texelHeightOffset;
     
     varying highp vec2 blurCoordinates[13];
     
     void main()
     {
         lowp vec4 sum = vec4(0.0);
         sum += texture2D(inputImageTexture, blurCoordinates[0]) * 0.080780;
         sum += texture2D(inputImageTexture, blurCoordinates[1]) * 0.153750;
         sum += texture2D(inputImageTexture, blurCoordinates[2]) * 0.153750;
         sum += texture2D(inputImageTexture, blurCoordinates[3]) * 0.126131;
         sum += texture2D(inputImageTexture, blurCoordinates[4]) * 0.126131;
         sum += texture2D(inputImageTexture, blurCoordinates[5]) * 0.088315;
         sum += texture2D(inputImageTexture, blurCoordinates[6]) * 0.088315;
         sum += texture2D(inputImageTexture, blurCoordinates[7]) * 0.052777;
         sum += texture2D(inputImageTexture, blurCoordinates[8]) * 0.052777;
         sum += texture2D(inputImageTexture, blurCoordinates[9]) * 0.026919;
         sum += texture2D(inputImageTexture, blurCoordinates[10]) * 0.026919;
         sum += texture2D(inputImageTexture, blurCoordinates[11]) * 0.011718;
         sum += texture2D(inputImageTexture, blurCoordinates[12]) * 0.011718;
         gl_FragColor = sum;
     }
    
    );
    
    
    
    NESCGLGaussianFilter::NESCGLGaussianFilter():NESCGL::NESCGLFilter(gaussian_filter_vertex_shader,
                                                                      gaussian_filter_fragment_shader)
    {
        
        glid_width_step_u = nes_glGetUniformLocation(program->programid, "texelWidthOffset");
        glid_height_step_u = nes_glGetUniformLocation(program->programid, "texelHeightOffset");
        
    }
    
    void NESCGLGaussianFilter::update_vertical_texture(NESCGLTexture* t)
    {
        mVertialTexture = t;
    }
    
    int NESCGLGaussianFilter::render(NESCGLFramebuffer* renderBuffer, NESRecti* viewport,
                                     NESCGLTexture* inputTexture)
    {
        if(!inputTexture){
            return NES_PARAMS_ILLEGAL;
        }
        
        NESCGLTexture* output_texture = renderBuffer->access_colorattatchMent_0();
        
//        nes_glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
        nes_glVertexAttribPointer(glid_vertex, 2, GL_FLOAT, 0, 0, NESCGL::default_vertices);
        
//        nes_glBindBuffer(GL_ARRAY_BUFFER, coordinate_buffer);
        nes_glVertexAttribPointer(glid_tex_coordinate, 2, GL_FLOAT, 0, 0, NESCGL::default_tex_coordinates);
        
        renderBuffer->framebufferAttatchColorTexture(mVertialTexture);
        NESRecti rect = (NESRecti){0, 0, mVertialTexture->size.x, mVertialTexture->size.y};
        renderBuffer->bindtoFramebufferViewPort(&rect);
        nes_glClear(GL_COLOR_BUFFER_BIT);
        
        nes_glUseProgram(program->programid);
        
        nes_glActiveTexture(GL_TEXTURE1);
        nes_glBindTexture(GL_TEXTURE_2D, inputTexture->textureid);
        nes_glUniform1i(glid_input_texture, 1);
        nes_glUniform1f(glid_width_step_u, 0.0);
        nes_glUniform1f(glid_height_step_u, 0.000781250012);
        nes_glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        renderBuffer->framebufferAttatchColorTexture(output_texture);
        renderBuffer->bindtoFramebufferViewPort(viewport);
        nes_glClear(GL_COLOR_BUFFER_BIT);
        
        nes_glActiveTexture(GL_TEXTURE2);
        nes_glBindTexture(GL_TEXTURE_2D, mVertialTexture->textureid);
        nes_glUniform1i(glid_input_texture, 2);
        nes_glUniform1f(glid_width_step_u, 0.00138888892);
        nes_glUniform1f(glid_height_step_u, 0.0);
        nes_glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        
//        nes_glBindBuffer(GL_ARRAY_BUFFER, 0);
        
        return NES_NO_ERROR;
    }
    
    
}



