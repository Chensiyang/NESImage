//
//  NESCGLHelper.hpp
//  NESImage
//
//  Created by chen on 2018/8/1.
//  Copyright © 2018年 chen. All rights reserved.
//

#ifndef NESCGLHelper_hpp
#define NESCGLHelper_hpp

#include <stdio.h>
#include <semaphore.h>
#include <assert.h>

namespace NESCGL {
    
    //indicate current thread block behaviour
    enum {
        
      NES_THREAD_BLOCK = 0,     //block current thread by inner method
      NES_THREAD_UNBLOCK = 1,   //do not block current thread by inner method
    };
    
    enum{
        
        NES_GLSAFE_LEVEL_NONE = 0,          //always invoke gl interface
        NES_GLSAFE_LEVEL_SKIPINVOKE = 1,    //when not safe, skip this invoke action
        NES_GLSAFE_LEVEL_BLOCKANDWAITE = 2, //when not safe, block current thread and wait for awake
    };
    
    
class NESCGLHelper{
    
public:
    NESCGLHelper(void);
    ~NESCGLHelper(void);
    
public:
    bool isGLStateSafe;
    int glInvokeSafeLevel;//if set to NES_GLSAFE_LEVEL_SKIPINVOKE,nes_glxxx method invoke may return NES_GLOPERATION_SKIP when isGLStateSafe is false
    
public:
    void blockThread(void);
    void unblockThread(void);
    
private:
    sem_t *thread_block_semaphore;
    
};
    
    
inline NESCGLHelper::NESCGLHelper(void)
{
    isGLStateSafe = true;
    glInvokeSafeLevel = NES_GLSAFE_LEVEL_BLOCKANDWAITE;
#ifdef __APPLE__
    thread_block_semaphore = sem_open("NES_thread_syn_semaphore", O_CREAT, 0644, 1);
#else
    sem_init(thread_block_semaphore, 0, 1);
#endif
    if(SEM_FAILED == thread_block_semaphore){
        assert(0);
    }
}
    
inline NESCGLHelper::~NESCGLHelper(void)
{
    if(thread_block_semaphore){
#ifdef __APPLE__
        int retErr = sem_close(thread_block_semaphore);
        if(-1 == retErr)
        {
            assert(false);
        }
        retErr = sem_unlink("NES_thread_syn_semaphore");
        if(-1 == retErr)
        {
            assert(false);
        }
#else
      
        sem_destroy(thread_block_semaphore);
#endif
    }
}

inline void NESCGLHelper::blockThread(void)
{
    sem_wait(thread_block_semaphore);
}

inline void NESCGLHelper::unblockThread(void)
{
    sem_post(thread_block_semaphore);
}

NESCGLHelper* access_shared_helper()
{
    static NESCGLHelper* default_cglhelper_instance = NULL;
    if(NULL == default_cglhelper_instance)
    {
        default_cglhelper_instance = new NESCGLHelper();
    }
    return default_cglhelper_instance;
}

    
}//end NESCGL



#endif /* NESCGLHelper_hpp */
