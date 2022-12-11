#include <SPI.h>
#include <mcp2515.h>
#define led 8
struct can_frame canMsg;
MCP2515 mcp2515(10);


void setup() {
  mcp2515.reset();
  mcp2515.setBitrate(CAN_125KBPS);
  mcp2515.setNormalMode();
 
  pinMode(led, OUTPUT);
}

void loop() {
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) {
    if(canMsg.data[0]){
      digitalWrite(led,HIGH);
    }
    else{
      digitalWrite(led,LOW);
    }  
  }
}
