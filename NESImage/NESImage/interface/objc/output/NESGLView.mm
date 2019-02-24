//
//  NESGLView.m
//  NESImage
//
//  Created by chen on 2019/2/12.
//  Copyright © 2019年 chen. All rights reserved.
//

#import "NESGLView.h"
#import "NESGLFramebuffer.h"
#import "NESGLContext.h"
#import "NESCGL.hpp"
#import "NESCGLProgram.hpp"
#import "NESCGLFramebuffer.hpp"
#import "NESCGLFilter.hpp"

@interface NESGLView()
{
    NESGLContext *drawable_context;
    NESGLFramebuffer* present_framebuffer;
    NESCGL::NESuint present_renderbuffer;
    
    CGSize m_view_pixel_size;
}

@end

@interface NESGLView()
{
    NESCGL::NESCGLFramebuffer *cnative_render_framebuffer;
    NESCGL::NESCGLTexture *cnative_inputtexture;
    
    NESCGL::NESRecti render_rect;
//    NESGLTexture* test_textture;
    
    NESCGL::NESint pro_vertex_id;
    NESCGL::NESint pro_tex_coordinate_id;
    NESCGL::NESint pro_input_texture_id;
    
    NESCGL::NESfloat vertex_array[8];
    NESCGL::NESfloat coordinate_array[8];
    
}

@property (assign, nonatomic) NESCGL::NESCGLProgram *cnative_program;

@end

@implementation NESGLView

+(Class)layerClass
{
    return [CAEAGLLayer class];
}

-(void)dealloc
{
    [self releaseFramebuffer];
    [self releaseRenderBuffer];
    [self releaseRenderFilter];
}

-(instancetype)init
{
    if(!(self = [super init])){
        return nil;
    }
    
    drawable_context = [NESGLContext sharedContext];
    
    [self configureGLLayer];
    [self createGLViewFrameBuffer];
    
    [self createRenderProgram];
    
    return self;
}

-(instancetype)initWithFrame:(CGRect)frame
{
    if(!(self = [super initWithFrame:frame])){
        return nil;
    }
    
    drawable_context = [NESGLContext sharedContext];
    
    [self configureGLLayer];
    [self createGLViewFrameBuffer];
    
    [self createRenderProgram];
    
    return self;
}

-(void)layoutSubviews
{
    [super layoutSubviews];
    [self rebuildRenderBufferIfNeed];
    [self renderGLViewStorage];
    
}

- (void)rebuildRenderBufferIfNeed
{
    [drawable_context activeAsCurrentContext];
    nes_glBindFramebuffer(GL_FRAMEBUFFER, present_framebuffer.framebufferId);
    nes_glBindRenderbuffer(GL_RENDERBUFFER, 0);
    nes_glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, 0);
    
    [self releaseRenderBuffer];
    [self createGLViewRenderBuffer];
    
}

//  necessary for retain display
- (void)configureGLLayer
{
    CAEAGLLayer* n_layer = (CAEAGLLayer*)self.layer;
    n_layer.opaque = NO;
    n_layer.hidden = NO;
    n_layer.drawableProperties = @{kEAGLDrawablePropertyRetainedBacking:[NSNumber numberWithBool:NO],
                                   kEAGLDrawablePropertyColorFormat:kEAGLColorFormatRGBA8
                                   };
    if([self respondsToSelector:@selector(contentScaleFactor)])
    {
        CGFloat screen_scale = [[UIScreen mainScreen] scale];
        [n_layer setContentsScale:screen_scale];
    }
}
//  set up render buffer for view and connect to framebuffer
- (void)renderGLViewStorage
{
    [drawable_context activeAsCurrentContext];
    nes_glBindFramebuffer(GL_FRAMEBUFFER, present_framebuffer.framebufferId);
    nes_glBindRenderbuffer(GL_RENDERBUFFER, present_renderbuffer);
    CAEAGLLayer* n_layer = (CAEAGLLayer*)self.layer;
    [[drawable_context context] renderbufferStorage:GL_RENDERBUFFER fromDrawable:n_layer];
    
    GLint backingWidth, backingHeight;
    nes_glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_WIDTH, &backingWidth);
    nes_glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_HEIGHT, &backingHeight);
    
    m_view_pixel_size.width = backingWidth;
    m_view_pixel_size.height = backingHeight;
    
    nes_glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, present_renderbuffer);
    
//    test_textture = [[NESGLTexture alloc] initWithImageSize:CGSizeMake(self.frame.size.width,
//                                                                       self.frame.size.height)];
//    [present_framebuffer framebufferAttatchColorTexture:test_textture];
    
}

#pragma mark - nesinput delegate
- (void)setRenderFramebuffer:(NESGLFramebuffer*)framebuffer
{
    //TO DO
}
- (void)setRotation:(NESImageOrientation)rotation atIndex:(NSUInteger)index
{
    mInputRotation = rotation;
}
- (void)setInputTexture:(NESGLTexture*)texture atIndex:(NSUInteger)index
{
    mInputTexture = texture;
    cnative_inputtexture = (NESCGL::NESCGLTexture*)NES_get_native_texture(mInputTexture);
}
- (void)renderFrame:(CGRect)rect atTime:(CMTime)time
{
    if(!mInputTexture){
        return;
    }
    [drawable_context activeAsCurrentContext];
    
    if(_cnative_program){
        
        [self reCalculateVertexArray];
        
        render_rect.x = 0;
        render_rect.y = 0;
        render_rect.width = (int)m_view_pixel_size.width;
        render_rect.height = (int)m_view_pixel_size.height;
        
        cnative_render_framebuffer->bindtoFramebufferViewPort(&render_rect);
        nes_glClearColor(0.0, 0.0, 0.0, 1.0);
        nes_glClear(GL_COLOR_BUFFER_BIT);
        
        nes_glVertexAttribPointer(pro_vertex_id, 2, GL_FLOAT, 0, 0, vertex_array);
        nes_glVertexAttribPointer(pro_tex_coordinate_id, 2, GL_FLOAT, 0, 0, coordinate_array);
        
        _cnative_program->useProgram();
        nes_glActiveTexture(GL_TEXTURE1);
        nes_glBindTexture(GL_TEXTURE_2D, cnative_inputtexture->textureid);
        nes_glUniform1i(pro_input_texture_id, 1);
        
        nes_glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }
    
    glFinish();
    nes_glBindRenderbuffer(GL_RENDERBUFFER, present_renderbuffer);
    [[drawable_context context] presentRenderbuffer:GL_RENDERBUFFER];
    
}

- (void)reCalculateVertexArray
{
    switch (_contentModel) {
            
        case NESViewContentModelScale:
        {
            vertex_array[0] = -1.0;
            vertex_array[1] = -1.0;
            
            vertex_array[2] = 1.0;
            vertex_array[3] = -1.0;
            
            vertex_array[4] = -1.0;
            vertex_array[5] = 1.0;
            
            vertex_array[6] = 1.0;
            vertex_array[7] = 1.0;
        }
            break;
        case NESViewContentModelAspect:
        {
            float width_fill_rate = cnative_inputtexture->size.x/m_view_pixel_size.width;
            float height_fill_rate = cnative_inputtexture->size.y/m_view_pixel_size.height;
            float min_fill_rate = MIN(width_fill_rate, height_fill_rate);
            
            float view_port_width = cnative_inputtexture->size.x*min_fill_rate;
            float view_port_height = cnative_inputtexture->size.y*min_fill_rate;
            float view_port_x = (view_port_width-m_view_pixel_size.width)*0.5;
            float view_port_y = (view_port_height-m_view_pixel_size.height)*0.5;
            
            float vertex_left = (view_port_x/m_view_pixel_size.width)*2.0-1.0;
            float vertex_bottom = (view_port_y/m_view_pixel_size.height)*2.0-1.0;
            float vertex_right = ((view_port_x+view_port_width)/m_view_pixel_size.width)*2.0-1.0;
            float vertex_top = ((view_port_y+view_port_height)/m_view_pixel_size.height)*2.0-1.0;
            
            vertex_array[0] = vertex_left;
            vertex_array[1] = vertex_bottom;
            
            vertex_array[2] = vertex_right;
            vertex_array[3] = vertex_bottom;
            
            vertex_array[4] = vertex_left;
            vertex_array[5] = vertex_top;
            
            vertex_array[6] = vertex_right;
            vertex_array[7] = vertex_top;
        }
            break;
        case NESViewContentModelAspectFill:
        {
            float width_fill_rate = cnative_inputtexture->size.x/m_view_pixel_size.width;
            float height_fill_rate = cnative_inputtexture->size.y/m_view_pixel_size.height;
            float max_fill_rate = MAX(width_fill_rate, height_fill_rate);
            
            float view_port_width = cnative_inputtexture->size.x*max_fill_rate;
            float view_port_height = cnative_inputtexture->size.y*max_fill_rate;
            float view_port_x = (view_port_width-m_view_pixel_size.width)*0.5;
            float view_port_y = (view_port_height-m_view_pixel_size.height)*0.5;
            
            float vertex_left = (view_port_x/m_view_pixel_size.width)*2.0-1.0;
            float vertex_bottom = (view_port_y/m_view_pixel_size.height)*2.0-1.0;
            float vertex_right = ((view_port_x+view_port_width)/m_view_pixel_size.width)*2.0-1.0;
            float vertex_top = ((view_port_y+view_port_height)/m_view_pixel_size.height)*2.0-1.0;
            
            vertex_array[0] = vertex_left;
            vertex_array[1] = vertex_bottom;
            
            vertex_array[2] = vertex_right;
            vertex_array[3] = vertex_bottom;
            
            vertex_array[4] = vertex_left;
            vertex_array[5] = vertex_top;
            
            vertex_array[6] = vertex_right;
            vertex_array[7] = vertex_top;
        }
            break;
        case NESViewContentModelNone:
        default:
        {
            vertex_array[0] = -1.0;
            vertex_array[1] = -1.0;
            
            vertex_array[2] = (cnative_inputtexture->size.x/m_view_pixel_size.width)*2.0-1.0;
            vertex_array[3] = -1.0;
            
            vertex_array[4] = -1.0;
            vertex_array[5] = (cnative_inputtexture->size.y/m_view_pixel_size.height)*2.0-1.0;
            
            vertex_array[6] = (cnative_inputtexture->size.x/m_view_pixel_size.width)*2.0-1.0;
            vertex_array[7] = (cnative_inputtexture->size.y/m_view_pixel_size.height)*2.0-1.0;
        }
            break;
    }
    
}

- (void)createRenderProgram
{
    _cnative_program = new NESCGL::NESCGLProgram(NESCGL::default_glprogram_vertex_shader,
                                               NESCGL::default_glprogram_fragment_shader);
    _cnative_program->linkProgram();
    _cnative_program->useProgram();
    pro_vertex_id = nes_glGetAttribLocation(_cnative_program->programid, "position");
    pro_tex_coordinate_id = nes_glGetAttribLocation(_cnative_program->programid, "inputTextureCoordinate");
    pro_input_texture_id = nes_glGetUniformLocation(_cnative_program->programid, "inputImageTexture");
    
    nes_glEnableVertexAttribArray(pro_vertex_id);
    nes_glEnableVertexAttribArray(pro_tex_coordinate_id);
    
    coordinate_array[0] = 0.0;
    coordinate_array[1] = 1.0;
    
    coordinate_array[2] = 1.0;
    coordinate_array[3] = 1.0;
    
    coordinate_array[4] = 0.0;
    coordinate_array[5] = 0.0;
    
    coordinate_array[6] = 1.0;
    coordinate_array[7] = 0.0;
    
}
- (void)createGLViewFrameBuffer
{
    [drawable_context activeAsCurrentContext];
    present_framebuffer = [[NESGLFramebuffer alloc] init];
    cnative_render_framebuffer = (NESCGL::NESCGLFramebuffer*)NES_get_native_framebuffer(present_framebuffer);
}
- (void)createGLViewRenderBuffer
{
    [drawable_context activeAsCurrentContext];
    nes_glGenRenderbuffers(1, &present_renderbuffer);
}
- (void)releaseFramebuffer
{
    present_framebuffer = nil;
}
- (void)releaseRenderBuffer
{
    [drawable_context activeAsCurrentContext];
    if(present_renderbuffer){
        nes_glDeleteRenderbuffers(1, &present_renderbuffer);
        present_renderbuffer = 0;
    }
}
- (void)releaseRenderFilter
{
    if(_cnative_program){
        delete _cnative_program;
    }
}

@end



