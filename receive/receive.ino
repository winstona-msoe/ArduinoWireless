#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8);
const byte rxAddr[6] = "00001";
void setup()
{
  while (!Serial);
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  radio.begin();
  radio.setChannel(1);
  radio.openReadingPipe(0, rxAddr);
  radio.startListening();
}

void loop()
{
  if (radio.available())
  {
    bool sample;
    radio.read(&sample, sizeof(sample));
    digitalWrite(9, sample);
   // Serial.println(text);
  }
}  


