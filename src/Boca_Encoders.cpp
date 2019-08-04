#include "Boca_Encoders.h"

int leftCount=0,rightCount=0;

long encTimeA=0,encTimeP=0;
int lastLeftCount=0,lastRightCount=0;
int leftRPM,rightRPM;

int timeToCheck = 20;

void initialize_encoders(void){
  attachInterrupt(digitalPinToInterrupt(OUTA_LEFT_M), external_interrupt_outA_LM_ISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(OUTA_RIGHT_M), external_interrupt_outA_RM_ISR, CHANGE);
  #ifdef DEBUG_ENCODERS
    attachInterrupt(digitalPinToInterrupt(OUTB_LEFT_M), external_interrupt_outB_LM_ISR, CHANGE);
    attachInterrupt(digitalPinToInterrupt(OUTB_RIGHT_M), external_interrupt_outB_RM_ISR, CHANGE);
  #endif
}

int get_encoder_count(int enc){
  if(enc == 0) return leftCount;
  else         return rightCount;
}

int get_RPM(int enc){
  if(enc == 0) return leftRPM;
  else         return rightRPM;
}

void set_time_to_check(int value){
  timeToCheck = value;
}

void check_rpm(void){
  encTimeA=millis();
  if((encTimeA-encTimeP) > timeToCheck){
    leftRPM = leftCount-lastLeftCount;
    rightRPM = rightCount-lastRightCount;
    lastLeftCount = leftCount;
    lastRightCount=rightCount;
    encTimeP = millis();
  }
}

void external_interrupt_outA_LM_ISR(void){
  #ifdef BEBUG_ENCODERS
    uart_port.println("INTERRUPT: LEFT MOTOR -A");
  #endif
  
  #ifndef NEGATE_LEFT_COUNTER
    if (digitalRead(OUTA_LEFT_M) == HIGH) {
      if (digitalRead(OUTB_LEFT_M) == LOW) leftCount++;
      else                                 leftCount--;
    }else{
      if (digitalRead(OUTB_LEFT_M) == LOW) leftCount--;
      else                                 leftCount++;
    }
  #else
    if (digitalRead(OUTA_LEFT_M) == HIGH) {
      if (digitalRead(OUTB_LEFT_M) == LOW) leftCount--;
      else                                 leftCount++;
    }else{
      if (digitalRead(OUTB_LEFT_M) == LOW) leftCount++;
      else                                 leftCount--;
    }
  #endif
}

void external_interrupt_outB_LM_ISR(void){
  #ifdef BEBUG_ENCODERS
    uart_port.println("INTERRUPT: LEFT MOTOR -B");
  #endif
}

void external_interrupt_outA_RM_ISR(void){
  #ifdef BEBUG_ENCODERS
    uart_port.println("INTERRUPT: RIGHT MOTOR -A");
  #endif

   #ifndef NEGATE_RIGHT_COUNTER
    if (digitalRead(OUTA_RIGHT_M) == HIGH) {
      if (digitalRead(OUTB_RIGHT_M) == LOW) rightCount++;
      else                                  rightCount--;
    }else{
      if (digitalRead(OUTB_RIGHT_M) == LOW) rightCount--;
      else                                  rightCount++;
    }
  #else
    if (digitalRead(OUTA_RIGHT_M) == HIGH) {
      if (digitalRead(OUTB_RIGHT_M) == LOW) rightCount--;
      else                                  rightCount++;
    }else{
      if (digitalRead(OUTB_RIGHT_M) == LOW) rightCount++;
      else                                  rightCount--;
    }
  #endif
}
 
void external_interrupt_outB_RM_ISR(void){
  #ifdef BEBUG_ENCODERS
    uart_port.println("INTERRUPT: RIGHT MOTOR -B");
  #endif
}
