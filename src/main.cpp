#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);
int count = 0;

void middle_finger()
{
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    // Try 0x3D if 0x3C doesn't work
    for (;;)
      ;
  }

  display.clearDisplay();

  display.fillRoundRect(44, 32, 40, 22, 4, WHITE);
  display.fillRoundRect(58, 6, 12, 28, 4, WHITE);
  display.fillRoundRect(46, 22, 10, 12, 3, WHITE); // Index finger
  display.fillRoundRect(72, 22, 10, 12, 3, WHITE); // Ring finger
  display.fillRoundRect(82, 26, 6, 10, 2, WHITE);  // Pinky finger
  display.fillRoundRect(36, 38, 10, 12, 4, WHITE);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  // display.display();
}

void setup()
{

  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(921600);
  Serial.println("Hello from the setup");
}

void loop()
{
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);
  middle_finger();
  display.setCursor(30, 56);
  display.print("Hellow x");
  display.println(count);
  display.display();
  Serial.println("Hello from the loop");
  count++;
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
}