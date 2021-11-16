
#ifndef KK_Robot_h
#define KK_Robot_h

#include "Arduino.h"
#include "./KK_Nav.h"
#include "./KK_Movement.h"
#include ".conductivitynew.h"
#include <Servo.h>

class Robot : public OmniMove, public Navigation {
  public: 
    Robot(int servoPin, int trigPin, int echoPin, int irPin, int salinityServoPin): Navigation( servoPin, trigPin, echoPin, irPin) {
      pinMode(salinityServoPin, OUTPUT);
      salinityMotor.attach(salinityServoPin);

    };

    void pullUpSalinity() {
      salinityMotor.write(80);
      delay(1000);
      salinityMotor.write(90);
    }

    void dropSalinity() {
      salinityMotor.write(180);
      delay(1000);
    }

    int getSalinity() {
      double slope = 12.884;
      double intercept = 172.341;
      adc = getConductivity();
      salinity = slope / (adc - intercept);

      return salinity;

    }

  private:
    Servo salinityMotor;
};

#endif
