#include <Servo.h>
  Servo myservo;
  Servo myservo2;
  int pos = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9);
  myservo2.attach(6);
  pinMode(3, INPUT); //Set port 3 as the input


}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(3)+"\n");
  if (digitalRead(3) == HIGH) {// if port 3 read of voltage is high
    for (pos = 0; pos <=180; pos+=1){ // for (0,180,1)
      myservo.write(pos);
      myservo2.write(pos);
      delay(15); // 15 interval, unit is ms
    
    }
    for (pos = 180; pos>=0; pos -=1){ // for (180,0,-1)
      myservo.write(pos);
      myservo2.write(pos);
      delay(15);// unit is ms
    }
  }

}
