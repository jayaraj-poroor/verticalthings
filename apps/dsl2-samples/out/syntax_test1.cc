/********************************************************************************
This code is automatically generated by the VerticalThings compiler. DO NOT EDIT!
********************************************************************************/

struct _arec_event {volatile int _state;};
#define NULL ((void *)0UL)
struct _future {void *_parec; int (*_pfn)(void *, void *);}; 
#include "../inc/vtdefs.h"
#include "../inc/stm32_hal_ex1.h"
struct _arec__syntax_test1_samp;
typedef int (*_t__syntax_test1_samp) ();
struct _arec__syntax_test1_main;
typedef void (*_t__syntax_test1_main) (struct _arec__syntax_test1_main* _this, void*  _ret0);
struct _arec__syntax_test1_main{
    int _state = 0;
    int syntax_test1_main_x;
};
/*Module vars for syntax_test1*/
/*End of module vars for syntax_test1*/
int _syntax_test1_samp()
{
    {
        return 1;
    }
}
int _syntax_test1_main(struct _arec__syntax_test1_main* _this)
{
static const void * _atbl[] = { &&lstate_0 };
int _state = _this->_state;
_this->_state = 0;
if (_state > 0 && _state <= 0) goto *(_atbl[_state]);
 lstate_0:
{
    _this->syntax_test1_main_x = _syntax_test1_samp() ;
}
return _this->_state;
}
/*Entry point - the 'C' main function*/
struct _arec__syntax_test1_main _arec_main;
int main(){
    int status = -1;
    while (status != 0){
        status = _syntax_test1_main(&_arec_main);
    }
    while (true);
    return 0;
}