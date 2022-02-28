#include "mbed.h"
#include "EC.h"　//ロボステlibrary確認　エンコーダーの角度、角速度とかの計算のプログラムが入ってる
 
 //start running the motor once the controller pushes the button
     //ピン出力の設定
    //_1が正回転、_2が逆回転    
PwmOut arm_rotate1(PB_6); //0.5出力 で動く、０出力で動かない
PwmOut arm_rotate(PA_5);//0.5出力 で動く、０出力で動かない

    //ピン入力設定
DigitalIn POSorg(PC_11,PullUp); //初期位置の角度ボタン
DigitalIn POS1(PC_10,PullUp); //1st positionボタン
DigitalIn POS2(PC_10,PullUp); //2nd positionボタン
    
     //PWM周期の設定
arm_rotate1(50);
arm_rotate2(50);

int main(){
    while(1){
       
       //arm 角度回転の操作
    if(push.read()==0){　//digitalIn POS1ピンで数値を受け取った後 moving to 1st position
　     arm_rotate1=0.5;
       arm_rotate2=0;
       {
           //start timer, measure the angle of the motor. 
           if(40<theta<45){
                arm_rotate1=0;
                arm_rotate2=0;
                wait(300); //この時間の間ｍモーターが止まっている
                //この時間内に射出がなされている
                
                
       }
       

     if(push.read()==0){　//digitalIn POS2ピンで数値を受け取った後 moving to 2nd position
　     arm_rotate1=0.5;
       arm_rotate2=0;
       {
           //start timer, measure the angle of the motor. 
           if(70<theta<75){
                arm_rotate1=0;
                arm_rotate2=0;
                wait(300); //この時間の間ｍモーターが止まっている
                //この時間内に射出がなされている
                
                
     }
       

    if(push.read()==0){　//digitalIn POSorgピンで数値を受け取った後 moving to 1st position
　     arm_rotate1=0;
       arm_rotate2=0.5;
       {
           //start timer, measure the angle of the motor. 
           if(0<theta<5){
                arm_rotate1=0;
                arm_rotate2=0;
                wait(300); //この時間の間ｍモーターが止まっている
                //この時間内に射出がなされている
                
                
       }
       
            }
        }    
}

 // program to obtain the angle the motor moved
Ec::Ec(int res, int multi) : count_(0), pre_omega_(0), pre_count_(0), resolution_(res), multiplication_(multi)
{
    timer_.start();
    setGearRatio(1);
}
 
int Ec::getCount() const
{
    return count_;
}
 
double Ec::getRad() const
{
    return count_ * 2.0f * M_PI / (multiplication_ * resolution_ * gear_ratio_);
}
double Ec::getDeg() const
{
    return count_ * 2.0f * 180.0 / (multiplication_ * resolution_ * gear_ratio_);
}
void Ec::calOmega()
{
    double t = timer_.read();
    double delta_time = t - ptw_;
    acceleration_ = (pre_omega_ - pre2_omega_) / delta_time;
    pre2_omega_ = pre_omega_;
    pre_omega_ = omega_;
    omega_ = (count_ - pre_count_) * 2.0f * M_PI / (multiplication_ * resolution_ * delta_time);
    omega_ /= gear_ratio_;
    pre_count_ = count_;
    ptw_ = t;
}
 
double Ec::getOmega() const
{
    return omega_;
}
double Ec::getAcceleration() const
{
    return acceleration_;
}
void Ec::setResolution(int res)
{
    resolution_ = res;
}
 
/*reset関数の定義*/
/*エンコーダを初期状態に戻すことができる*/
void Ec::reset()
{
    count_ = 0;
    pre_count_ = 0, omega_ = 0;
    ptw_ = 0;
    timer_.stop();
    timer_.reset();
    timer_.start();
}
void Ec::setGearRatio(double gear_r)
{
    gear_ratio_ = gear_r;
}
 
////////////////////////////////////////////////////1逓倍//////////////////////////////////////////////////////////////////
Ec1multi::Ec1multi(PinName signalA, PinName signalB, int res) : Ec(res, 1), signalA_(signalA), signalB_(signalB)
{
    signalA_.rise(callback(this, &Ec1multi::upA));
}
 
//ピン変化割り込み関数の定義
void Ec1multi::upA()
{
    if (signalB_.read())
        count_++;
    else
        count_--;
}
////////////////////////////////////////////////////2逓倍//////////////////////////////////////////////////////////////////
Ec2multi::Ec2multi(PinName signalA, PinName signalB, int res) : Ec(res, 2), signalA_(signalA), signalB_(signalB)
{
    signalA_.rise(callback(this, &Ec2multi::upA));
    signalA_.fall(callback(this, &Ec2multi::downA));
}
 
//ピン変化割り込み関数の定義
void Ec2multi::upA()
{
    if (signalB_.read())
        count_++;
    else
        count_--;
}
void Ec2multi::downA()
{
    if (signalB_.read())
        count_--;
    else
        count_++;
}
#include "mbed.h"
//original position −９０度
//height1
//heigh2

   //ピン出力の設定   
PwmOut arm_r&p_1(PB_6); //0.5出力 で動く、０出力で動かない
PwmOut arm_r&p_2(PA_5);//0.5出力 で動く、０出力で動かない

    //ピン入力設定
DigitalIn pushrack(PC_11,PullUp); //ラックを押し出す
DigitalIn pullrack(PC_10,PullUp); //ラックを引き込む
    
     //PWM周期の設定
arm_r&p_1.period(50);
arm_r&p_2.period(50);
