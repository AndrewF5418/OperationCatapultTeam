int EMGvalue;//initialize EMGvalue for store the value/readings for EMG
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);//setup the baude 
}

void loop() {
  // put your main code here, to run repeatedly:
  //continously read the value, put detect statement in a loop
  EMGvalue = analogRead(A0);//plug the transmission cable from blue board with detector cables to the A0 port of the board above the arduino board(UNO,normally) 
  //continously read the value to the variable EMGvalue
  delay(10);// 10 ms delays, 1s = 1000ms
  //then check the serial plotter

}

