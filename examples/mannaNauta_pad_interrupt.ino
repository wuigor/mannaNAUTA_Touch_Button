/*
 * mannaNAUTA Hand Touch BT 
 * MCU: ESP32-S3
 * Author	mannaNAUTA
 * Company	mannaTEAM
 * Date		21/02/2024
 *
 *********************************
 *   T7 = GPIO7 = Left hand     **
 *   T6 = GPIO6 = Left right    **
 *   Default Threshold = 40     **
 *********************************
 *
*/

int   threshold          = 40;
bool  HandLeftDetected   = false;
bool  HandRightDetected  = false;

void goHandLeft() {
  HandLeftDetected = true;
}

void goHandRight() {
 HandRightDetected = true;
}


void setup() {

  Serial.begin(115200);
  touchAttachInterrupt(T7, goHandLeft, threshold);
  touchAttachInterrupt(T6, goHandRight, threshold);
  
}

void loop() {
  
  if(HandLeftDetected){
    HandLeftDetected = false;
    Serial.println("Left hand detected.");
  }

  if(HandRightDetected){
    HandRightDetected = false;
    Serial.println("Right hand detected.");
  }

}
