/********************************************************************************
This code is automatically generated by the VerticalThings compiler. DO NOT EDIT!
********************************************************************************/

struct _arec_event {int _state;};
#define NULL ((void *)0UL)
struct _arec__icane_m;
typedef void (*_t__icane_m) (struct _arec__icane_m* _this, float*  _ret0);
struct _arec__icane_m{
    int _state = 0;
    int icane_m_y;
    int icane_m_x;
};
struct _arec__icane_main;
typedef void (*_t__icane_main) (struct _arec__icane_main* _this, void*  _ret0);
struct _arec__icane_main{
    int _state = 0;
    float icane_main_v[100];
    float icane_main_res;
    struct _arec__icane_m _arec__icane_m;
};
struct _arec__icane_irq;
typedef void (*_t__icane_irq) ();
/*Module vars for icane*/
struct _arec__icane_m*  icane_f;
struct _arec_event*  icane_e;
/*End of module vars for icane*/
int _icane_m(struct _arec__icane_m* _this, float*  _ret0)
{
void * _atbl[] = {  };
int _state = _this->_state;
_this->_state = 0;
if (_state > 0 && _state < 0) goto *(_atbl[_state]);
lstate_0: 
{
}
return _this->_state;
}
int _icane_main(struct _arec__icane_main* _this)
{
void * _atbl[] = { &&lstate_0, &&lstate_1, &&lstate_2 };
int _state = _this->_state;
_this->_state = 0;
if (_state > 0 && _state < 3) goto *(_atbl[_state]);
lstate_0: 
{
    _this->icane_main_v[0]=1;
    _this->_arec__icane_m._state = 0;
    _this->_arec__icane_m.icane_m_y = 3;
    lstate_1: _state = _icane_m( &(_this->_arec__icane_m), &(_this->icane_main_res)) ;
    if (_state > 0) {_this->_state = 1; return _this->_state;} 
    _this->_arec__icane_m._state = 0;
    _this->_arec__icane_m.icane_m_y = 4;
    _icane_m( &(_this->_arec__icane_m), ((float*) 0UL)) ;
    icane_f= &(_this->_arec__icane_m);
    lstate_2: _state = _icane_m(icane_f, (&_this->icane_main_res) );
    if (_state > 0) {_this->_state = 2; return _this->_state;} 
    icane_e->_state = 1;
    lstate_3: _state = icane_e->_state;
    if (_state > 0) {_this->_state = 3; return _this->_state;} 
}
return _this->_state;
}
void _icane_irq()
{
    {
        icane_e->_state = 0;
    }
}