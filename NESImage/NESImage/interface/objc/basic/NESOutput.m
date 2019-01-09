//
//  NESOutput.m
//  NESImage
//
//  Created by chen on 2018/9/27.
//  Copyright © 2018年 chen. All rights reserved.
//

#import "NESOutput.h"

@implementation NESOutput

-(instancetype)init
{
    if(!(self = [super init])){
        return nil;
    }
    mtargets = [[NSMutableArray alloc] init];
    mtargetsOutputIndices = [[NSMutableArray alloc] init];
    
    return self;
}

-(int)suitableTargetOutputIndex
{
    int n_index = 0;
    for(int i = 0; i < mtargetsOutputIndices.count; i++){
        int i_index = [mtargetsOutputIndices objectAtIndex:i].intValue;
        if(i_index > n_index){
            n_index = i_index;
        }
    }
    return n_index;
}

- (void)setInputTextureForTarget:(id<NESInput>)target atIndex:(NSUInteger)index
{
    [target setInputTexture:_outputTexture atIndex:index];
    
}

- (void)notifyTargetsNewRenderReady:(CMTime)time
{
    for(int i = 0; i < mtargets.count; i++){
        id<NESInput> i_t = [mtargets objectAtIndex:i];
        int i_i = [mtargetsOutputIndices objectAtIndex:i].intValue;
        [self setInputTextureForTarget:i_t atIndex:i_i];
    }
}
- (void)addOutputTarget:(id<NESInput>)target
{
    if([mtargets containsObject:target]){
        return;
    }
    
    int index_for_target = [self suitableTargetOutputIndex];
    
    [mtargets addObject:target];
    [mtargetsOutputIndices addObject:[NSNumber numberWithInt:index_for_target]];
}
- (void)addOutputTarget:(id<NESInput>)target atIndex:(NSUInteger)index
{
    if([mtargets containsObject:target]){
        return;
    }
    
    [mtargets addObject:target];
    [mtargetsOutputIndices addObject:[NSNumber numberWithUnsignedInteger:index]];
}

- (void)removeTarget:(id<NESInput>)target
{
    if(!target){
        NSLog(@"null target on method removeTarget:");
        return;
    }
    NSUInteger index_of_object = [mtargets indexOfObject:target];
    if(NSNotFound != index_of_object){
        [mtargets removeObjectAtIndex:index_of_object];
        [mtargetsOutputIndices removeObjectAtIndex:index_of_object];
    }
    else{
        NSLog(@"output target not exist");
    }
}
- (void)removeTargetAt:(NSUInteger)index
{
    if(mtargets.count > index){
        [mtargets removeObjectAtIndex:index];
        [mtargetsOutputIndices removeObjectAtIndex:index];
    }
    else{
        NSLog(@"output target index over range");
    }
}


@end


