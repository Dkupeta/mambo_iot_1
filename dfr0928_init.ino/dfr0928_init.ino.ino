//#include <DFRobot_Type.h>
//#include <DFRobot_UI.h>
#include <DFRobot_GDL.h>
//#include <DFRobot_Gesture.h>
//#include <DFRobot_Picdecoder_SD.h>
//#include <graphic.h>
//#include <DFRobot_Touch.h>

/*M0*/
#if defined ARDUINO_SAM_ZERO
#define TFT_DC  7
#define TFT_CS  5
#define TFT_RST 6
/*ESP32 ESP8266*/
#elif defined(ESP32)
#define TFT_DC  D2
#define TFT_CS  D6
#define TFT_RST D3
/*ESP8266*/
#elif defined(ESP8266)
#define TFT_DC  D4
#define TFT_CS  D6
#define TFT_RST D5
/* AVR series mainboard */
#else
#define TFT_DC  2
#define TFT_CS  3
#define TFT_RST 4
#endif

DFRobot_ST7735_128x160_HW_SPI screen(/*dc=*/TFT_DC, /*cs=*/TFT_CS, /*rst=*/TFT_RST);

void setup() {
  Serial.begin(115200);
  screen.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

}
