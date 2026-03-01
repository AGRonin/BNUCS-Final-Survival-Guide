const int analogPin1=A0;
const int analogPin2=A1;
const int digitalPin1=7;
const int digitalPin2=8;
const int redPin=13;
const int greenPin=12;
const int bluePin=11;
int Astate1=0;
int Astate2=0;
boolean Dstate1=0;
boolean Dstate2=0;
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(digitalPin1, INPUT);
  pinMode(digitalPin2, INPUT);
  Serial.begin(9600);
}

void loop() {
  Astate1=analogRead(analogPin1);
  Astate2=analogRead(analogPin2);
  Dstate1=digitalRead(digitalPin1);
  Dstate2=digitalRead(digitalPin2);
  if(Dstate1==LOW && Dstate2==LOW)
  {
    digitalWrite(greenPin,LOW);
    digitalWrite(bluePin,LOW);
    digitalWrite(redPin,HIGH);
  }
  else if(Dstate1==HIGH && Dstate2==HIGH)
  {
    digitalWrite(greenPin,HIGH);
    digitalWrite(bluePin,LOW);
    digitalWrite(redPin,LOW);
  }
  else
  {
    digitalWrite(greenPin,LOW);
    digitalWrite(bluePin,HIGH);
    digitalWrite(redPin,LOW);
  }
}
