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

@interface ViewController ()<NESCameraDelegate>
{
    NESGLView* preview;
    NESCamera* capture;
    
}

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    capture = [[NESCamera alloc] initWithPreset:AVCaptureSessionPreset1280x720
                                         camera:AVCaptureDevicePositionBack];
    capture.sampleDelegate = self;
    
    preview = [[NESGLView alloc] initWithFrame:CGRectMake(0, 0,
                                                          self.view.bounds.size.width,
                                                          self.view.bounds.size.height)];
    [capture addOutputTarget:preview];
    
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
    NSLog(@"get capture output : %ld, %ld", s_width, s_height);
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
    
    
}


@end



