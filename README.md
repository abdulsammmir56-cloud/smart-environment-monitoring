# Smart Environmental Monitoring & Alert System

An ESP32-based environmental monitoring and alert system developed and simulated using Wokwi.

The system monitors **temperature, humidity, and gas levels** and provides visual and audible alerts when configured thresholds are exceeded.

## Features

* 🌡️ Temperature monitoring using DHT22
* 💧 Humidity monitoring using DHT22
* 🧪 Gas-level monitoring using MQ-2
* 🖥️ Real-time OLED display
* 🔴 Warning LED
* 🔊 Buzzer alarm
* 📟 Serial Monitor output
* 🚨 Configurable warning thresholds
* 🧩 ESP32-based design
* 🧪 Wokwi simulation

## Hardware Components

| Component     | Purpose                  |
| ------------- | ------------------------ |
| ESP32 DevKit  | Main microcontroller     |
| DHT22         | Temperature and humidity |
| MQ-2          | Gas-level sensing        |
| SSD1306 OLED  | Display                  |
| LED           | Visual warning           |
| Buzzer        | Audible warning          |
| 220Ω resistor | LED current limiting     |

## Pin Connections

| Component   | ESP32 Pin |
| ----------- | --------- |
| DHT22 DATA  | GPIO 4    |
| MQ-2 AOUT   | GPIO 34   |
| OLED SDA    | GPIO 21   |
| OLED SCL    | GPIO 22   |
| Warning LED | GPIO 2    |
| Buzzer      | GPIO 5    |

## Alert Thresholds

The current thresholds are configured for **simulation purposes**:

```text
Temperature > 35°C
Humidity > 80%
Gas level > 2000
```

If any configured threshold is exceeded:

* Warning LED turns ON
* Buzzer activates
* OLED displays `WARNING!`
* Serial Monitor reports the alert condition

> **Note:** The gas threshold is a Wokwi simulation value and should not be treated as a certified real-world gas safety limit.

## Project Structure

```text
smart-environment-monitoring/
│
├── sketch.ino
├── diagram.json
├── libraries.txt
├── LICENSE
└── README.md
```

## Libraries

The project uses:

* Adafruit SSD1306
* Adafruit GFX Library
* DHT sensor library

## Simulation

## Simulation

The project was developed and tested using **Wokwi** with an ESP32 DevKit.

▶️ **[Run the simulation on Wokwi](https://wokwi.com/projects/475596234272305153)**

The simulation includes:

* ESP32 DevKit
* DHT22 temperature and humidity sensor
* MQ-2 gas sensor
* SSD1306 OLED display
* Warning LED
* Buzzer


## How It Works

The ESP32 continuously reads environmental data from the sensors.

1. DHT22 provides temperature and humidity.
2. MQ-2 provides a gas-level reading.
3. The ESP32 compares the readings with the configured thresholds.
4. Sensor values are displayed on the OLED.
5. If a threshold is exceeded, the warning LED and buzzer are activated.
6. Sensor readings and warning information are also printed to the Serial Monitor.

## Future Improvements

Possible future improvements include:

* Wi-Fi connectivity
* Web dashboard
* Mobile notifications
* Cloud data logging
* Historical sensor graphs
* Improved gas-sensor calibration
* Multiple environmental sensors
* Automatic data logging
* Remote monitoring

  ## Project Preview

![Wokwi Simulation](wokwi-simulation.png)

## Author

**Abdul Sammir Bashirudeen**

## License

This project is licensed under the terms included in the `LICENSE` file.
