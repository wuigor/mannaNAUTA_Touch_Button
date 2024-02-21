# mannaNAUTA Touch Button (hand)

Examples of how to use the touch buttons on the mannaNAUTA board with ESP32-S3.

## Features
* Read touch button from the left and right hand.
* Detect change in the state of the touch button from the left and right hand.

Based on the example program "Touch Sensor V2" in IDF-SDK. </br>
The source code repository is here:

https://github.com/espressif/esp-idf/tree/master/examples/peripherals/touch_sensor

## Examples:
* Touch Pad Read Example

```C
/*
*   T7 = GPIO7 = Left hand
*   T6 = GPIO6 = Left right
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
```

* Touch Pad Interrupt Example
```C
/*
*   T7 = GPIO7 = Left hand
*   T6 = GPIO6 = Left right
*   Default Threshold = 40
*/

int   threshold          = 40;
bool  HandLeftDetected   = false;
bool  HandRightDetected  = false;

// Interrupt Hand Left
void goHandLeft() {
  HandLeftDetected = true;
}

// Interrupt Hand Righ
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
```

## Usage

* Function to read the touch pad
```C
touchRead(uint8_t pin);
```

* Function to set the interrupt

uint8_t pin             -> PAD TOUCH (GPIO).</br>
void (*userFunc)(void)  -> Function to be called when the interrupt is generated.</br>
touch_value_t threshold -> Limit set to generate the interaction.</br>
```C
touchAttachInterrupt(uint8_t pin, void (*userFunc)(void), touch_value_t threshold);
```


