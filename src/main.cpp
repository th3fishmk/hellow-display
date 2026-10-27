#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);
int count = 0;

void middle_finger()
{
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    for (;;)
      ;
  }

  display.clearDisplay();

  display.drawLine(0, 56, 127, 56, WHITE);
  for (int x = 0; x < 128; x += 12)
  {
    display.drawCircle(x + 6, 60, 6, WHITE);
  }

  display.fillRect(35, 42, 50, 10, WHITE);
  display.fillTriangle(85, 42, 85, 52, 100, 42, WHITE);
  display.fillTriangle(35, 42, 35, 52, 25, 42, WHITE);
  display.fillRect(58, 12, 3, 30, WHITE);
  display.fillTriangle(63, 15, 63, 38, 90, 38, WHITE);
  display.fillTriangle(56, 18, 56, 38, 38, 38, WHITE);
  display.fillTriangle(58, 12, 58, 17, 50, 14, WHITE);

  display.display();
}

void setup()
{

  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(921600);
  Serial.println("Hello from the setup");
}

void loop()
{
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  middle_finger();
  display.setCursor(30, 56);
  display.print("Ares puto x");
  display.println(count);
  display.display();

  Serial.println("Hello from the loop");
  Serial.println(count);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  count++;
}