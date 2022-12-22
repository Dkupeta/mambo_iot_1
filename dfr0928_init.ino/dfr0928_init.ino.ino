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
  testLine();
  testFastLines(COLOR_RGB565_PURPLE, COLOR_RGB565_YELLOW);
  testRects(COLOR_RGB565_BLACK, COLOR_RGB565_WHITE);
  testRoundRects();
  testCircles(24, COLOR_RGB565_BLUE);
  testTriangles(COLOR_RGB565_YELLOW);
  testPrint();
}

void testLine()
{}

void testFastLines()
{}

void testRects()
{}

void testRoundRects()
{}

void testCircles()
{}

void testTriangles(uint16_t color)
  {
    screen.fillScreen(COLOR_RGB565_BLACK);

    for (int16_t i=0; i <=screen.width(); i+=24)
      screen.drawTriangle(/*x0=*/i,/*y0=*/0,/*x1=*/0,/*y1=*/screen.height()-i,/*x2=*/screen.width()-i,/*y2=*/screen.height(), /*color=*/color);
  
    for (int16_t i=0; i <screen.width(); i+=24)
      screen.drawTriangle(screen.width(),i*4/3,0,screen.height()-i*4/3,i,0, color);
  
    for (int16_t i=0; i <screen.width(); i+=24)
      screen.drawTriangle(screen.width(),i*4/3,i,0,screen.width()-i,screen.height(), color);
  
    color = COLOR_RGB565_RED;
    for (int16_t i=0; i <=screen.width(); i+=24)
      screen.fillTriangle(/*x0=*/i,/*y0=*/0,/*x1=*/0,/*y1=*/screen.height()-i,/*x2=*/screen.width()-i,/*y2=*/screen.height(), /*color=*/color+=100);
  
    for (int16_t i=0; i <screen.width(); i+=24)
      screen.fillTriangle(screen.width(),i*4/3,0,screen.height()-i*4/3,i,0, color+=100);
  
    for (int16_t i=0; i <screen.width(); i+=24)
      screen.fillTriangle(screen.width(),i*4/3,i,0,screen.width()-i,screen.height(), color+=100);

  }

void testPrint()
  {
    int16_t color = 0x00ff;
    screen.setTextWrap(false);
    screen.fillScreen(COLOR_RGB565_BLACK);

    screen.setCursor(0, 50);
    screen.setTextColor(color+=0x3000);
    screen.setTextSize(0);
    screen.println("Hello apo");

    screen.setTextColor(color+=0x3000);
    screen.setTextSize(1);
    screen.println("Hello apo1");

    screen.setTextColor(color+=0x3000);
    screen.setTextSize(2);
    screen.println("Hello apo2");

    screen.setTextColor(color+=0x3000);
    screen.setTextSize(3);
    screen.println("Hello apo3");
    
    screen.setTextColor(color+=0x3000);
    screen.setTextSize(4);
    screen.println("Hello apo4");

    screen.setTextColor(color+=0x3000);
    screen.setTextSize(5);
    screen.println("Hello apo5");
    delay(2000);

    screen.setCursor(0,0);
    screen.fillScreen(COLOR_RGB565_BLACK);
    screen.setTextColor(color+=0x3000);
    screen.setTextSize(2);
    screen.println("a = ");

    screen.setTextColor(color+=0x3000);
    int a = 1234;
    screen.println(a, 1);
    screen.setTextColor(color+=0x3000);
    screen.print(8675309, HEX);
    screen.println("this is HEX!");
    screen.println("");
  
    screen.setTextColor(color+=0x0F00);
    screen.println("running for: ");
    screen.setTextColor(color+=0x0F00);
    screen.print(millis());
    screen.setTextColor(color+=0x0F00);
    screen.println("/1000 seconds.");
  
    char text[] = "Hi Mambo!";
    screen.setTextColor(color+=0x0F00);
    screen.setTextWrap(true);
    screen.setTextSize(3);
    screen.println(text);
    screen.println(text);
    delay(2000);
    
  }
