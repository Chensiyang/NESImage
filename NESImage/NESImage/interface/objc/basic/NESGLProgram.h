//
//  NESProgram.h
//  NESImage
//
//  Created by chen on 2018/8/15.
//  Copyright © 2018年 chen. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NESGLProgram;
/**
 access the native NESCGLProgram object representing the program,
 useful for further gl program control
 @param program object whose native object you want to obtain
 @return pointer to NESCGLProgram, may be NULL if the native object cant be not successfully created
 */
extern void* NES_get_native_program(NESGLProgram *program);

@interface NESGLProgram : NSObject

-(instancetype)initWithVertexShader:(const char*)vertexshader fragmentShader:(const char*)fragmentShader;


@property (assign, nonatomic) uint32_t programId;// gl program id, represent the native gl program

- (void)linkProgram;//link programid for render ready
- (void)useProgram;//active programid and set as the current render program

@end


