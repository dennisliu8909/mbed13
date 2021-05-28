#include "mbed.h"
#include "bbcar.h"

Ticker servo_ticker;
PwmOut pin5(D5), pin6(D6);

BBCar car(pin5, pin6, servo_ticker);

int main() {
   // please contruct you own calibration table with each servo
   double pwm_table0[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
   double speed_table0[] = {-12.835, -9.009, -12.437, -11.639, -6.537, 0.239, 6.537, 11.639, 12.437, 9.009, 12.835};
   double pwm_table1[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
   double speed_table1[] = {-12.835, -9.009, -12.437, -11.639, -6.537, 0.239, 6.537, 11.639, 12.437, 9.009, 12.835};

   // first and fourth argument : length of table
   car.setCalibTable(11, pwm_table0, speed_table0, 11, pwm_table1, speed_table1);

   while (1) {
      car.goStraightCalib(5);
      ThisThread::sleep_for(5s);
      car.stop();
      ThisThread::sleep_for(5s);
   }
}