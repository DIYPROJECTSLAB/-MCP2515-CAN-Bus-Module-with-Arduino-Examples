//diyprojectslab.com

#include <SPI.h>
#include <mcp2515.h>
#define btn 8

struct can_frame canMsg1;

MCP2515 mcp2515(10);
bool state = 0;
void setup() {
  canMsg1.can_id  = 0x01;
  canMsg1.can_dlc = 1;
  canMsg1.data[0] = 0x00;

  mcp2515.reset();
  mcp2515.setBitrate(CAN_125KBPS);
  mcp2515.setNormalMode();

  pinMode(btn, INPUT_PULLUP);
}

void loop() {
  if (!digitalRead(btn)) {
    //antirebote
    while (!digitalRead(btn)) {
    delay(10);
    }
    
    state = !state;
    
    if (state) {
    canMsg1.data[0] = 0x01;
    }
    else {
      canMsg1.data[0] = 0x00;
    }
   
    mcp2515.sendMessage(&canMsg1);
  }

}
