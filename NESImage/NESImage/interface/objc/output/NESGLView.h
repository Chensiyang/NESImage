//
//  NESGLView.h
//  NESImage
//
//  Created by chen on 2019/2/12.
//  Copyright © 2019年 chen. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <NESInput.h>
#import <NESGLTexture.h>

typedef NS_ENUM(NSUInteger, NESViewContentModel)
{
    NESViewContentModelNone = 0,
    NESViewContentModelScale = 1,
    NESViewContentModelAspect = 2,
    NESViewContentModelAspectFill = 3
    
};

@interface NESGLView : UIView <NESInput>
{
    NESImageOrientation mInputRotation;
    NESGLTexture *mInputTexture;
    
}

@property (assign, nonatomic) NESViewContentModel contentModel;



@end

