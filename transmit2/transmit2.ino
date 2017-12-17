#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <inttypes.h>

RF24 radio(7, 8);

const byte channel = 2;
const byte rxAddr[6] = "00001";
bool sample = LOW;

void setup()
{
  radio.begin();
  radio.setChannel(channel);
  radio.setRetries(15, 15);
  radio.openWritingPipe(rxAddr);
  
  radio.stopListening();
}

void loop()
{
  sample = !sample;
  radio.write(&sample, sizeof(sample));
  delay(1);
}
