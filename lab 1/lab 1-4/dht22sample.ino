#include <DHT22_lab.h>
//define pin data
#define pinDATA 2 

DHT22 dht22(pinDATA); 

float DHT22::getHumidity(){
  bool valid = dht22.readFromSensor();//read data and return whether read success or not
  if(!valid)return 0;
  
  uint64_t rawData = dht22.getRawData();
  String rawStr = dht22.getRawStrData();
  //finish the following code to parse the raw byte data of humidity to float
  int16_t Humidity = (rawData >> 24) / 10.0;
  return Humidity;
}

float DHT22::getTemperature(){
  bool valid = dht22.readFromSensor();//read data and return whether read success or not
  if(!valid)return 0;
  
  uint64_t rawData = dht22.getRawData();
  String rawStr = dht22.getRawStrData();
  //finish the following code to parse the raw byte data of humidity to float
  rawData = (rawData << 40);
  uint16_t Temperature = (rawData >> 48) / 10.0;
  return Temperature;
}

 
void setup() {
  Serial.begin(9600); 
}

void loop() {

  float t = dht22.getTemperature();
  float h = dht22.getHumidity();

  if (dht22.getLastError() != dht22.OK) 
    Serial.println(dht22.getLastError());

  Serial.print("h=");Serial.print(h,1);Serial.print("\t");
  Serial.print("t=");Serial.println(t,1);
  delay(1000);
}
