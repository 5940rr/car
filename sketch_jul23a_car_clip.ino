//自走車+夾子
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
  Mini.RC1.set(130);

}

void loop() {
  while(Mini.BTN1.get()==0){}//按鈕1按下
  Mini.RGB1.setRGB(0,255,0);
  Mini.RC1.set(130);//夾子打開
  delay(1000);
  readD4();//偵測距離
  while(x1>15){//直到目標位置
    readD4();
    line();//循跡
  }
  Mini.M1.set(0);//停下
  Mini.M2.set(0);
  delay(1000);
  Mini.RC1.set(90);//夾取
  delay(1000);
//--------------------------------------  
  Mini.M1.set(-50);//轉到正後方
  Mini.M2.set(50);
  delay(100);//轉一點點離開黑線
  while(Mini.A3.getANG()<500){}//維持轉向直到看到黑線
  Mini.M1.set(0);//停下
  Mini.M2.set(0);
  delay(1000);
//-------------------------------------- 
  readD4();//偵測距離
  while(x1>15){//直到回程位置
    readD4();
    line();//循跡
  }
  Mini.M1.set(0);//停下
  Mini.M2.set(0);
  delay(1000);
  Mini.RC1.set(130);//打開夾子
//-------------------------------------- 
  Mini.M1.set(-50);//轉到正後方
  Mini.M2.set(50);
  delay(100);//轉一點點離開黑線
  while(Mini.A3.getANG()<500){}//維持轉向直到看到黑線
  Mini.M1.set(0);//停下
  Mini.M2.set(0);
  delay(1000);
  Mini.RGB1.setRGB(255,0,0);
}




void readD4(){
  x1=Mini.D4.US.get();
  while(x1<5){  x1=Mini.D4.US.get();}
}


void line(){
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
}

/*
//夾子角度
  if(Mini.BTN1.get()==1){
    Mini.RGB1.setRGB(0,100,0); 
    Mini.RC1.set(90);
  }
  if(Mini.BTN2.get()==1){
    Mini.RGB1.setRGB(255,0,0);  
    Mini.RC1.set(130);
  }

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
*/