/************************************************************
This code is automatically generated by the VerticalThings compiler. DO NOT EDIT!
************************************************************/
/*Managed memory variables*/
unsigned char __vtmem[80];
int (*test_mod_xxx_p)[10]= (int (*)[10]) &__vtmem[0];
#define test_mod_xxx (*test_mod_xxx_p)
int (*test_mod_acquire_zzz_p)[10]= (int (*)[10]) &__vtmem[0];
#define test_mod_acquire_zzz (*test_mod_acquire_zzz_p)
int (*test_mod_acquire_yyy_p)[10]= (int (*)[10]) &__vtmem[40];
#define test_mod_acquire_yyy (*test_mod_acquire_yyy_p)
int (*test_mod2_fff_p)[10]= (int (*)[10]) &__vtmem[40];
#define test_mod2_fff (*test_mod2_fff_p)
/*End of managed memory variables*/
/*Module vars for test_mod*/
/*End of module vars for test_mod*/
/*Module vars for test_mod2*/
/*End of module vars for test_mod2*/
int (*test_mod2_process_val_p)[10];
#define test_mod2_process_val (*test_mod2_process_val_p)
typedef enum { __test_mod_acquire, __test_mod2_process}  __icane_test;
 __icane_test __state = __test_mod_acquire;
void _test_mod_acquire_acquire()
{
{
for(int i=0; i<10; i++)
{
test_mod_xxx[i]=i;
}
for(int i=0; i<10; i++)
{
test_mod_acquire_yyy[i]=(test_mod_xxx[i]*3);
}
for(int i=0; i<10; i++)
{
test_mod_acquire_zzz[i]=(test_mod_acquire_yyy[i]*4);
}
test_mod2_process_val_p = &(test_mod_acquire_zzz); __state = __test_mod2_process;
}
}
void _test_mod2_process_process()
{
const int test_mod2_process_x=3;
{
for(int i=0; i<10; i++)
{
test_mod2_fff[i]=(test_mod2_process_val[i]+test_mod2_process_x);
}
}
}
void loop()
{
switch(__state)
{
case __test_mod_acquire:
__state = __test_mod_acquire;
___test_mod_acquire();
break;
case __test_mod2_process:
__state = __test_mod_acquire;
___test_mod2_process();
break;
default :
__state = __test_mod_acquire;
}
}
void setup()
{
}