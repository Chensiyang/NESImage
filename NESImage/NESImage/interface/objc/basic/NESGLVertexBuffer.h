//
//  NESGLVertexBuffer.h
//  NESImage
//
//  Created by chen on 2018/8/15.
//  Copyright © 2018年 chen. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NESGLVertexBuffer;

/**
 access the native NESCGLVertexBuffer object representing the vertexbuffer,
 useful for further gl vertexbuffer control
 @param vertexbuffer object whose native object you want to obtain
 @return pointer to NESCGLVertexBuffer, may be NULL if the native object cant be not successfully created
 */
extern void* NES_get_native_vertexbuffer(NESGLVertexBuffer *vertexbuffer);


@interface NESGLVertexBuffer : NSObject

-(instancetype)initWithTarget:(uint32_t)target;

@property (assign, nonatomic) uint32_t target;// gl vertexbuffer target
@property (assign, nonatomic) uint32_t vertexbufferId;//gl vertexbuffer id, represent the native gl buffer


@end

