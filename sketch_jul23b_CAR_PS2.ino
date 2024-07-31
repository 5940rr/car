//自走車+夾子+PS2搖桿
#include <MatrixMini.h>
#include <MiniANG.h>
#include <MiniBTN.h>
#include <MiniDC.h>
#include <MiniDIG.h>
#include <MiniLED.h>
#include <MiniRC.h>
int x1=90;

void setup() {
  Mini.begin(7.6,1,9600);
  Mini.RGB1.setRGB(0,0,0);//0~255
  Mini.RGB2.setRGB(0,0,0);//0~255
  Mini.RC1.set(x1);

  Mini.PS2.begin();
}
void loop() {
  Mini.PS2.polling();
  if(Mini.PS2.TRIANGLE){
    Mini.RGB1.setRGB(0,0,255);
    x1=x1-5;
    if(x1<70) x1=70;
    Mini.RC1.set(x1);
    delay(200);
  }
  if(Mini.PS2.CIRCLE){
    Mini.RGB1.setRGB(0,255,0);
    x1=x1+5;
    if(x1>180) x1=180;
    Mini.RC1.set(x1);
    delay(200);
  }
  speed();
}

//單搖桿方向盤模式
void  speed(){
  int s0=map(Mini.PS2.LY,0,255,100,-100);
  int v1=map(Mini.PS2.LX,0,255,-100,100);
  int s1=sqrt(s0*s0+v1*v1);
  s1=map(s1,0,140,0,100);
  if(s0<0)  s1=-1*s1;

  int LM1,RM2;
  if(v1>0){
    LM1=s1;
    RM2=s1-s1*2*v1/100;
  }
  else{
    LM1=s1+s1*2*v1/100;
    RM2=s1;    
  }

  Mini.M1.set(LM1);
  Mini.M2.set(RM2); 

  Serial.print(LM1);
  Serial.print(" ");
  Serial.print(RM2);
  Serial.println(" ");
}

/*
//坦克模式
  int LM1=map(Mini.PS2.LY,0,255,100,-100);
  int RM2=map(Mini.PS2.RY,0,255,100,-100);

//方向盤模式
void  speed(){
  int s1=map(Mini.PS2.LY,0,255,100,-100);
  int v1=map(Mini.PS2.RX,0,255,-100,100);
  
  int LM1,RM2;
  if(v1>0){
    LM1=s1;
    RM2=s1-s1*2*v1/100;
  }
  else{
    LM1=s1+s1*2*v1/100;
    RM2=s1;    
  }

  Mini.M1.set(LM1);
  Mini.M2.set(RM2); 

  Serial.print(LM1);
  Serial.print(" ");
  Serial.print(RM2);
  Serial.println(" ");
}

*/






