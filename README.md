# 🌱 Smart Environmental Monitoring & Alert System

An ESP32-based environmental monitoring and alert system that continuously monitors **temperature, humidity, and gas levels** and provides visual and audible warnings when configured thresholds are exceeded.

The project was developed and simulated using **Wokwi** and is maintained using **Git and GitHub**.

---

## 📌 Project Overview

The **Smart Environmental Monitoring & Alert System** is designed to demonstrate how an ESP32 can collect environmental data from multiple sensors, display the information in real time, and activate an alert system when potentially unsafe conditions are detected.

The system monitors:

* 🌡️ Temperature
* 💧 Humidity
* 🧪 Gas level

The sensor readings are displayed on an **SSD1306 OLED display** and are also sent to the **Serial Monitor**.

When a configured threshold is exceeded, the system activates:

* 🔴 Warning LED
* 🔊 Buzzer
* ⚠️ Warning message on the OLED
* 📟 Alert information in the Serial Monitor

---

## 🖥️ Project Preview

![Wokwi Simulation](wokwi-simulation.png)

---

## 🚀 Features

* Real-time temperature monitoring
* Real-time humidity monitoring
* Gas-level monitoring
* OLED display
* Visual warning using LED
* Audible warning using buzzer
* Serial Monitor output
* Configurable environmental thresholds
* ESP32-based control system
* Wokwi simulation
* GitHub version control

---

## 🧰 Hardware Components

| Component       | Quantity | Purpose                          |
| --------------- | -------: | -------------------------------- |
| ESP32 DevKit    |        1 | Main microcontroller             |
| DHT22           |        1 | Temperature and humidity sensing |
| MQ-2 Gas Sensor |        1 | Gas-level sensing                |
| SSD1306 OLED    |        1 | Display sensor readings          |
| LED             |        1 | Visual warning                   |
| Buzzer          |        1 | Audible warning                  |
| 220Ω Resistor   |        1 | LED current limiting             |

---

## 🔌 Pin Connections

| Component | Pin      | ESP32               |
| --------- | -------- | ------------------- |
| DHT22     | DATA     | GPIO 4              |
| DHT22     | VCC      | 3.3V                |
| DHT22     | GND      | GND                 |
| MQ-2      | AOUT     | GPIO 34             |
| MQ-2      | VCC      | 5V                  |
| MQ-2      | GND      | GND                 |
| OLED      | SDA      | GPIO 21             |
| OLED      | SCL      | GPIO 22             |
| OLED      | VCC      | 3.3V                |
| OLED      | GND      | GND                 |
| LED       | Anode    | GPIO 2 through 220Ω |
| LED       | Cathode  | GND                 |
| Buzzer    | Positive | GPIO 5              |
| Buzzer    | Negative | GND                 |

---

## 🧠 System Architecture

```text
                    ┌─────────────────────┐
                    │       ESP32         │
                    │   Main Controller   │
                    └──────────┬──────────┘
                               │
             ┌─────────────────┼─────────────────┐
             │                 │                 │
             ▼                 ▼                 ▼
        ┌─────────┐       ┌─────────┐       ┌─────────┐
        │  DHT22  │       │  MQ-2   │       │  OLED   │
        │ Temp +  │       │  Gas    │       │ Display │
        │Humidity │       │ Sensor  │       │         │
        └─────────┘       └─────────┘       └─────────┘
                               │
                               ▼
                       ┌───────────────┐
                       │ Alert System  │
                       ├───────────────┤
                       │ 🔴 LED        │
                       │ 🔊 Buzzer     │
                       └───────────────┘
```

---

## ⚙️ Alert Thresholds

The current thresholds are configured for **simulation purposes**.

| Parameter   | Threshold |
| ----------- | --------: |
| Temperature |    > 35°C |
| Humidity    |     > 80% |
| Gas Level   |    > 2000 |

If any configured threshold is exceeded, the system enters **WARNING** mode.

### Warning behavior

When a warning condition occurs:

```text
LED     → ON
Buzzer  → ON
OLED    → WARNING!
Serial  → Alert reason displayed
```

If all readings remain below their configured thresholds:

```text
LED     → OFF
Buzzer  → OFF
OLED    → STATUS: SAFE
```

> ⚠️ **Important:** The MQ-2 gas threshold of `2000` is a simulation value used for this project. It is not a certified real-world gas safety limit. A physical system would require appropriate sensor calibration, electrical protection, and safety validation.

---

## 🖥️ OLED Display

During normal operation, the OLED displays information similar to:

```text
ENVIRONMENT MONITOR

Temp: 25.0 C
Hum : 45.0 %
Gas : 850

STATUS: SAFE
```

When a threshold is exceeded:

```text
ENVIRONMENT MONITOR

Temp: 38.0 C
Hum : 45.0 %
Gas : 850

WARNING!
```

---

## 📟 Serial Monitor

The ESP32 also outputs sensor readings and system status through the Serial Monitor.

Example:

```text
================================
       SENSOR READINGS
================================
Temperature : 25.0 C
Humidity    : 45.0 %
Gas Level   : 850

STATUS: SAFE
================================
```

Example warning:

```text
================================
       SENSOR READINGS
================================
Temperature : 38.0 C
Humidity    : 45.0 %
Gas Level   : 850

STATUS: WARNING
Reason: Temperature HIGH
================================
```

---

## 🔄 How the System Works

The system follows a continuous monitoring cycle:

```text
Start
  │
  ▼
Initialize ESP32
  │
  ├── Initialize DHT22
  ├── Initialize MQ-2
  ├── Initialize OLED
  ├── Initialize LED
  └── Initialize Buzzer
  │
  ▼
Read Temperature & Humidity
  │
  ▼
Read Gas Level
  │
  ▼
Compare Values With Thresholds
  │
  ├── Safe ────────► Display SAFE
  │                    LED OFF
  │                    Buzzer OFF
  │
  └── Warning ────► Display WARNING
                       LED ON
                       Buzzer ON
  │
  ▼
Repeat
```

---

## 🧪 Wokwi Simulation

The complete circuit is simulated using Wokwi.

### ▶️ Run the Simulation

[Open the Smart Environmental Monitoring System in Wokwi](https://wokwi.com/projects/475596234272305153)

The simulation contains:

* ESP32 DevKit
* DHT22
* MQ-2 gas sensor
* SSD1306 OLED
* LED
* 220Ω resistor
* Buzzer

---

## 📚 Libraries

The project uses the following Arduino libraries:

```text
Adafruit SSD1306
Adafruit GFX Library
DHT sensor library
```

The libraries are listed in:

```text
libraries.txt
```

---

## 📁 Project Structure

```text
smart-environment-monitoring/
│
├── sketch.ino
├── diagram.json
├── libraries.txt
├── README.md
├── LICENSE
└── wokwi-simulation.png
```

### File Description

| File                   | Description                 |
| ---------------------- | --------------------------- |
| `sketch.ino`           | Main ESP32 Arduino program  |
| `diagram.json`         | Wokwi circuit configuration |
| `libraries.txt`        | Required Arduino libraries  |
| `README.md`            | Project documentation       |
| `LICENSE`              | Project license             |
| `wokwi-simulation.png` | Wokwi circuit screenshot    |

---

## 🛠️ Software & Tools

* **ESP32**
* **Arduino Framework**
* **C/C++**
* **Wokwi**
* **Git**
* **GitHub**

---

## ▶️ How to Run the Project

### Option 1 — Wokwi

1. Open the Wokwi simulation.
2. Start the simulation.
3. Observe the OLED display.
4. Open the Serial Monitor.
5. Change the sensor values to test different conditions.
6. Observe the LED and buzzer when thresholds are exceeded.

### Option 2 — GitHub

Clone the repository:

```bash
git clone https://github.com/abdulsammmir56-cloud/smart-environment-monitoring.git
```

Enter the project directory:

```bash
cd smart-environment-monitoring
```

The project files can then be opened and modified using an Arduino-compatible development environment.

---

## 🧪 Testing

The system can be tested by changing the simulated sensor values.

### Temperature Test

Set the DHT22 temperature above:

```text
35°C
```

Expected result:

```text
LED     → ON
Buzzer  → ON
OLED    → WARNING!
```

### Humidity Test

Set humidity above:

```text
80%
```

Expected result:

```text
LED     → ON
Buzzer  → ON
OLED    → WARNING!
```

### Gas Test

Increase the simulated gas sensor value above:

```text
2000
```

Expected result:

```text
LED     → ON
Buzzer  → ON
OLED    → WARNING!
```

---

## 🚧 Current Project Status

🟢 **Core monitoring system implemented**

Current functionality:

* [x] ESP32 setup
* [x] DHT22 temperature monitoring
* [x] DHT22 humidity monitoring
* [x] MQ-2 gas monitoring
* [x] OLED display
* [x] Warning LED
* [x] Buzzer
* [x] Threshold-based alerts
* [x] Serial Monitor output
* [x] Wokwi simulation
* [x] GitHub repository
* [x] Project documentation

---

## 🔮 Future Improvements

Possible future development:

* 📶 Wi-Fi connectivity
* 🌐 Web-based monitoring dashboard
* 📱 Mobile notifications
* ☁️ Cloud data logging
* 📊 Historical sensor graphs
* 💾 SD card data logging
* ⏱️ Long-term environmental data collection
* 🔧 Improved MQ-2 calibration
* 🚨 More advanced alarm states
* 🔋 Battery-powered operation
* 🏠 IoT integration
* 📡 Remote monitoring

---

## ⚠️ Safety Note

This project is primarily an educational and simulation project.

The simulated sensor thresholds should **not** be used as real-world safety limits.

For physical deployment, the system would require:

* Proper sensor calibration
* Appropriate electrical protection
* Safe power-supply design
* Validated sensor thresholds
* Appropriate enclosure and environmental protection
* Testing against relevant safety requirements

---

## 👨‍💻 Author

**Abdul Sammir Bashirudeen**

ESP32 • IoT • Embedded Systems • Environmental Monitoring

---

## 📄 License

This project is distributed under the license included in the `LICENSE` file.
