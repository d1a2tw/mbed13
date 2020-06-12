#include "mbed.h"
#include "bbcar.h"

Ticker servo_ticker;
PwmOut pin8(D8), pin9(D9);

BBCar car(pin8, pin9, servo_ticker);

int main() {
    // please contruct you own calibration table with each servo
    double pwm_table0[] = {150, 120, 90, 60, 30, 0, -30, -60, -90, -120, -150};
    double speed_table0[] = {16.827, 16.629, 15.232, 12.202, 5.662, 0.000, -6.699, -12.202, -15.232, -16.428, -16.827};
    double pwm_table1[] = {150, 120, 90, 60, 30, 0, -30, -60, -90, -120, -150};
    double speed_table1[] = {15.551, 15.392, 14.434, 12.122, 6.539, 0.000, -4.625, -9.809, -12.122, -13.797, -14.036};

    // first and fourth argument : length of table
    car.setCalibTable(11, pwm_table0, speed_table0, 11, pwm_table1, speed_table1);

    while (1) {
        car.goStraightCalib(5);
        wait(5);
        car.stop();
        wait(5);
    }
}