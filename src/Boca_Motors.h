#ifndef Boca_Motors_H
#define Boca_Motors_H

#include <Arduino.h>

 #define MOTORA_IN1    10
 #define MOTORA_IN2     9
 
 #define MOTORB_IN1     5
 #define MOTORB_IN2     6

 class DcMotors{
   public:
     DcMotors(void);  
     
     void init(void);
     void off(void);
     void setMotor(int _m,int _vel);
     void set(int _velA,int _velB);
 };
#endif 
