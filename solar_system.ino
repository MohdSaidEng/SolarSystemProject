/*   
 *   Basic example code for controlling a stepper with the AccelStepper library
 *      
 *   by Dejan, https://howtomechatronics.com
 */

#include <AccelStepper.h>
//int spd=1000;

int sg=14;
int bg=325;

double r=bg/sg;

int sg_full_rotation = 3200;  //steps
double bg_full_rotation = sg_full_rotation * r;

double Mspd=600;
int Maccl=30;

// Define the stepper motor and the pins that is connected to
AccelStepper stepper1(1, 2, 3 ); // (Type of driver: with 2 pins, STEP, DIR)
AccelStepper stepper2(1, 4, 5 );
void setup() {
  delay(3000);
  // Set maximum speed value for the stepper
  stepper1.setMaxSpeed(Mspd);
  //stepper1.setSpeed(spd);
  stepper2.setMaxSpeed(Mspd);
  stepper1.setAcceleration(Maccl);
  stepper2.setAcceleration(Maccl);
  
}

void loop() {
  stepper1.moveTo(bg_full_rotation);
  stepper2.moveTo(bg_full_rotation);

  // Step the motor with a constant speed previously set by setSpeed();
  stepper1.run(); 
  stepper2.run();
}
