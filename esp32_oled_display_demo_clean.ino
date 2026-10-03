#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define OLED_ADDR 0x3C

#define SDA_PIN 21
#define SCL_PIN 22

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void showText() {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("ESP32 OLED");

  display.setTextSize(2);
  display.setCursor(0, 12);
  display.println("PRIYANSHU");

  display.display();
}

void showAnimation() {
  for (int x = 0; x <= 112; x += 8) {
    display.clearDisplay();

    display.drawRect(x, 4, 12, 12, SSD1306_WHITE);

    display.drawRect(4, 23, 120, 7, SSD1306_WHITE);
    display.fillRect(6, 25, x + 2, 3, SSD1306_WHITE);

    display.display();
    delay(80);
  }
}

void setup() {
  Serial.begin(115200);

  Wire.begin(SDA_PIN, SCL_PIN);

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println("OLED initialization failed!");
    while (true) {
      delay(1000);
    }
  }

  display.clearDisplay();
  display.display();

  showText();
  delay(2000);
}

void loop() {
  showAnimation();
  delay(500);

  showText();
  delay(1500);
}
