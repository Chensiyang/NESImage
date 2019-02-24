//
//  ViewController.m
//  NESImageCameraDemo
//
//  Created by chen on 2019/2/16.
//  Copyright © 2019年 chen. All rights reserved.
//

#import "ViewController.h"
#import "NESCamera.h"
#import "NESGLView.h"
#import "NESGLGrayFilter.h"

@interface ViewController ()<NESCameraDelegate>
{
    NESGLView* preview;
    NESCamera* capture;
    NESGLGrayFilter *effect_filter;
    
}

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    capture = [[NESCamera alloc] initWithPreset:AVCaptureSessionPreset1280x720
                                         camera:AVCaptureDevicePositionFront];
    capture.sampleDelegate = self;
    
    preview = [[NESGLView alloc] initWithFrame:CGRectMake(0, 0,
                                                          self.view.bounds.size.width,
                                                          self.view.bounds.size.height)];
    effect_filter = [[NESGLGrayFilter alloc] init];
    
    [capture addOutputTarget:effect_filter];
    [effect_filter addOutputTarget:preview];
    
    [self.view addSubview:preview];
}

-(void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    [capture startRunning];
}

#pragma mark - camera output
-(void)captureOutput:(AVCaptureOutput *)output
didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer
      fromConnection:(AVCaptureConnection *)connection
{
    CVPixelBufferRef img_buffer = CMSampleBufferGetImageBuffer(sampleBuffer);
    size_t s_width = CVPixelBufferGetWidth(img_buffer);
    size_t s_height = CVPixelBufferGetHeight(img_buffer);
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
    
    
}


@end



