//
//  NESCGLGrayFilter.cpp
//  NESImage
//
//  Created by chen on 2019/2/24.
//  Copyright © 2019年 chen. All rights reserved.
//

#include "NESCGLGrayFilter.hpp"

namespace NESCGL {
    
    const char* gray_filter_vertex_shader = NES_GL_SHADER
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
    
    const char* gray_filter_fragment_shader = NES_GL_SHADER
    (
     precision highp float;
     varying highp vec2 textureCoordinate;
     
     uniform sampler2D inputImageTexture;
     
     const vec3 gray_weight = vec3(0.299, 0.578, 0.114);
     
     void main()
     {
         vec4 in_color = texture2D(inputImageTexture, textureCoordinate);
         vec3 gray_vec = in_color.rgb*gray_weight;
         float gray = gray_vec.r+gray_vec.g+gray_vec.b;
         gl_FragColor = vec4(vec3(gray), 1.0);
     }
     );
    
    NESCGLGrayFilter::NESCGLGrayFilter():NESCGLFilter(gray_filter_vertex_shader, gray_filter_fragment_shader)
    {
        
    }
    
    
}




