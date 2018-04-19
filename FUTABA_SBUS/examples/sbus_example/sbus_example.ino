#include <FUTABA_SBUS.h>
#include <SoftwareSerial.h>

//Connect SBUS To pin 10

SoftwareSerial mySerial(10, 11); // RX, TX

FUTABA_SBUS sBus;


void setup(){
  sBus.begin();
  Serial.begin(115200);
}

void loop(){
  sBus.FeedLine();
  if (sBus.toChannels == 1){
    sBus.UpdateServos();
    sBus.UpdateChannels();
    sBus.toChannels = 0;
    Serial.println(sBus.channels[0]);
  }
}
