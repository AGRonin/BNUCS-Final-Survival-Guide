const int digitalPin=7;
int analogPin=A0;
const int redPin=13;
const int greenPin=12;
boolean Dstate=0;
int Astate=0;
void setup() {
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(digitalPin,INPUT);
  pinMode(analogPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  Astate=analogRead(analogPin);
  Dstate=digitalRead(digitalPin);
  Serial.print("D0:");
  Serial.println(Dstate);
  Serial.print("A0:");
  Serial.println(Astate);
  if(Dstate==LOW)
  {
    digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,LOW);
  }
  else
  {
    digitalWrite(redPin,LOW);
    digitalWrite(greenPin,HIGH);
  }
}
