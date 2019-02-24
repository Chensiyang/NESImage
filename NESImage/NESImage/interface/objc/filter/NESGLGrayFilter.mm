//
//  NESGLGrayFilter.m
//  NESImage
//
//  Created by chen on 2019/2/24.
//  Copyright © 2019年 chen. All rights reserved.
//

#import "NESGLGrayFilter.h"
#include "NESCGLGrayFilter.hpp"

@implementation NESGLGrayFilter

-(instancetype)init
{
    if(!(self = [super initWithVertexShader:NESCGL::gray_filter_vertex_shader fragmentShader:NESCGL::gray_filter_fragment_shader])){
        return nil;
    }
    return self;
}


@end






