//
//  NESGLContext.m
//  NESImage
//
//  Created by chen on 2018/8/19.
//  Copyright © 2018年 chen. All rights reserved.
//

#import "NESGLContext.h"
#import "NESCGLHelper.hpp"

@interface NESGLContext ()
{
    
    EAGLContext *gl_context;
}

@end

@implementation NESGLContext

+(void)load
{
    NESGLContext* shared_context = [NESGLContext sharedContext];
}

+ (NESGLContext *)sharedContext
{
    static NESGLContext *nesgl_context = nil;
    static dispatch_once_t onceToken;
    if(!nesgl_context)
    {
        dispatch_once(&onceToken, ^{
            if(!nesgl_context)
            {
                nesgl_context = [[NESGLContext alloc] init];
            }
            
            [NESGLContext configureNativeGLHelper];
        });
    }
    
    return nesgl_context;
}

+ (void)configureNativeGLHelper
{
    NESCGL::NESCGLHelper* shared_heloper = NESCGL::access_shared_helper();
    shared_heloper->isGLStateSafe = true;
    shared_heloper->glInvokeSafeLevel = NESCGL::NES_GLSAFE_LEVEL_BLOCKANDWAITE;
}

+(BOOL)supportsSharedMemoryTexture
{
#if TARGET_IPHONE_SIMULATOR
    return NO;
#else
    
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-pointer-compare"
    return (CVOpenGLESTextureCacheCreate != NULL);
#pragma clang diagnostic pop
    
#endif
    
}

-(instancetype)init
{
    if(!(self = [super init])){
        return nil;
    }
    
    [self createGLContext];
    [self commonInit];
    [self applicationActiveObserverInit];
    
    return self;
}

- (void)createGLContext
{
    gl_context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
    NSAssert(nil!=gl_context, @"can not successfully create OpenGL ES 2.0 context");
}

- (void)commonInit
{
    [self activeAsCurrentContext];
    glDisable(GL_DEPTH_TEST);
}

- (void)applicationActiveObserverInit
{
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(applicationWillResignActive:)
                                                 name:UIApplicationWillResignActiveNotification
                                               object:nil];//进入后台
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(applicationDidBecomeActive:)
                                                 name:UIApplicationDidBecomeActiveNotification
                                               object:nil];//退出后台
    
}

- (void)applicationWillResignActive:(NSNotification*)obj
{
    NESCGL::NESCGLHelper* shared_heloper = NESCGL::access_shared_helper();
    shared_heloper->isGLStateSafe = false;
    
    glFlush();
    
}
- (void)applicationDidBecomeActive:(NSNotification*)obj
{
    NESCGL::NESCGLHelper* shared_heloper = NESCGL::access_shared_helper();
    shared_heloper->isGLStateSafe = true;
    shared_heloper->try_wakeup_thread();
    
}

- (EAGLContext *)context
{
    return gl_context;
}

- (void)activeAsCurrentContext
{
    if([EAGLContext currentContext]!=gl_context){
        [EAGLContext setCurrentContext:gl_context];
    }
}

+ (GLint)maxTextureSizeForCurrentDevice;
{
    static dispatch_once_t onceToken;
    static GLint maxTextureSize = 0;
    
    dispatch_once(&onceToken, ^{
        [[NESGLContext sharedContext] activeAsCurrentContext];
        glGetIntegerv(GL_MAX_TEXTURE_SIZE, &maxTextureSize);
    });
    
    return maxTextureSize;
}


@end


