const int analogPin=A0;
const int digitalPin=7;
const int redPin=13;
const int greenPin=12;
int Astate=0;
boolean Dstate=0;
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(digitalPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  Astate=analogRead(analogPin);
  Dstate=digitalRead(digitalPin);
  if(Dstate==LOW)
  {
    digitalWrite(greenPin,LOW);
    digitalWrite(redPin,HIGH);
  }
  else
  {
    digitalWrite(greenPin,HIGH);
    digitalWrite(redPin,LOW);
  }
}
