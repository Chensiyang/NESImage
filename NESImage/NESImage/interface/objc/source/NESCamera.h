//
//  NESCamera.h
//  NESImage
//
//  Created by chen on 2019/2/13.
//  Copyright © 2019年 chen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <NESOutput.h>
#import <NESGLFramebuffer.h>

@protocol NESCameraDelegate <NSObject>

@optional
- (void)captureOutput:(AVCaptureOutput *)output didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer fromConnection:(AVCaptureConnection *)connection;

@end

@interface NESCamera : NESOutput
{
    AVCaptureDevice* select_device;
    
    NESGLFramebuffer *mRenderFramebuffer;
}

@property(strong, nonatomic, readonly) AVCaptureSession* mSession;
@property(strong, nonatomic, readonly) AVCaptureDeviceInput* mVideoInput;
@property(strong, nonatomic, readonly) AVCaptureVideoDataOutput* mVideoOutput;

@property(strong, nonatomic, readonly) AVCaptureSessionPreset mCameraPreset;
@property(nonatomic, readonly) AVCaptureDevicePosition mCameraPostion;

@property (weak, nonatomic) id<NESCameraDelegate> sampleDelegate;

-(instancetype)initWithPreset:(AVCaptureSessionPreset)preset camera:(AVCaptureDevicePosition)camera;

-(void)startRunning;
-(void)stopRunning;

-(void)switchCamera;


@end



