# 🏃 REACTION TIME (R.T.)
### *Measurement of TR in Starting Block Exits*

[![LICENSE](https://img.shields.io/badge/license-MIT-lightgrey.svg)](/LICENSE.txt)
[![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D?logo=arduino)](https://www.arduino.cc/)
[![ESP8266](https://img.shields.io/badge/ESP8266-NodeMCU-1C9E3A?logo=espressif)](https://www.espressif.com/)
[![Version](https://img.shields.io/badge/version-2.0-brightgreen)](https://github.com/fran-byte/tiempo_reaccion)
[![Status](https://img.shields.io/badge/status-Beta-yellow)](https://github.com/fran-byte/tiempo_reaccion)

---

## 📖 Table of Contents

- [⚙️ Operation](#️-operation)
- [🔧 Installing ESP8266 Board in Arduino](#-installing-esp8266-board-in-arduino)
- [📡 ESP8266 PINOUT](#-esp8266-pinout)
- [📦 Components](#-components)
- [🔌 Connections](#-connections)
- [💻 Code](#-code)
- [🧪 BETA](#-beta)
- [🔋 Battery Level (Extra)](#-battery-level-extra)
- [🧠 ESP8266 Deep Dive](#-esp8266-deep-dive)
- [📜 License](#-license)

---

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/giphy.gif" alt="Demo" width="600">
</p>

---

## ⚙️ Operation

This repository aims to **measure reaction times** and quantify **explosiveness improvements** in an athlete's training.

The starting block exit in athletics is used in:
- 🏃 60m / 100m / 400m sprints
- 🏃 60m / 100m / 110m hurdles
- 🏃 4x200m / 4x400m relays (first leg only)

> Mastering this technique is **essential** for short-distance events.

---

### 📶 Connecting to the Device

1. **WiFi Connection**  
   Connect to the network: **Club-Atletismo-Leganes**  
   *(The device has no internet access — confirm you want to stay connected)*

2. **Access the Web Interface**  
   Open your browser and go to:  
   `http://192.168.4.1/START=O`

   > 🔔 Upon connection, the device will perform a **test beep**. If you hear the buzzer, the connection was successful. The web interface will then appear.

   <p align="center">
     <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/wifi2.png" alt="Web Interface" width="400">
   </p>

3. **Controls**  
   From the screen you can:
   - ✅ Select **sensitivity** levels
   - ✅ **Reset** parameters
   - ✅ Adjust deviation (temporary calibration)
   - ✅ Press **GO** to trigger the start

4. **The Start**  
   - The **GO** button triggers the start with a **delay** (to capture pre-movement)
   - The start is **VOID** if it occurs before the signal or within **<100ms**

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/false_start.gif" alt="False Start" width="400">
</p>

---

### 🏆 Reaction Times in TOKYO 2021

| Level | Time |
|-------|------|
| Acceptable | **< 200ms** |
| Good | **< 170ms** |
| **Excellent** | **< 145ms** |

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/TR Tokio2.png" alt="Tokyo 2021 Times" width="500">
</p>

---

## 🔧 Installing ESP8266 Board in Arduino

1. **Open Arduino IDE** (latest version)

2. **Add Board Manager URL**  
   Go to `File > Preferences` and add:
   ```
   http://arduino.esp8266.com/stable/package_esp8266com_index.json
   ```

3. **Install the Board**  
   Go to `Tools > Board > Boards Manager`  
   Search for **esp8266** and install.

---

## 📡 ESP8266 PINOUT

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/ESP-12E-Development-Board-ESP8266-NodeMCU-Pinout.png" alt="Pinout" width="500">
</p>

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/ESP8266 varias.jpg" alt="ESP8266" width="500">
</p>

---

## 📦 Components

| Component | Qty | Description |
|-----------|-----|-------------|
| NodeMCU ESP8266 | 1 | Development board |
| CJMCU ADXL345 | 1 | 3-axis accelerometer |
| 8.4V Battery | 1 | Rechargeable (bicycle light battery) |
| 1KΩ Resistor | 1 | For optocoupler |
| PC817 Optocoupler | 1 | Electrical isolation |
| Piezoelectric Buzzer | 1 | 3-30V DC, 30mA, 95dB |

> ⚠️ **IMPORTANT:**  
> The **buzzer MUST NOT be soldered to the same board as the accelerometer** — vibrations can cause false readings.  
> Place it on a **pad** or in a **separate enclosure**.

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/componentes.jpg" alt="Components" width="500">
</p>

---

## 🔌 Connections

### 📐 I2C Wiring Diagram

| Component | Pin | Connect to |
|-----------|-----|------------|
| ADXL345 | CS | 3.3V (ESP8266) |
| ADXL345 | SCL | D2 (ESP8266) |
| ADXL345 | SDA | D1 (ESP8266) |
| ADXL345 | GND | GND (ESP8266) |
| Optocoupler | Vin / Collector | Battery +8.4V |

> 🧠 The **buzzer** is connected via the **optocoupler** to avoid electrical interference.

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/conectividades.jpg" alt="Connections" width="500">
</p>

---

## 💻 Code

Full code available at:  
👉 [Code / tiempo_reaccion](https://github.com/fran-byte/tiempo_reaccion/tree/main/code/tiempo_reaccion)

---

## 🧪 BETA

> 📸 Current prototype on **protoboard**. PCB design and machining pending.

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/Proto.jpg" alt="Prototype" width="400">
</p>

---

## 🔋 Battery Level (Extra)

### 📊 Analog Measurement

You can add a variable in the HTML to display battery level using **GPIO12** as analog input.

#### ⚡ Voltage Divider

Since the battery is **8-10V** and the ESP8266 only accepts **3.3V**, we use a voltage divider:

```
Input Voltage → 49KΩ → GPIO12
                     │
                    10KΩ
                     │
                    GND
```

#### 📐 Calculation

- Reference: 3.3V / 1023 = **0.0032258** per unit
- Multiplier: 100% / 20.408% = **4.9**

#### 💻 Example Code

```cpp
void leer_voltios() {
    float voltios;
    voltios = (analogRead(12)) * 0.003225806452 * 4.9;
    
    if (voltios <= 5.50) {
        battery = "<h2 style='color:red'>BATTERY ⚡</h2>";
    } else if (voltios > 5.50 && voltios < 6.60) {
        battery = "<h2 style='color:orange'>BATTERY ⚡⚡⚡</h2>";
    } else {
        battery = "<h2 style='color:green'>BATTERY ⚡⚡⚡⚡⚡</h2>";
    }
}
```

---

## 🧠 ESP8266 Deep Dive

### 📌 What is the ESP8266?

The **ESP8266** is a **System on Chip (SoC)** with integrated **WiFi**. Originally designed as a WiFi interface for Arduinos, it quickly became popular in the maker community.

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/250px-ESP-01.jpg" alt="ESP-01" width="200">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/ESP8266 pla.jpg" alt="ESP8266" width="200">
</p>

The **ESP-12** became the most popular module, used in boards like **NodeMCU** and **Wemos**.

---

### 📟 NodeMCU ESP8266

An IoT-oriented development platform similar to Arduino.  
The **NodeMCU v2 ESP8266** uses the **ESP-12E SoM**, integrating the **CP2102 USB-Serial TTL** converter.

#### 🔧 Technical Specifications

| Specification | Detail |
|---------------|--------|
| Input Voltage | 4.5V~9V (max 10V) or USB |
| I/O Voltage | 3.3V (**Do NOT use 5V**) |
| Current per pin | 12mA |
| Board | NodeMCU v2 (Amica) |
| USB-Serial | CP2102 |
| SoM | ESP-12E (Ai-Thinker) |
| SoC | ESP8266 (Espressif) |
| CPU | Tensilica Xtensa LX3 (32-bit) |
| Clock Speed | 80MHz / 160MHz |
| Instruction RAM | 32KB |
| Data RAM | 96KB |
| Flash Memory | 4MB |
| Digital GPIO | 17 (4 with PWM at 3.3V) |
| Analog ADC | 1 (0-1V) |
| UART Ports | 2 |
| Certification | FCC |
| Antenna | PCB |
| WiFi | 802.11 b/g/n |
| WiFi Direct | P2P, soft-AP |
| Output Power | +19.5dBm (802.11b) |
| Leakage Current | < 10uA |
| Standby Power | < 1.0mW (DTIM3) |
| Reset/Flash | Buttons |
| LED indicators | 2 |
| Dimensions | 49×26×12mm |
| Weight | 9g |

#### 🔌 Connectivity

- SDIO 2.0, SPI, UART
- Integrated RF switch, balun, 24dBm PA, DCXO, PMU
- RISC processor with on-chip memory and external interface
- Integrated MAC/Baseband processor
- I2S interface for high-quality audio
- On-chip LDO voltage regulators
- Proprietary spurious-free clock generation
- WEP, TKIP, AES, WAPI support

---

### 📡 Communication Protocols

The NodeMCU supports three main serial communication protocols:

| Protocol | Pins | Description |
|-----------|------|-------------|
| **UART** | Rx / Tx | Asynchronous serial communication |
| **I2C** ⭐ | D1 (SDA) / D2 (SCL) | **Used in this project** — 2-wire interface |
| **SPI** | D5 (CLK) / D6 (MISO) / D7 (MOSI) | Full-duplex, 3-wire |

> ⭐ **I2C** is ideal for the accelerometer because it uses only 2 wires.

---

### ⚡ PWM Pins

Some digital pins support **Pulse Width Modulation (PWM)**, allowing analog signal simulation via fast digital pulses.

PWM is commonly used for motor control.

On the **NodeMCU**, PWM-compatible pins are:  
**D2, D5, D6, D8**

Use `analogWrite()` to set PWM values.

---

### 📟 CJMCU ADXL345 3-Axis Accelerometer

**Model: CJMCU ADXL345**

This module features an **ADXL345** 3-axis accelerometer, measuring acceleration in the range of **±2g to ±16g** (selectable).

It uses **I2C** or **SPI** communication. The X-axis is used for this project.

#### 🔧 Specifications

| Parameter | Detail |
|-----------|--------|
| Input Voltage | 3.3V~5V |
| Operating Voltage | 2V~3.6V |
| Operating Current | 140µA |
| Interface | I2C / SPI (5MHz) |
| Self-test | Yes |
| Axes | X, Y, Z |
| Internal Clock | 400KHz |
| Sensitivity | 4 LSB/g |
| Selectable Range | 2g / 4g / 8g / 16g |
| Operating Temp | -40°C ~ +85°C |
| Dimensions | 19×14mm |

> **Note:** This board has a built-in 3.3V regulator, so it works with 3.3V–5V. However, **logic levels are 3.3V** — use a level shifter for 5V systems.

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/ADXL335.jpg" alt="ADXL345" width="300">
</p>

---

## 📜 License

This project is licensed under the **MIT License**.  
[View full license](LICENSE.txt)

---

## 🤝 Contributions

Want to improve this project?  
**Issues** and **Pull Requests** are welcome!



---

*Made with ❤️ for athletics and technology.*
