#include <Stepper.h>
#include<Servo.h>
int servo=12;
Servo pointer;


int button=2;
int buttonstate=0;

const int stepsPerRevolution = 64; 
const int stepsPerRevolution2 = 64; 

//===========================lower-arm===============================
Stepper small_stepper1(stepsPerRevolution, 8,9,10,11);  
Stepper small_stepper2(stepsPerRevolution, 4,5,6,7); 
//===================upper-arm=========================================
Stepper small_stepper3(stepsPerRevolution2, 30,31,32,33); 

//===========================================================function button=============================================================================================

void Readbutton()
   {
  buttonstate=digitalRead(button);
 
 if(buttonstate==HIGH)
 {
  pointer.write(180);
  Serial.println("HIGH");
  
 }
 else
{
  pointer.write(0);
  Serial.println("LOW");
  
} 
}

void setup() {
  
 small_stepper1.setSpeed(260);    // set stepper speed
 small_stepper2.setSpeed(260);  // set stepper speed
 small_stepper3.setSpeed(260);
 pointer.attach(servo); 
 pinMode(button,INPUT_PULLUP);
 

}


void loop() {
 
  int sensorReading = analogRead(A0);// read value from joystick X-axis
  int sensorReading2 = analogRead(A1);//read value from joystick Y-axis

//----------------------------lower-arm-----------------------------
  if (sensorReading < 400) { small_stepper1.step(1); }   // step left
  if (sensorReading >400 && sensorReading<600) { small_stepper1.step(0); }   // stop
  if (sensorReading > 600) { small_stepper1.step(-1); }  // step right

  if (sensorReading < 400) { small_stepper2.step(1); }   // step left
  if (sensorReading >400 && sensorReading<600) { small_stepper2.step(0); }   // stop
  if (sensorReading > 600) { small_stepper2.step(-1); }  // step right

//---------------------------upper-arm-------------------------------------------------  
    

  if (sensorReading2 < 400) { small_stepper3.step(1); }   // step left
  if (sensorReading2 >400 && sensorReading2<600) { small_stepper3.step(0); }   // stop
  if (sensorReading2 > 600) { small_stepper3.step(-1); }  // step right



//-------------------------------------button-gripper---------------------------------------------------------

Readbutton();
   
}
