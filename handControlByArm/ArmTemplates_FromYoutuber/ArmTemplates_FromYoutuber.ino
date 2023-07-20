//Source Code from https://create.arduino.cc/editor/mertarduinotech/5d77b4bc-d24f-4f14-b887-fa08050e4baf/preview , video link:https://www.youtube.com/watch?v=D-6GDlvAMCI
#include <Servo.h>

//Threshold for servo motor control with muscle sensor. 
//You can set a threshold according to the maximum and minimum values of the muscle sensor.
//#define THRESHOLD 250
//#define THRESHOLD number
//Pin number where the sensor is connected. (Analog 0)
//#define EMG_PIN 0


//Define Servo motor
Servo thumb_Servo; //Control motors for thumb, the name rule will be used for code after
Servo indexfinger_Servo;
Servo middlefinger_Servo;
Servo ringfinger_Servo;
Servo littlefinger_Servo;
Servo SERVO_1;
/*-------------------------------- void setup ------------------------------------------------*/
int thresholdCounter=0;
int thresholdCounterTwice=0;
void setup(){
  
  //BAUDRATE set to 115200, remember it to set monitor serial properly. 
  //Used this Baud Rate and "NL&CR" option to visualize the values correctly.
  Serial.begin(115200);
  
  // thumb_Servo.attach(3);//ID for thumb to little finger in orders is 1 to 5. Set up the attach port (control cable), the port named in numbers
  // indexfinger_Servo.attach(5);
  // middlefinger_Servo.attach(6);
  // ringfinger_Servo.attach(9);
  // littlefinger_Servo.attach(10);
  SERVO_1.attach(3);
  //Set servo motor to digital pin 3
  
}

/*--------------------------------  void loop  ------------------------------------------------*/


void loop(){

  //The "Value" variable reads the value from the analog pin to which the sensor is connected.
  int value1 = analogRead(A1);
  
  //method 1
  
  int servoPos = 0; //stretch value
  int servoReturn = 10;
  int THRESHOLD = 340;
  
  Serial.println(value1);
  //If the sensor value is GREATER than the THRESHOLD, the servo motor will turn to 170 degrees.
  if(value1 > THRESHOLD){
 
  Serial.print(",");//Separate two EMG valuesS
  Serial.println(value1);
 
      for (servoPos = 180; servoPos>=0; servoPos +=1){
        SERVO_1.write(servoPos);
        Serial.print(",");//Separate two EMG valuesS
  Serial.println(value1);
        delay(10);
      }
     delay(10); 
  }
    //If the sensor is LESS than the THRESHOLD, the servo motor will turn to 10 degrees.
  else{
    SERVO_1.write(servoReturn);
    for (servoPos = 60; servoPos>=0; servoPos -=1){
        SERVO_1.write(servoPos);
        Serial.print(",");//Separate two EMG valuesS
  Serial.println(value1);
        delay(10);
      }
    delay(10);
  }
  delay(25);
}

