//自走車
#include <MatrixMini.h>
#include <MiniANG.h>
#include <MiniBTN.h>
#include <MiniDC.h>
#include <MiniDIG.h>
#include <MiniLED.h>
#include <MiniRC.h>
int x1=0;

void setup() {
  Mini.begin(7.6,1,9600);
  Mini.RGB1.setRGB(0,0,0);//0~255
  Mini.RGB2.setRGB(0,100,0);//0~255
}

void loop() {
  if(Mini.BTN1.get()==1){
    Mini.RGB1.setRGB(0,100,0); 
    Mini.RC1.set(70);
  }
  if(Mini.BTN2.get()==1){
    Mini.RGB1.setRGB(255,0,0);  
    Mini.RC1.set(110);
  }
}


/*
//循跡
  if(Mini.A3.getANG()>500){
    if(Mini.A3.getANG()>900){
      Mini.M1.set(0);//0~100
      Mini.M2.set(50);
    }
    else{
      Mini.M1.set(40);//0~100
      Mini.M2.set(50);
    }
  }
  else{
    if(Mini.A3.getANG()>100){
    Mini.M1.set(50);//0~100
    Mini.M2.set(40);
    }
    else{
    Mini.M1.set(50);//0~100
    Mini.M2.set(0);
    }
  }


//顯示數值

  Serial.print(Mini.A3.getANG());
  Serial.println("");

//車體移動
 if(Mini.BTN1.get()==1){
    Mini.RGB1.setRGB(0,100,0);
    Mini.M1.set(50);//0~100
    Mini.M2.set(50);
    delay(1000);
    Mini.M1.set(50);//0~100
    Mini.M2.set(0);  
    delay(500);   
    Mini.M1.set(50);//0~100
    Mini.M2.set(50);
    delay(1000);
    Mini.M1.set(0);//0~100
    Mini.M2.set(0);
    delay(1000);    
  }
  if(Mini.BTN2.get()==1){
    Mini.RGB1.setRGB(100,0,0);
    Mini.M1.set(0);
    Mini.M2.set(0);
  }

*/
