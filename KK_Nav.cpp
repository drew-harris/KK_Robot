#include "Arduino.h"
#include <Servo.h>
#include "KK_Nav.h"
#include "./infraredsensor.h"

int DEGREE_DELAY = 273;

Navigation::Navigation(int servoPin, int echoPin, int trigPin, int irPin) {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  _servoPin = servoPin;
  _trigPin = trigPin;
  _echoPin = echoPin;
  _irPin = irPin;
  navServo.attach(_servoPin);

}

// Add a delay after in the main code
void Navigation::turnNav(int angle) {
  if (angle > 180) {
    angle -= 360;
  }
  angle = map(angle, 90, -90, 0, 180);
  navServo.write(angle);
  _angle = angle;
}

void swap(double *a, double *b) {
  double temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(double array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {
      if (array[i] < array[min_idx])
        min_idx = i;
    }
    swap(&array[min_idx], &array[step]);
  }
}

// Hope this works
double median(double arr[], int size){
  selectionSort(arr, 5);
  if (size % 2 != 0)
    return (double)arr[size/2];
  return (double)(arr[(size-1)/2] + arr[size/2])/2.0;
}


double Navigation::measureDistance() {
  double distances[5];
  for (int i = 0; i < 5; ++i) {
    distances[i] = measureDistanceOnce();
    delay(30);
  }
  return median(distances, 5);

}

double Navigation::measureDistanceOnce() {
  long duration; // variable for the duration of sound wave travel
  double distance; // variable for the distance measurement
  digitalWrite(_trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(_echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  return duration;
}

// TODO: Check this before merge
char* Navigation::getLetters() {
  int numCharsReadFromIR = scanIR(_irPin);
  char* characters = getIR();

  return characters;
}


int Navigation::getAngle() {
  return _angle;
}

