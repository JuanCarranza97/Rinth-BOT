#include "Boca_Motors.h"

DcMotors::DcMotors(void)
 {
  
 }

void DcMotors::init(void){
  pinMode(MOTORA_IN1,OUTPUT);
  pinMode(MOTORA_IN2,OUTPUT);
  pinMode(MOTORB_IN1,OUTPUT);
  pinMode(MOTORB_IN2,OUTPUT);
  
  DcMotors::off();
}

void DcMotors::off(void)
 {
  DcMotors::set(0,0);
 }

 void DcMotors::setMotor(int _m,int _vel){

  if(_m == 1) {
      if(_vel == 0){
       digitalWrite(MOTORA_IN1,LOW);
       digitalWrite(MOTORA_IN2,LOW);
      }
      else if(_vel > 0) {
       analogWrite(MOTORA_IN1,map(_vel,0,100,0,255));
       digitalWrite(MOTORA_IN2,LOW);
      }
      else
      {
       digitalWrite(MOTORA_IN1,LOW);
       analogWrite(MOTORA_IN2,map(_vel,0,-100,0,255));
      }
  }

  else{
    if(_vel == 0){
    digitalWrite(MOTORB_IN1,LOW);
    digitalWrite(MOTORB_IN2,LOW);
   }
   else if(_vel > 0) {
    analogWrite(MOTORB_IN1,map(_vel,0,100,0,255));
    digitalWrite(MOTORB_IN2,LOW);
   }
   else
   {
    digitalWrite(MOTORB_IN1,LOW);
    analogWrite(MOTORB_IN2,map(_vel,0,-100,0,255));
   }
  }
   
 }

 void DcMotors::set(int _velA,int _velB)
 {
  DcMotors::setMotor(1,_velA);
  DcMotors::setMotor(2,_velB);
 }

