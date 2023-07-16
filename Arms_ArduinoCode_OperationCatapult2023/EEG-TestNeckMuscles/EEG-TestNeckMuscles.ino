





int EMGvalueLeft;//initialize EMGvalue for store the value/readings for EMG
int EMGvalueRight;//Muscle 1 and muscle 2
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);//setup the baude 
}

void loop() {
  // put your main code here, to run repeatedly:
  //continously read the value, put detect statement in a loop
  EMGvalueLeft = analogRead(A0);//BLUE LEFT is A0
  EMGvalueRight = analogRead(A2);//ORGANE RIGHT is A2
  Serial.print(EMGvalueLeft);
  Serial.print(",");//Separate two EMG valuesS
  Serial.println(EMGvalueRight);
  //EMGvalueM2 = analogRead(A1);//plug the transmission cable from blue board with detector cables to the A0 port of the board above the arduino board(UNO,normally) 
  //continously read the value to the variable EMGvalue
  delay(10);
  // 1ms delays, 1s = 1000ms
  //then check the serial plotter

}

