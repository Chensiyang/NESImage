//
//  NESCGLGrayFilter.hpp
//  NESImage
//
//  Created by chen on 2019/2/24.
//  Copyright © 2019年 chen. All rights reserved.
//

#ifndef NESCGLGrayFilter_hpp
#define NESCGLGrayFilter_hpp

#include <stdio.h>
#include "NESCGLFilter.hpp"

namespace NESCGL {
    
    extern const char* gray_filter_vertex_shader;
    extern const char* gray_filter_fragment_shader;
    
    //apply 3x3 boxfilter
    class NESCGLGrayFilter : public NESCGLFilter {
        
    public:
        NESCGLGrayFilter(void);
        
    };
}

#endif /* NESCGLGrayFilter_hpp */
