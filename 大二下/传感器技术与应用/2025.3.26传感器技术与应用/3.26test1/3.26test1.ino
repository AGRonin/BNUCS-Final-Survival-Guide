#include <IRremote.h>
const int irReceiverPin=8;//the SIG of receiver module attach to pin7
const int ledPin=10;//pin 13 built-in led
IRrecv irreev(irReceiverPin);//Creates a variable of type IRrecv
decode_results results;
void setup ()
{
  pinMode(ledPin,OUTPUT);//set ledpin as OUTPUT
  Serial.begin (9600);//initialize serial
  irreev.enableIRIn(); //enable ir receiver module
}
void loop()
{
  if(irreev.decode(&results))
  { 
  Serial.print("irCode: "); //print" irCode: "
  Serial.print(results.value,HEX); //print the value in hexdecimal
  Serial.print(", bits: "); //print"
  Serial.println(results. bits);
  irreev.resume();
  }
  delay(600);
  if(results.value==0xFFE21D)
  digitalWrite(ledPin,HIGH); //turn on the led
  else
  digitalWrite(ledPin, LOW);//turn off the led
}