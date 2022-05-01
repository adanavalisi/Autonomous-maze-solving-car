# Autonomous-maze-solving-car
A maze solving car by using Arduino UNO

This car can solve a maze and exit from maze. It is basically does it by following the right wall of the maze. That's why we use HCSR-04 sensors to measure distance between the car and the wall.

We need;
3 X HCSR-04 sensors
Arduino UNO
1 X 9V or 6 X 1.5V battery
l298N Motor Driver
2 X DC Motor

You can make the connection by using connection diagram (Will be uploaded after a while).

After you completed the connections upload the code to the arduino card. The most important thing after this step is setting your PWM values. Because every DC Motor has different power level. You can easily find the PWM values under "smart commands" title in code file.
