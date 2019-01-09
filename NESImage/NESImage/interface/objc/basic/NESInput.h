//
//  NESInput.h
//  NESImage
//
//  Created by chen on 2018/9/27.
//  Copyright © 2018年 chen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
#import <CoreGraphics/CoreGraphics.h>

@class NESGLTexture;
@class NESGLFramebuffer;

typedef NS_ENUM(NSUInteger, NESImageOrientation)
{
    NESImageOrientationPortrait = 0,
    
};

@protocol NESInput<NSObject>

- (void)setRenderFramebuffer:(NESGLFramebuffer*)framebuffer;
- (void)setRotation:(NESImageOrientation)rotation atIndex:(NSUInteger)index;
- (void)setInputTexture:(NESGLTexture*)texture atIndex:(NSUInteger)index;
- (void)renderFrame:(CGRect)rect atTime:(CMTime)time;

@end





