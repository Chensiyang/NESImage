//
//  NESCGLBoxFilter.hpp
//  NESImage
//
//  Created by chen on 2019/2/21.
//  Copyright © 2019年 chen. All rights reserved.
//

#ifndef NESCGLBoxFilter_hpp
#define NESCGLBoxFilter_hpp

#include <stdio.h>
#include "NESCGLFilter.hpp"

namespace NESCGL {
    
    extern const char* box3x3filter_vertex_shader;
    extern const char* box3x3filter_fragment_shader;
    
    //apply 3x3 boxfilter
    class NESCGL3x3BoxFilter : public NESCGLFilter {
        
    public:
        NESCGL3x3BoxFilter(void);
        virtual ~NESCGL3x3BoxFilter(void);
        
        NESint gl_blurstep_id;
        
        virtual void render(NESCGLFramebuffer* renderBuffer, NESRecti* viewport, NESCGLTexture* inputTexture);
        
        
    };
    
}


#endif /* NESCGLBoxFilter_hpp */
