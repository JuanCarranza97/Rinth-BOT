#include "Boca_IrSensors.h"

SharpDistSensor left_sensor(LEFT_SENSOR_PIN,5);
SharpDistSensor corner_left_sensor(CORNER_LEFT_SENSOR_PIN,5);
SharpDistSensor center_sensor(CENTER_SENSOR_PIN,5);
SharpDistSensor corner_right_sensor(CORNER_RIGHT_SENSOR_PIN,5);
SharpDistSensor right_sensor(RIGHT_SENSOR_PIN,5);

void setSensorModel(int port,int sensorModel){
  SharpDistSensor::models model_sensor = SharpDistSensor::GP2Y0A51SK0F_5V_DS;

  switch (sensorModel)
  {
  default:
  case 0:
    model_sensor = SharpDistSensor::GP2Y0A60SZLF_5V;
    break;
  case 1:
    model_sensor = SharpDistSensor::GP2Y0A710K0F_5V_DS;
    break;
  case 2:
    model_sensor = SharpDistSensor::GP2Y0A51SK0F_5V_DS;
    break;
  case 3:
    model_sensor = SharpDistSensor::GP2Y0A41SK0F_5V_DS;
    break;
  }
  

  switch (port){
    default:
    case 0:
      left_sensor.setModel(model_sensor);
      break;
    case 1:
      corner_left_sensor.setModel(model_sensor);
      break;
    case 2:
      center_sensor.setModel(model_sensor);
      break;
    case 3:
      corner_right_sensor.setModel(model_sensor);
      break;
    case 4:
      right_sensor.setModel(model_sensor);
      break;
  }
}

void configure_sensors(void){
  left_sensor.setModel(SharpDistSensor::LEFT_SENSOR_MODEL);
  corner_left_sensor.setModel(SharpDistSensor::CORNER_LEFT_SENSOR_MODEL);
  center_sensor.setModel(SharpDistSensor::CENTER_SENSOR_MODEL);
  corner_right_sensor.setModel(SharpDistSensor::CORNER_RIGHT_SENSOR_MODEL);
  right_sensor.setModel(SharpDistSensor::RIGHT_SENSOR_MODEL);
}

int read_sensor(int port){ 
  switch (port){
    default:
    case 0:
      return left_sensor.getDist();
      break;
    case 1:
      return corner_left_sensor.getDist();
      break;
    case 2:
      return center_sensor.getDist();
      break;
    case 3:
      return corner_right_sensor.getDist();
      break;
    case 4:
      return right_sensor.getDist();
      break;
  }
}
