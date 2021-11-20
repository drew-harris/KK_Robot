# Krusty Kannons Library Guide

### Constructor
```c++
new Robot( servoPin, triggerPin, echoPin, irPin, salinityServoPin );
```

# Movement
### Move in a direction
`robot->go(angle);`
Moves the robot in the specific direction with default speed 30. Other speeds might not move robot in a straight line.

`robot->go(angle, speed);`
Moves the robot in the specific direction. Other speeds beside 30 might not move robot in a straight line.

### Stop robot
`robot->stop();`

### Turn robot (WIP)
`robot->turnRobot(angle)`
Attempts to turn the robot by the angle. Ex. Entering 90 will turn the robot 90 degress to the right. 

### YEET
`robot->yeet();`
Omniwheel remake of the classic KNW method

# Navigation
### Turn navigation tower
`robot->turnNav(90);`
Turns tower to the specified angle

270/-90: Left, 0: Forward, 90: Right, etc..

## Get angle
`robot->getAngle();`
Returns the current angle of the robot
** NOTE: may not be the exact angle when the function is called because it takes time to turn the navigation. You are responsible for adding a delay. **

## Measure distance with ping sensor
`robot->measureDistance();`
Returns a double that represents the distance
** NOTE: The number is not in any specific unit. **

## Get IR Beacon letters
`robot->getLetters();`
Returns an array of characters


# Extra methods (WIP)
### Print to lcd
`robot->print( String text );`

### Pull up salinity plates
`robot->pullUpSalinity();`

### Drop salinity plates
`robot->dropSalinity();`

### Get salinity measurement
`robot->getSalinity();`
Returns an integer that is the percent
