void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
}

String c;
void loop() {
  // put your main code here, to run repeatedly:
  String result;
  while(Serial.available()){
    c += (char)Serial.read();  
    if(c.length() != 0){
      Serial1.println("AT+CPT=\"TXPP,1,0100,925.000,20,2,5,1,0,1,0,0035,1234\"");
    }
  }
  delay(1000);
  while(Serial1.available()){
    result+=(char)Serial1.read();    
  }
  Serial.print(result);
  delay(1000);
}
