void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  String s;
  char c;
  while(Serial.available()){
    c = Serial.read();
    if((int)c > 96 && (int)c < 123){
      s+=(char)((int)c - 32);      
    }
  }
  Serial.print(s);
}
