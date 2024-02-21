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

void setup() {
  Serial.begin(115200);
  Serial.println("mannaNAUTA Touch Button");
}

void loop() {

  Serial.print("Reading the left touch hand: ");
  Serial.println(touchRead(T7));

  Serial.print("Reading the right touch hand: ");
  Serial.println(touchRead(T6));

  delay(1000);

}