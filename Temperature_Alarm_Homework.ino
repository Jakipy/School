float sinVal;
float toneVal;
unsigned long tepTimer;
int led = 13;
void setup() {
 pinMode(8,OUTPUT);
 Serial.begin(9600);
 pinMode(13,OUTPUT);
 
}

void loop() {
  int range_one = 10;
  int range_two = 20;
  
  int val;
  double data;
  val = analogRead(0);
  data = (double)val* (5/10.24);
  if(data >= range_one && data <= range_two){
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);                       // wait for a second
  }
  if(data>27){
    for(int x = 0; x < 180; x++){
      sinVal = (sin(x*(3.1412/180)));
      toneVal = 2000+(int(sinVal*1000));
      tone(8,toneVal);
      delay(2);
    }
  }
  else{
    noTone(8);
    
  }
  if(millis() - tepTimer > 50){
    tepTimer = millis();
    Serial.print("temperature: ");
    Serial.print(data);
    Serial.println("C");
  }

}
