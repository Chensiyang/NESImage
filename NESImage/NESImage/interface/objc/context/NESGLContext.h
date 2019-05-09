//
//  NESGLContext.h
//  NESImage
//
//  Created by chen on 2018/8/19.
//  Copyright © 2018年 chen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreVideo/CoreVideo.h>
#import <UIKit/UIKit.h>
#include <OpenGLES/EAGL.h>
#include <OpenGLES/ES2/gl.h>

@interface NESGLContext : NSObject

+ (NESGLContext *)sharedContext;
+ (BOOL)supportsSharedMemoryTexture;
+ (GLint)maxTextureSizeForCurrentDevice;

- (EAGLContext *)context;
- (void)activeAsCurrentContext;


@end




