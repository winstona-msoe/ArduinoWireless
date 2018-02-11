#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <inttypes.h>

RF24 radio(7, 8);

const char channel = 1;
const byte rxAddr[6] = "00001";
bool sample = LOW;

void setup()
{
  radio.begin();
  radio.setChannel(channel);
  radio.setRetries(15, 15);
  radio.setDataRate(RF24_1MBPS);
  radio.openWritingPipe(rxAddr);
  Serial.begin(9600);
  
  radio.stopListening();
}

void loop()
{
  sample = !sample;
  radio.write(&sample, sizeof(sample));
  Serial.write("I transmitted stuff!\n");
  delay(1);
}
