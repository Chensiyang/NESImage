//
//  NESCGLVertexBuffer.hpp
//  NESImage
//
//  Created by chen on 2018/8/7.
//  Copyright © 2018年 chen. All rights reserved.
//

#ifndef NESCGLVertexBuffer_hpp
#define NESCGLVertexBuffer_hpp

#include <stdio.h>
#include "NESCGLTypes.hpp"
#include "NESCGL.hpp"

namespace NESCGL {

class NESCGLVertexBuffer{
    
public:
    NESCGLVertexBuffer(void);
    NESCGLVertexBuffer(NESuint id, NESuint target);
    ~NESCGLVertexBuffer(void);
    
public:
    NESuint bufferid;   // gl vertexbuffer id, represent the native gl buffer
    NESuint buffertarget; // gl vertexbuffer target
    
    void bindToVertexBuffer(void);  //bind the bufferid to target for use
    
    static NESCGLVertexBuffer* createVertexbuffer(NESuint target){
        NESuint vertexbuffers;
        nes_glGenBuffers(1, &vertexbuffers);
        NESCGLVertexBuffer *output_vertexbuffer = new NESCGLVertexBuffer(vertexbuffers, target);
        return output_vertexbuffer;
    }
    
};
    
inline NESCGLVertexBuffer::NESCGLVertexBuffer(void)
{
    bufferid = 0;
    buffertarget = 0;
}
inline NESCGLVertexBuffer::NESCGLVertexBuffer(NESuint id, NESuint target)
{
    bufferid = id;
    buffertarget = target;
}
inline void NESCGLVertexBuffer::bindToVertexBuffer(void)
{
    nes_glBindBuffer(buffertarget, bufferid);
}
    
    
}//end NESCGL

#endif /* NESCGLVertexBuffer_hpp */



