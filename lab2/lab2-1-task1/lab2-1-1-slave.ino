// this is to receive command from Serail.read, instead of directly transmitting commnad
// command for slave: 
// AT+CPT="TXPP,0,0010,925.000,00,2,5,1,0,1,0,0100,1234"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
  
}

int time =0;

void reset(){
  Serial1.println("ATZ");
  Serial.println("board reseted"); 
}

void loop() {
  if(time ==0){
    reset();
  }
  time++;
  String cmd;
  
  while(Serial.available()){
    cmd+=(char)Serial.read();
  }

  
  if(cmd.length() !=0){
    Serial1.println(cmd);
    Serial.println("command transmitted:" +cmd);
  }
  
  delay(1000);
  String result;
  
  //Serial1.println("AT+CPT=\"TXPP,0,0010,925.000,00,2,5,1,0,1,0,0100,1234\"");
  // not sending cmd directly
  
  
  while(Serial1.available()){
    result+=(char)Serial1.read();
  }
  Serial.println(result); 
  delay(1000);



}
