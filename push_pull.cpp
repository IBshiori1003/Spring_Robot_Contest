#include "mbed.h"
#include <stdio.h>

    //ピン出力の設定
    //_1が正回転、_2が逆回転    
PwmOut arm_rp_1(PC_8); //0.5出力 で動く、０出力で動かない
PwmOut arm_rp_2(PC_6);//0.5出力 で動く、０出力で動かない

    //ピン入力設定
DigitalIn pushrack(PC_11,PullUp); //ラックを押し出す
DigitalIn pullrack(PC_10,PullUp); //ラックを引き込む
    
     //PWM周期の設定
arm_r&p_1.period(50);
arm_r&p_2.period(50);

int main(){

       //ラックピニオンの操作
    if(push.read()==0){　//digitalIn ピンで数値を受け取った後
　     arm_r&p_1=0.5;
       arm_r&p_2=0;
       wait(300); //この時間の間ラックが押されている→その後ラックが自動で戻り始める
       arm_r&p_1=0;
       arm_r&p_2=0.5;
       wait(300);　//この時間の間ラックが戻っている→元の位置に戻る
       }
    else{
       arm_r&p_1=0.5;
       arm_r&p_2=0;
    } 
       
            }
          

