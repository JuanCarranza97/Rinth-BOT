#ifndef SENSORS_H
#define SENSORS_H
  #include "MedianFilter.h"
  #include "SharpDistSensor.h"


  //DEFINE SENSOR PIN AND MODEL
  #define LEFT_SENSOR_PIN                                A3
  #define LEFT_SENSOR_MODEL              GP2Y0A51SK0F_5V_DS
  
  #define CORNER_LEFT_SENSOR_PIN                         A2
  #define CORNER_LEFT_SENSOR_MODEL       GP2Y0A41SK0F_5V_DS
  
  #define CENTER_SENSOR_PIN                              A1
  #define CENTER_SENSOR_MODEL            GP2Y0A51SK0F_5V_DS
  
  #define CORNER_RIGHT_SENSOR_PIN                        A0
  #define CORNER_RIGHT_SENSOR_MODEL      GP2Y0A41SK0F_5V_DS
  
  #define RIGHT_SENSOR_PIN                                8
  #define RIGHT_SENSOR_MODEL             GP2Y0A51SK0F_5V_DS
  
  void setSensorModel(int port,int sensorModel);
  void configure_sensors(void);
  int read_sensor(int port);
#endif
