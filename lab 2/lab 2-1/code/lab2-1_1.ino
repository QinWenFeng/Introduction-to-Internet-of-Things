void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  String result;
  c = Serial.read();
  if()
  Serial1.println("AT+CAPPSKEY?");
  delay(1000);
  Serial1.println("AT+CNWKSKEY?");
  delay(1000);
  while(Serial1.available()){
    result+=(char)Serial1.read();    
  }
  Serial.print(result);
  delay(1000);
}
