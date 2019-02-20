//
//  NESGLTexturePool.h
//  NESImage
//
//  Created by chen on 2018/8/19.
//  Copyright © 2018年 chen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreVideo/CoreVideo.h>
#import <NESGLContext.h>
#import <NESGLTexture.h>

@interface NESGLTexturePool : NSObject
{
    NSMutableDictionary<NSString*, NSMutableArray<NESGLTexture*>*> *texture_pool;
    
}

+ (NESGLTexturePool *)sharedTexturePool;

- (instancetype)initWithESGLContext:(NESGLContext *)context;

@property (strong, nonatomic) NESGLContext *glcontext;
@property (assign, nonatomic) CVOpenGLESTextureCacheRef textureCacheRef;//only available for ios5.0 above


- (NESGLTexture*)fetchTextureFromPool:(uint32_t)width
                               height:(uint32_t)height;
- (NESGLTexture*)fetchTextureFromPool:(uint32_t)width
                               height:(uint32_t)height
                              options:(NESGLTextureOptions)options;


@end


