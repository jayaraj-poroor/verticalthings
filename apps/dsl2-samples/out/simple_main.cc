/********************************************************************************
This code is automatically generated by the VerticalThings compiler. DO NOT EDIT!
********************************************************************************/

struct _arec_event {volatile int _state;};
#define NULL ((void *)0UL)
struct _future {void *_parec; int (*_pfn)(void *, void *);}; 
#include "../inc/vtdefs.h"
#include "../inc/stm32_hal_ex1.h"
struct _arec__sys_HAL_io_completion;
typedef void (*_t__sys_HAL_io_completion) (struct _arec__sys_HAL_io_completion* _this, int*  _ret0);
struct _arec__sys_HAL_io_completion{
    int _state = 0;
    int sys_HAL_io_completion_io;
};
struct _arec__sys_HAL_start;
typedef int (*_t__sys_HAL_start) (int sys_HAL_start_io);
/*Module vars for sys*/
/*End of module vars for sys*/
struct _arec__simple_main_func;
typedef int (*_t__simple_main_func) (int simple_main_func_x);
struct _arec__simple_main_main;
typedef void (*_t__simple_main_main) (struct _arec__simple_main_main* _this, void*  _ret0);
struct _arec__simple_main_main{
    int _state = 0;
    int simple_main_main_u;
};
/*Module vars for simple_main*/
/*End of module vars for simple_main*/
int _sys_HAL_io_completion(struct _arec__sys_HAL_io_completion* _this, int* _ret0)
{
static const void * _atbl[] = { &&lstate_0 };
int _state = _this->_state;
_this->_state = 0;
if (_state > 0 && _state <= 0) goto *(_atbl[_state]);
 lstate_0:
{
}
return _this->_state;
}
int _sys_HAL_start(int sys_HAL_start_io)
{
    {
    }
}
int _simple_main_func(int simple_main_func_x)
{
    {
        return (simple_main_func_x*3);
    }
}
int _simple_main_main(struct _arec__simple_main_main* _this)
{
static const void * _atbl[] = { &&lstate_0 };
int _state = _this->_state;
_this->_state = 0;
if (_state > 0 && _state <= 0) goto *(_atbl[_state]);
 lstate_0:
{
    _simple_main_func(5) ;
}
return _this->_state;
}
/*Entry point - the 'C' main function*/
struct _arec__simple_main_main _arec_main;
int main(){
    int status = -1;
    while (status != 0){
        status = _simple_main_main(&_arec_main);
    }
    while (true);
    return 0;
}