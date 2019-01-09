//
//  NESGLTexturePool.m
//  NESImage
//
//  Created by chen on 2018/8/19.
//  Copyright © 2018年 chen. All rights reserved.
//

#import "NESGLTexturePool.h"

@implementation NESGLTexturePool

+ (NESGLTexturePool*)sharedTexturePool
{
    static NESGLTexturePool *texture_pool = nil;
    static dispatch_once_t onceToken;
    if(!texture_pool)
    {
        dispatch_once(&onceToken, ^{
            if(!texture_pool)
            {
                texture_pool = [[NESGLTexturePool alloc] initWithESGLContext:
                                [NESGLContext sharedContext]];
            }
        });
    }
    return texture_pool;
}

-(instancetype)initWithESGLContext:(NESGLContext *)context
{
    if(!(self = [super init])){
        return nil;
    }
    
    _glcontext = context;
    
    if([NESGLContext supportsSharedMemoryTexture]){
        
        [self createSharedTextureCacheRef];
    }
    
    texture_pool = [[NSMutableDictionary alloc] init];
    
    return self;
}

- (CVOpenGLESTextureCacheRef)createSharedTextureCacheRef;
{
    if (NULL == _textureCacheRef)
    {
#if defined(__IPHONE_6_0)
        CVReturn err = CVOpenGLESTextureCacheCreate(kCFAllocatorDefault,
                                                    NULL,
                                                    [_glcontext context],
                                                    NULL,
                                                    &_textureCacheRef);
#else
        CVReturn err = CVOpenGLESTextureCacheCreate(kCFAllocatorDefault,
                                                    NULL,
                                                    (__bridge void *)[_glcontext context],
                                                    NULL,
                                                    &_textureCacheRef);
#endif
        
        if (err)
        {
            NSAssert(NO, @"Error occur CVOpenGLESTextureCacheCreate %d", err);
        }
    }
    
    return _textureCacheRef;
}

- (NESGLTexture*)fetchTextureFromPool:(uint32_t)width
                               height:(uint32_t)height
                              options:(NESGLTextureOptions)options
{
    NSString *size_key = [NSString stringWithFormat:@"%d-%d %d-%d %d-%d",
                          height, width,
                          options.wrap_s, options.wrap_t,
                          options.min_filter, options.mag_filter];
    NSMutableArray<NESGLTexture*>* fetch_list = [texture_pool objectForKey:size_key];
    if(nil == fetch_list){
        fetch_list = [[NSMutableArray alloc] init];
        [texture_pool setObject:fetch_list forKey:size_key];
    }
    
    [_glcontext activeAsCurrentContext];
    
    NESGLTexture *out_texture = nil;
    if(0 < fetch_list.count){
        int exist_size = (int)fetch_list.count;
        for(int i = 0; i < exist_size; i++){
            NESGLTexture *i_texture = [fetch_list objectAtIndex:i];
            if(0 == [i_texture getRefrenceCount]){
                out_texture = i_texture;
                [out_texture textureRetain];
                break;
            }
        }
        if(nil == out_texture){
            NESGLTexture *create_texture = [[NESGLTexture alloc]
                                            initWithImageSize:CGSizeMake(width, height)];
            [create_texture textureRetain];
            [fetch_list addObject:create_texture];
            
            out_texture = create_texture;
        }
    }
    else{
        NESGLTexture *create_texture = [[NESGLTexture alloc]
                                        initWithImageSize:CGSizeMake(width, height)];
        [create_texture textureRetain];
        [fetch_list addObject:create_texture];
        
        out_texture = create_texture;
    }
    
    return out_texture;
}



@end


