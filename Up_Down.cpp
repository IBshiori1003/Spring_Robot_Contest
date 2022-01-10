#include "mbed.h"
#include <stdio.h>

    //ピン出力の設定
    //_1が正回転、_2が逆回転    
PwmOut arm_r&p_1(PB_6); //0.5出力 で動く、０出力で動かない
PwmOut arm_r&p_2(PA_5);//0.5出力 で動く、０出力で動かない

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
       
       //エアシリンダーの動作
        if(hold.read()==0){
            wait(0.05);
            if(hold.read()==0){//やや長押しで反応
                printf("hold\r\n");
                cylinder=1;
            }
            
        }else if(release.read()==0){
            wait(0.05);
            if(release.read()==0){
                printf("release\r\n");
                cylinder=0;
            }
        }    
}

