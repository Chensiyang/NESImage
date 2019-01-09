//
//  NESGLVertexBuffer.m
//  NESImage
//
//  Created by chen on 2018/8/15.
//  Copyright © 2018年 chen. All rights reserved.
//

#import "NESGLVertexBuffer.h"
#import "NESCGLVertexBuffer.hpp"

@interface NESGLVertexBuffer()
{
    
    
}

@property (assign, nonatomic) NESCGL::NESCGLVertexBuffer *cnative_vertexbuffer;

@end

extern void* NES_get_native_vertexbuffer(NESGLVertexBuffer *vertexbuffer)
{
    if(!vertexbuffer){
        return NULL;
    }
    return vertexbuffer.cnative_vertexbuffer;
}


@implementation NESGLVertexBuffer

-(void)dealloc
{
    if(_cnative_vertexbuffer){
        nes_glDeleteBuffers(1, &(_cnative_vertexbuffer->bufferid));
        delete _cnative_vertexbuffer;
    }
}

-(instancetype)initWithTarget:(uint32_t)target
{
    if(!(self = [super init])){
        return nil;
    }
    
    _target = target;
    
    [self createNativeVertexbuffer];
    
    return self;
    
}

- (void)createNativeVertexbuffer{
    
    _cnative_vertexbuffer = NESCGL::NESCGLVertexBuffer::createVertexbuffer(_target);
}


-(uint32_t)vertexbufferId
{
    if(_cnative_vertexbuffer){
        return _cnative_vertexbuffer->bufferid;
    }
    return 0;
}

@end


