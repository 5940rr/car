#include <MatrixMini.h>
#include <MiniANG.h>
#include <MiniBTN.h>
#include <MiniDC.h>
#include <MiniDIG.h>
#include <MiniLED.h>
#include <MiniRC.h>
int x1=0;

void setup() {
  Mini.begin(,1,9600);
  Mini.RGB1.se7.6tRGB(255,100,0);//0~255
  Mini.RGB2.setRGB(0,100,0);//0~255
}

void loop() {
  if(Mini.BTN1.get()==1){
    delay(300);
    if(Mini.BTN1.get()==1){//長按
      x1--;  
      if(x1<0)  x1=49;
      led01();
      while(Mini.BTN1.get()==1){}      
    }
    else{//短按
      x1++;
      led01();
    }
  }
}


void led01(){
  if(x1%5==0){  Mini.RGB1.setRGB(0,0,0);}
  if(x1%5==1){  Mini.RGB1.setRGB(255,0,0);}  
  if(x1%5==2){  Mini.RGB1.setRGB(0,255,0);} 
  if(x1%5==3){  Mini.RGB1.setRGB(0,0,255);} 
  if(x1%5==4){  Mini.RGB1.setRGB(255,255,255);} 
}









/*
//一增一減
if(Mini.BTN1.get()==1){
    x1++;
    led01();
    while(Mini.BTN1.get()==1){}
  }
if(Mini.BTN2.get()==1){
    x1--;
    if(x1<0)  x1=49;
    led01();
    delay(300);
  }


//巢狀-雙按鈕
  if(Mini.BTN1.get()==1){
    if(Mini.BTN2.get()==1){
      Mini.RGB1.setRGB(0,0,255);
      Mini.RGB2.setRGB(0,0,255);
    }
    else{
      Mini.RGB1.setRGB(0,255,0);
      Mini.RGB2.setRGB(255,0,0);
    }
  }
  else{
    if(Mini.BTN2.get()==1){
      Mini.RGB1.setRGB(255,0,0);
      Mini.RGB2.setRGB(0,255,0);
    }
    else{
      Mini.RGB1.setRGB(255,0,0);
      Mini.RGB2.setRGB(255,0,0);
    }
  }


//條件式-雙按鈕
if(Mini.BTN1.get()==0&&Mini.BTN2.get()==0){
    Mini.RGB1.setRGB(255,0,0);
    Mini.RGB2.setRGB(255,0,0);
  }
  if(Mini.BTN1.get()==1&&Mini.BTN2.get()==0){
    Mini.RGB1.setRGB(0,255,0);
    Mini.RGB2.setRGB(255,0,0);
  }
  if(Mini.BTN1.get()==0&&Mini.BTN2.get()==1){
    Mini.RGB1.setRGB(255,0,0);
    Mini.RGB2.setRGB(0,255,0);
  }
  if(Mini.BTN1.get()==1&&Mini.BTN2.get()==1){
    Mini.RGB1.setRGB(0,0,255);
    Mini.RGB2.setRGB(0,0,255);
  }

//呼吸燈
  for(int i=0;i<255;i++){
    Mini.RGB1.setRGB(i,0,255-i);
    delay(50);
  }
  for(int i=0;i<255;i++){
    Mini.RGB1.setRGB(255-i,0,i);
    delay(50);
  }


  */
