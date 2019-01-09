//
//  NESProgram.m
//  NESImage
//
//  Created by chen on 2018/8/15.
//  Copyright © 2018年 chen. All rights reserved.
//

#import "NESGLProgram.h"
#import "NESCGLProgram.hpp"

@interface NESGLProgram()
{
    
    
}

@property (assign, nonatomic) NESCGL::NESCGLProgram *cnative_program;

@end

void* NES_get_native_program(NESGLProgram *program)
{
    if(!program){
        return NULL;
    }
    return program.cnative_program;
}

@implementation NESGLProgram

-(void)dealloc
{
    if(_cnative_program){
        nes_glDeleteProgram(_cnative_program->programid);
        delete _cnative_program;
    }
}

-(instancetype)initWithVertexShader:(const char*)vertexshader fragmentShader:(const char*)fragmentShader
{
    if(!(self = [super init])){
        return nil;
    }
    
    _cnative_program = new NESCGL::NESCGLProgram(vertexshader, fragmentShader);
    
    return self;
}
- (void)linkProgram
{
    if(_cnative_program){
        _cnative_program->linkProgram();
    }
}
- (void)useProgram
{
    if(_cnative_program){
        _cnative_program->useProgram();
    }
}

-(uint32_t)programId
{
    if(_cnative_program){
        return _cnative_program->programid;
    }
    return 0;
}

@end




