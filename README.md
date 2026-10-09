# 🌦️ Arduino Nano Weather Station with OLED & BME280

# 🌦️ Arduino Nano Weather Station with OLED & BME280

A compact DIY weather monitoring project using an **Arduino Nano**, **0.91-inch I2C OLED display**, and **BME280 environmental sensor**. The system measures and displays real-time temperature, relative humidity, and barometric pressure on a small OLED screen.

## ✨ Features

- 🌡️ Real-time temperature monitoring (°C)
- 💧 Relative humidity measurement (%)
- 🌍 Barometric pressure monitoring (hPa)
- 🖥️ Compact 0.91-inch OLED interface
- 🔌 I2C communication for easy wiring
- 🔄 Automatic sensor readings every second
- 🛠️ Simple, beginner-friendly Arduino IDE code

## 🧰 Components Required

- Arduino Nano
- 0.91-inch I2C OLED display (SSD1306, 128×32)
- BME280 temperature, humidity, and pressure sensor
- Jumper wires
- USB cable

## 🔌 Pin Connections

| Arduino Nano | OLED | BME280 |
|---|---|---|
| A4 | SDA | SDA |
| A5 | SCL | SCL |
| GND | GND | GND |
| Suitable supply | VCC | VIN/VCC |

**Note:** Verify your module's voltage requirements before connecting the power supply. Some BME280 boards require 3.3V.

## 📚 Required Libraries

Install these libraries using the Arduino IDE Library Manager:

- Adafruit BME280 Library
- Adafruit Unified Sensor
- Adafruit SSD1306
- Adafruit GFX Library

## 🚀 Getting Started

1. Connect the OLED display and BME280 sensor to the Arduino Nano.
2. Install the required libraries in Arduino IDE.
3. Open the Arduino sketch from this repository.
4. Select **Arduino Nano** under Tools → Board.
5. Choose the correct processor and COM port.
6. Upload the code.
7. View temperature, humidity, and pressure on the OLED display.

## 📺 Display Example

```text
TEMP:  27.4 C
HUM :  63.2 %
PRES: 1008.6 hPa
```

*Example readings only; actual measurements depend on the environment.*

## 🎯 Applications

- DIY weather stations
- Indoor environment monitoring
- IoT learning projects
- Electronics and embedded systems experiments
- Educational STEM projects

## 🔮 Future Improvements

- ESP8266/ESP32 Wi-Fi connectivity
- Web-based live monitoring dashboard
- Data logging and historical graphs
- Weather alerts and notifications
- Battery-powered portable operation

## 🤝 Contributing

Suggestions, improvements, and contributions are welcome! Feel free to fork this repository and experiment with the project.

## 📄 License

This project is available under the MIT License. Add a `LICENSE` file to the repository to apply it.

---

⭐ If you find this project useful, consider giving the repository a star!

**Built with ❤️ Dipankar Bhunia.**