#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display1(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_SSD1306 display2(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Master drawing function that handles eye positions and open/closed states independently
void drawEyes(int pupilX1, int pupilX2, bool leftOpen, bool rightOpen)
{

    // --- Display 1 (0x3D) - Left Eye ---
    display1.clearDisplay();
    if (leftOpen)
    {
        display1.fillRoundRect(24, 6, 80, 52, 16, WHITE);
        display1.fillRoundRect(pupilX1, 14, 24, 36, 8, BLACK);
    }
    else
    {
        display1.fillRect(24, 30, 80, 4, WHITE);
    }
    display1.display();

    // --- Display 2 (0x3C) - Right Eye ---
    display2.clearDisplay();
    if (rightOpen)
    {
        display2.fillRoundRect(24, 12, 80, 46, 14, WHITE);
        display2.fillRoundRect(pupilX2, 19, 20, 32, 6, BLACK);
        display2.drawLine(24, 4, 104, 8, WHITE);
    }
    else
    {
        display2.fillRect(24, 30, 80, 4, WHITE);
        display2.drawLine(24, 4, 104, 8, WHITE);
    }
    display2.display();
}

void setup()
{
    if (!display1.begin(SSD1306_SWITCHCAPVCC, 0x3D))
    {
        for (;;)
            ;
    }

    if (!display2.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        for (;;)
            ;
    }

    display1.clearDisplay();
    display2.clearDisplay();
}

void loop()
{
    drawEyes(54, 54, true, true);
    delay(3000);

    drawEyes(54, 54, false, false);
    delay(200);
    drawEyes(54, 54, true, true);
    delay(2000);

    drawEyes(54, 54, false, true);
    delay(100);

    drawEyes(54, 54, true, false);
    delay(100);

    drawEyes(54, 54, true, true);
    delay(1000);

    drawEyes(30, 70, true, true);
    delay(1000);

    drawEyes(54, 54, true, true);
    delay(2500);

    drawEyes(54, 54, false, true);
    delay(200);

    drawEyes(54, 54, true, true);
    delay(2000);

    drawEyes(70, 70, true, true);
    delay(1000);

    drawEyes(54, 54, true, true);
    delay(2000);

    drawEyes(70, 70, true, true);
    delay(1000);
}
