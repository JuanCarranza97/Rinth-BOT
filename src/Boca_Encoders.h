#ifndef ENCODER_H
#define ENCODER_H
  
  #include <Arduino.h>
    
  #define OUTA_LEFT_M      1
  #define OUTB_LEFT_M      0
  #define OUTA_RIGHT_M     3
  #define OUTB_RIGHT_M     2

  //#define NEGATE_LEFT_COUNTER 
  #define NEGATE_RIGHT_COUNTER
  
  //#define BEBUG_ENCODERS

  #define CHECK_TIME_MS 20
  
  void initialize_encoders(void);
  int get_encoder_count(int enc);
  int get_RPM(int enc);
  void check_rpm(void);
  
  void external_interrupt_outA_LM_ISR(void);
  void external_interrupt_outB_LM_ISR(void);
  void external_interrupt_outA_RM_ISR(void);
  void external_interrupt_outB_RM_ISR(void);

#endif
