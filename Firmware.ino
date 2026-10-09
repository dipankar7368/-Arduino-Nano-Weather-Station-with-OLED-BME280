
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// 0.91-inch OLED: 128 x 32 pixels
#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT 32
#define OLED_RESET    -1
#define OLED_ADDRESS  0x3C

Adafruit_SSD1306 display(
  SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET
);

Adafruit_BME280 bme;

bool oledOK = false;
bool bmeOK = false;

void showMessage(const __FlashStringHelper *msg) {
  if (!oledOK) return;

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 12);
  display.println(msg);
  display.display();
}

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // Initialize OLED
  oledOK = display.begin(
    SSD1306_SWITCHCAPVCC, OLED_ADDRESS
  );

  if (oledOK) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println(F("Environment Monitor"));
    display.println(F("Starting sensor..."));
    display.display();
  } else {
    Serial.println(F("OLED not found at 0x3C"));
  }

  // Try both common BME280 I2C addresses
  bmeOK = bme.begin(0x76);
  if (!bmeOK) {
    bmeOK = bme.begin(0x77);
  }

  if (!bmeOK) {
    Serial.println(F("BME280 not found!"));
    showMessage(F("BME280 NOT FOUND"));
  }

  delay(1500);
}

void loop() {
  if (!bmeOK) {
    delay(2000);
    return;
  }

  float temperature = bme.readTemperature();
  float humidity    = bme.readHumidity();
  float pressure    = bme.readPressure() / 100.0F;

  // Print full precision readings to Serial Monitor
  Serial.print(F("Temperature: "));
  Serial.print(temperature, 1);
  Serial.print(F(" C  Humidity: "));
  Serial.print(humidity, 1);
  Serial.print(F(" %  Pressure: "));
  Serial.print(pressure, 1);
  Serial.println(F(" hPa"));

  if (oledOK) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    // Row 1: title
    display.setCursor(0, 0);
    display.println(F("ENVIRONMENT MONITOR"));

    // Row 2: temperature
    display.setCursor(0, 8);
    display.print(F("Temp: "));
    display.print(temperature, 1);
    display.print(F(" C"));

    // Row 3: relative humidity
    display.setCursor(0, 16);
    display.print(F("Hum : "));
    display.print(humidity, 1);
    display.print(F(" %"));

    // Row 4: barometric pressure
    display.setCursor(0, 24);
    display.print(F("Pres: "));
    display.print(pressure, 1);
    display.print(F(" hPa"));

    display.display();
  }

  delay(1000);
}
