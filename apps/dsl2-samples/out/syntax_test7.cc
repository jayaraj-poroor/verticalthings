/********************************************************************************
This code is automatically generated by the VerticalThings compiler. DO NOT EDIT!
********************************************************************************/

struct _arec_event {volatile int _state;};
#define NULL ((void *)0UL)
struct _future {void *_parec; int (*_pfn)(void *, void *);}; 
#include "../inc/vtdefs.h"
#include "../inc/stm32_hal_ex1.h"
struct _t__int_int{int r0 ; int r1 ; _t__int_int() :  r0( (int) 0 ),  r1( (int) 0 ){}; void operator = (const _t__int_int& _obj) {r0= _obj.r0; r1= _obj.r1; };  _t__int_int(int p0 , int p1 ): r0(p0),  r1(p1){}; };
struct _arec__syntax_test7_func;
typedef struct _t__int_int (*_t__syntax_test7_func) ();
struct _arec__syntax_test7_fun1;
typedef void (*_t__syntax_test7_fun1) (struct _arec__syntax_test7_fun1* _this, struct _t__int_int*  _ret0);
struct _arec__syntax_test7_fun1{
    int _state = 0;
};
struct _arec__syntax_test7_main;
typedef void (*_t__syntax_test7_main) (struct _arec__syntax_test7_main* _this, void*  _ret0);
struct _arec__syntax_test7_main{
    int _state = 0;
    union _inner_arecs {
        struct _arec__syntax_test7_fun1 _arec__syntax_test7_fun1;
    _inner_arecs(){};
}
_arecs;
};
/*Module vars for syntax_test7*/
/*End of module vars for syntax_test7*/
struct _t__int_int _syntax_test7_func()
{
    {
        return _t__int_int(0, 1) ;
    }
}
int _syntax_test7_fun1(struct _arec__syntax_test7_fun1* _this, struct _t__int_int* _ret0)
{
static const void * _atbl[] = { &&lstate_0, &&lstate_1 };
int _state = _this->_state;
_this->_state = 0;
if (_state > 0 && _state <= 1) goto *(_atbl[_state]);
 lstate_0:
{
 lstate_1:
    if (_ret0 == NULL){
        _this->_state = 1;
    }
    else{
        *(_ret0) = _t__int_int(1, 1) ;
    }
    return _this->_state; 
}
return _this->_state;
}
int _syntax_test7_main(struct _arec__syntax_test7_main* _this)
{
    struct _t__int_int _t__int_int_ret;
static const void * _atbl[] = { &&lstate_0, &&lstate_1 };
int _state = _this->_state;
_this->_state = 0;
if (_state > 0 && _state <= 1) goto *(_atbl[_state]);
 lstate_0:
{
    _t__int_int_ret = _syntax_test7_func() ;
    int&  syntax_test7_main_a = _t__int_int_ret.r0;
    int&  syntax_test7_main_b = _t__int_int_ret.r1;
    _this->_arecs._arec__syntax_test7_fun1._state = 0;
 lstate_1:
    _state = _syntax_test7_fun1( &(_this->_arecs._arec__syntax_test7_fun1), &(_t__int_int_ret)) ;
    int&  syntax_test7_main_c = _t__int_int_ret.r0;
    int&  syntax_test7_main_d = _t__int_int_ret.r1;
    if (_state > 0) {_this->_state = 1; return _this->_state;} 
}
return _this->_state;
}
/*Entry point - the 'C' main function*/
struct _arec__syntax_test7_main _arec_main;
int main(){
    int status = -1;
    while (status != 0){
        status = _syntax_test7_main(&_arec_main);
    }
    while (true);
    return 0;
}