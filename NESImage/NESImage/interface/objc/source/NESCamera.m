//
//  NESCamera.m
//  NESImage
//
//  Created by chen on 2019/2/13.
//  Copyright © 2019年 chen. All rights reserved.
//

#import "NESCamera.h"
#import "NESGLContext.h"

@interface NESCamera()<AVCaptureVideoDataOutputSampleBufferDelegate>
{
    
    
}

@end

@implementation NESCamera

-(instancetype)init
{
    return [self initWithPreset:AVCaptureSessionPresetPhoto camera:AVCaptureDevicePositionFront];
}

-(instancetype)initWithPreset:(AVCaptureSessionPreset)preset camera:(AVCaptureDevicePosition)camera
{
    if(!(self = [super init])){
        return nil;
    }
    
    _mCameraPreset = preset;
    _mCameraPostion = camera;
    
    _mSession = [[AVCaptureSession alloc] init];
    [_mSession beginConfiguration];
    if([_mSession canSetSessionPreset:preset]){
        [_mSession setSessionPreset:preset];
    }
    else{
        NSAssert(NO, @"can not create AVCaptureSession with preset:%@", preset);
        return nil;
    }
    
    select_device = nil;
    NSArray<AVCaptureDevice *> *candicate_devices = [AVCaptureDevice devicesWithMediaType:AVMediaTypeVideo];
    
    for(int i = 0; i < candicate_devices.count; i++){
        AVCaptureDevice* td = [candicate_devices objectAtIndex:i];
        if([td supportsAVCaptureSessionPreset:preset]&&(td.position==camera)){
            select_device = td;
        }
    }
    if(!select_device){
        NSAssert(NO, @"can not create AVCaptureDevice with preset:%@", preset);
        return nil;
    }
    
    NSError* error=nil;
    _mVideoInput = [AVCaptureDeviceInput deviceInputWithDevice:select_device error:&error];
    if(error){
        NSAssert(NO, @"can not create AVCaptureDeviceInput with device:%@", select_device);
        return nil;
    }
    
    if(![_mSession canAddInput:_mVideoInput]){
        NSAssert(NO, @"can not add AVCaptureDevice:%@", _mVideoInput);
        return nil;
    }
    [_mSession addInput:_mVideoInput];
    
    _mVideoOutput = [[AVCaptureVideoDataOutput alloc] init];
    _mVideoOutput.alwaysDiscardsLateVideoFrames = NO;
    [_mVideoOutput setVideoSettings:@{((__bridge_transfer NSString*)kCVPixelBufferPixelFormatTypeKey):
                                         @(kCVPixelFormatType_32BGRA)}];
    AVCaptureConnection* video_connection = [_mVideoOutput connectionWithMediaType:AVMediaTypeVideo];
    if([video_connection isVideoOrientationSupported]){
        [video_connection setVideoOrientation:AVCaptureVideoOrientationPortrait];
    }
    if([video_connection isVideoMirroringSupported]){
        [video_connection setVideoMirrored:YES];
    }
    dispatch_queue_t camera_sample_queue = dispatch_queue_create("com.nes.camera.samplequeue", NULL);
    [_mVideoOutput setSampleBufferDelegate:self queue:camera_sample_queue];
    
    if(![_mSession canAddOutput:_mVideoOutput]){
        NSAssert(NO, @"can not add AVCaptureVideoDataOutput:%@", _mVideoOutput);
        return nil;
    }
    [_mSession addOutput:_mVideoOutput];
    
    [_mSession commitConfiguration];
    
    
    return self;
}

- (void)createRenderBuffer
{
    mRenderFramebuffer = [[NESGLFramebuffer alloc] init];
}

- (void)startRunning
{
    if(![_mSession isRunning]){
        [_mSession startRunning];
    }
}
- (void)stopRunning
{
    if([_mSession isRunning]){
        [_mSession stopRunning];
    }
}

- (void)switchCamera
{
    switch (_mCameraPostion) {
        case AVCaptureDevicePositionBack:
        {
            [self switchToCameraPositon:AVCaptureDevicePositionFront];
        }
            break;
        case AVCaptureDevicePositionFront:
        {
            [self switchToCameraPositon:AVCaptureDevicePositionBack];
        }
            break;
        default:
            break;
    }
}

- (void)switchToCameraPositon:(AVCaptureDevicePosition)positioin
{
    if(AVCaptureDevicePositionUnspecified == positioin){
        NSAssert(NO, @"can not open capture device on positon:%ld", (long)positioin);
    }
    
    [_mSession stopRunning];
    
    [_mSession beginConfiguration];
    [_mSession removeInput:_mVideoInput];
    
    select_device = nil;
    NSArray<AVCaptureDevice *> *candicate_devices = [AVCaptureDevice devicesWithMediaType:AVMediaTypeVideo];
    for(int i = 0; i < candicate_devices.count; i++){
        AVCaptureDevice* td = [candicate_devices objectAtIndex:i];
        if([td supportsAVCaptureSessionPreset:_mCameraPreset]&&(td.position==positioin)){
            select_device = td;
        }
    }
    if(!select_device){
        NSAssert(NO, @"can not create AVCaptureDevice with preset:%@", _mCameraPreset);
        return;
    }
    
    NSError* error=nil;
    _mVideoInput = [AVCaptureDeviceInput deviceInputWithDevice:select_device error:&error];
    if(error){
        NSAssert(NO, @"can not create AVCaptureDeviceInput with device:%@", select_device);
        return;
    }
    
    if(![_mSession canAddInput:_mVideoInput]){
        NSAssert(NO, @"can not add AVCaptureDevice:%@", _mVideoInput);
        return;
    }
    [_mSession addInput:_mVideoInput];
    
    [_mSession commitConfiguration];
}


#pragma mark - camera sample output
- (void)captureOutput:(AVCaptureOutput *)output didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer fromConnection:(AVCaptureConnection *)connection
{
    if([_sampleDelegate respondsToSelector:@selector(captureOutput:didOutputSampleBuffer:fromConnection:)]){
        [_sampleDelegate captureOutput:output didOutputSampleBuffer:sampleBuffer fromConnection:connection];
    }
    
    [[NESGLContext sharedContext] activeAsCurrentContext];
    CVPixelBufferRef img_buffer = CMSampleBufferGetImageBuffer(sampleBuffer);
    [self updateOutPutTexture:img_buffer];
    
    CMTime sample_time = CMSampleBufferGetPresentationTimeStamp(sampleBuffer);
    
    [self setupBufferForTargets];
    size_t img_width = CVPixelBufferGetWidth(img_buffer);
    size_t img_height = CVPixelBufferGetHeight(img_buffer);
    self.renderRect = CGRectMake(0, 0, img_width, img_height);
    [self notifyTargetsNewRenderReady:sample_time];
    
}

- (void)updateOutPutTexture:(CVPixelBufferRef)imgbuffer
{
    if(!self.outputTexture){
        self.outputTexture = [[NESGLTexture alloc] initWithTextureBuffer:imgbuffer];
    }
    else{
        [self.outputTexture refreshContentWithTextureBuffer:imgbuffer];
    }
}

- (void)setupBufferForTargets
{
    for(int i = 0; i < mtargets.count; i++){
        id<NESInput> i_t = [mtargets objectAtIndex:i];
        int i_i = [mtargetsOutputIndices objectAtIndex:i].intValue;
        [self setInputTextureForTarget:i_t atIndex:i_i];
        [i_t setRenderFramebuffer:mRenderFramebuffer];
    }
}



@end





