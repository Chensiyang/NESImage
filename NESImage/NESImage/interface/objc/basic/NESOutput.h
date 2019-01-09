//
//  NESOutput.h
//  NESImage
//
//  Created by chen on 2018/9/27.
//  Copyright © 2018年 chen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
#import "NESGLTexture.h"
#import "NESInput.h"

@interface NESOutput : NSObject
{
    NSMutableArray<id<NESInput>> *mtargets;
    NSMutableArray<NSNumber*> *mtargetsOutputIndices;
    
}

- (void)setInputTextureForTarget:(id<NESInput>)target atIndex:(NSUInteger)index;
- (void)notifyTargetsNewRenderReady:(CMTime)time;
//can not add object for output target more than noce
- (void)addOutputTarget:(id<NESInput>)target;
- (void)addOutputTarget:(id<NESInput>)target atIndex:(NSUInteger)index;
- (void)removeTarget:(id<NESInput>)target;
- (void)removeTargetAt:(NSUInteger)index;


@property (strong, nonatomic) NESGLTexture* outputTexture;


@end


