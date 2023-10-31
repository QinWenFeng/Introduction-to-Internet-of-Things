void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  String s = "";
  while(Serial.available()){
    s += (char)Serial.read();
  }
  if(s.length() != 0){
    Serial1.print(s);    
  }
}
