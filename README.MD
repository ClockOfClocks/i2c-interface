# Communication protocol

Between Raspberry Pi (Python) and Arduino

## Command
* calibration
* one motor move
* both motors move
* sleep

**Summary: 3 bits**

## Calibration
Data absence

**Summary: 0 bits**


## One motor  move

### Motor definition
0 – hour motor
1 – minute motor
1 bit

### Direction of rotation
Direction of motor: 0 – cw, 1 – ccw
1 bit

### Speed of rotation
Speed of hour and minute motors
2 bits (4 gradations)

### Angle of final position
2 bytes for the angle

**Summary: 4 bits + 2 bytes**


## Both motors move

### Direction of rotation
Direction of hour and minute motor: 0 – cw, 1 – ccw

1 bit for each motor

Summary: 2 bits

### Speed of rotation
Speed of hour and minute motors
2 bits (4 gradations) for each motor

### Angle of final position
2 times by 2 bytes consequently for each of motors

**Summary: 4 bits + 4 bytes**

## Sleep
This command means do nothing for some time

2 times by 2 bytes consequently for each of motors

**Summary: 4 bytes**
