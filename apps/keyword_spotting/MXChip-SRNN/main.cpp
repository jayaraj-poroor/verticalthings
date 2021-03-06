/********************************************************************************
This code is automatically generated by the VerticalThings compiler. DO NOT EDIT!
********************************************************************************/

struct _arec_event {volatile int _state;};
#define NULL ((void *)0UL)
struct _future {void *_parec; int (*_pfn)(void *, void *);}; 
#include <Arduino.h>
#include <AudioClassV2.h>
#include "inc/src/lib/utils/circularq.h"
#include "inc/src/models/model.h"
#include "inc/src/lib/sfastrnn_pipeline/sfastrnnpipeline.h"
#include "inc/hot_fixes.h"
#include "inc/custom_structs.h"
#include "inc/hal_buf.h"
struct _arec__main_prediction_callback;
typedef void (*_t__main_prediction_callback) (float_pointer main_prediction_callback_vec, int main_prediction_callback_len);
struct _arec__main_setup;
typedef void (*_t__main_setup) ();
struct _arec__main_printStr;
typedef void (*_t__main_printStr) (char_pointer main_printStr_a);
struct _arec__main_main;
typedef void (*_t__main_main) (struct _arec__main_main* _this, void*  _ret0);
typedef char _char__512[512];
struct _t__int_int__char__512_int{int r0 ; int r1 ; _char__512* r2 ; int r3 ; _t__int_int__char__512_int() :  r0( (int) 0 ),  r1( (int) 0 ),  r2( (_char__512*) 0 ),  r3( (int) 0 ){}; void operator = (const _t__int_int__char__512_int& _obj) {r0= _obj.r0; r1= _obj.r1; r2= _obj.r2; r3= _obj.r3; };  _t__int_int__char__512_int(int p0 , int p1 , _char__512* p2 , int p3 ): r0(p0),  r1(p1),  r2(p2),  r3(p3){}; };
struct _arec__main_main{
    int _state = 0;
    int main_main_mic;
    int main_main_mic_buf;
    _t__int_int main_main_tmp;
    int main_main_idx=0;
    int main_main_non_blocking;
    int main_main_r_mic;
    int main_main_value;
    struct _t__int_int__char__512_int main_main_HAL_io_completion_result;
    union _inner_arecs {
        struct _arec__sys_HAL_io_completion _arec__sys_HAL_io_completion;
    _inner_arecs(){};
}
_arecs;
};
/*Module vars for main*/
int main_setup_const=1;
FastRNNParams main_fastrnnParams0;
FastRNNParams main_fastrnnParams1;
FCParams main_fcParams;
const_char_arr main_labelInvArr[13]={ "Noise", "go", "no", "on", "up", "bed", "cat", "dog", "off", "one", "six", "two", "yes"} ;
int main_len, main_value, main_current_queue_size;
int main_FRAME_LEN=400;
int main_VOTE_WIN_LEN=10;
int main_VOTE_MAJORITY=5;
int main_NUM_LABELS=13;
FIFOCircularQ main_votingQ;
static int main_votingContainer[10];
static int main_votingFrequence[13];
int main_TRANSFER_BUFFER_MAX_LEN=128;
static AudioClass& main_Audio=AudioClass::getInstance() ;
int main_AUDIO_CHUNK_SIZE=512;
static int main_transfer_buffer_curr_len=0;
static int16_t main_transfer_buffer[128];
/*End of module vars for main*/
/*Module vars for sys*/
/*End of module vars for sys*/
void _main_prediction_callback(float_pointer main_prediction_callback_vec, int main_prediction_callback_len)
{
    int main_prediction_callback_arg=argmax(main_prediction_callback_vec, main_prediction_callback_len) ;
    int main_prediction_callback_oldarg=get_q_oldest(&(main_votingQ)) ;
    char main_prediction_callback_str[20];
    {
        if(((main_prediction_callback_oldarg>=main_NUM_LABELS)||(main_prediction_callback_oldarg<0)))
        {
            main_prediction_callback_oldarg=0;
        }
        main_votingFrequence[main_prediction_callback_arg]=(main_votingFrequence[main_prediction_callback_arg]+1);
        main_votingFrequence[main_prediction_callback_oldarg]=(main_votingFrequence[main_prediction_callback_oldarg]-1);
        q_force_enqueue(&(main_votingQ), &(main_prediction_callback_arg)) ;
        if((main_votingFrequence[main_prediction_callback_arg]>=main_VOTE_MAJORITY))
        {
            sprintf(main_prediction_callback_str, "Pred: %s (%d)", main_labelInvArr[main_prediction_callback_arg], main_prediction_callback_arg) ;
            Screen.print(main_prediction_callback_str, false) ;
        }
    }
}
void _main_setup()
{
    uint32_t main_setup_ret;
    {
        q_init(&(main_votingQ), main_votingContainer, main_VOTE_WIN_LEN, cb_write_int, cb_read_int) ;
        main_votingFrequence[0]=5;
        Serial.begin(115200) ;
        Screen.init() ;
        delay(500) ;
        initFastRNN0(main_fastrnnParams0) ;
        initFastRNN1(main_fastrnnParams1) ;
        initFC(main_fcParams) ;
        delay(500) ;
        Screen.clean() ;
        main_setup_ret = sfastrnn2p_init(&(main_fastrnnParams0), &(main_fastrnnParams1), &(main_fcParams), main_prediction_callback) ;
        Serial.printf("Return code: %d (init)\n", main_setup_ret) ;
        if((main_setup_ret!=0))
        {
            error("Shallow FastRNN initialization failed (code %d)", main_setup_ret) ;
        }
        if((main_setup_ret!=0))
        {
            while(1)
            {
            }
        }
    }
}
void _main_printStr(char_pointer main_printStr_a)
{
    {
        Serial.println(main_printStr_a) ;
    }
}
int _main_main(struct _arec__main_main* _this)
{
    struct _t__int_int__char__512_int _t__int_int__char__512_int_ret;
static const void * _atbl[] = { &&lstate_0, &&lstate_1 };
int _state = _this->_state;
_this->_state = 0;
if (_state > 0 && _state <= 1) goto *(_atbl[_state]);
 lstate_0:
{
    if((main_setup_const==1))
    {
        main_setup_const=0;
        _main_setup() ;
    }
    _this->main_main_r_mic = _sys_HAL_start(_this->main_main_mic, _this->main_main_mic_buf) ;
    while((1>0))
    {
        main_current_queue_size = pred_func() ;
        if((main_current_queue_size>=main_FRAME_LEN))
        {
            _this->main_main_non_blocking=1;
        }
        else
        {
            _this->main_main_non_blocking=0;
        }
        _this->_arecs._arec__sys_HAL_io_completion._state = 0;
        _this->_arecs._arec__sys_HAL_io_completion.sys_HAL_io_completion_rc = _this->main_main_r_mic;
        _this->_arecs._arec__sys_HAL_io_completion.sys_HAL_io_completion_non_blocking = _this->main_main_non_blocking;
 lstate_1:
        _state = _sys_HAL_io_completion( &(_this->_arecs._arec__sys_HAL_io_completion), &(_t__int_int__char__512_int_ret)) ;
        int&  main_main_MIC = _t__int_int__char__512_int_ret.r0;
        int&  main_main_MIC_BUF = _t__int_int__char__512_int_ret.r1;
        _char__512& main_main_readBuffer = (*_t__int_int__char__512_int_ret.r2);
        int&  main_main_len = _t__int_int__char__512_int_ret.r3;
        if (_state > 0) {_this->_state = 1; return _this->_state;} 
        if((main_main_len>0))
        {
            main_main_len=(main_main_len/2);
            main_main_len=(main_main_len-(main_main_len%2));
            main_main_len=(main_main_len/2);
            if((main_main_len>0))
            {
                _this->main_main_idx=0;
                while((_this->main_main_idx<main_main_len))
                {
                    _this->main_main_tmp = _sys_HAL_buf_at(main_main_MIC_BUF, (2*_this->main_main_idx)) ;
                    main_transfer_buffer[_this->main_main_idx] = to_int16t(_this->main_main_tmp.r0) ;
                    _this->main_main_idx=(_this->main_main_idx+1);
                }
            }
        }
        _this->main_main_r_mic = _sys_HAL_start(main_main_MIC, main_main_MIC_BUF) ;
        if((main_main_len>0))
        {
            sfastrnn2p_add_new_samples(main_transfer_buffer, main_main_len) ;
        }
    }
}
return _this->_state;
}
/*Entry point - the 'C' main function*/
struct _arec__main_main _arec_main;
void loop(){
    int status = -1;
    _arec_main.main_main_mic=0;
    _arec_main.main_main_mic_buf=1;
    while (status != 0){
        status = _main_main(&_arec_main);
    }
    while (true);
    return;
}
void setup(){}
