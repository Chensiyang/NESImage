//
//  NESCGLGaussianFilter.hpp
//  NESImage
//
//  Created by chen on 2019/3/24.
//  Copyright © 2019年 chen. All rights reserved.
//

#ifndef NESCGLGaussianFilter_hpp
#define NESCGLGaussianFilter_hpp

#include <stdio.h>
#include "NESCGLFilter.hpp"

namespace NESCGL {
    
    extern const char* gaussian_filter_vertex_shader;
    extern const char* gaussian_filter_fragment_shader;
    
    class NESCGLGaussianFilter : public NESCGLFilter {
        
    public:
        NESCGLGaussianFilter(void);
    
    protected:
        NESCGLTexture* mVertialTexture=NULL;
        NESint glid_width_step_u;
        NESint glid_height_step_u;
    
    public:
        virtual int render(NESCGLFramebuffer* renderBuffer, NESRecti* viewport, NESCGLTexture* inputTexture);
        
        void update_vertical_texture(NESCGLTexture* t);
        
    };

}

#endif /* NESCGLGaussianFilter_hpp */


