# REACTION TIME (R.T.)
## MEASUREMENT of R.T. in STARTING BLOCKS

[![LICENSE](https://img.shields.io/badge/license-MIT-lightgrey.svg)](/LICENSE.txt)

## Index

- [Functionality](https://github.com/fran-byte/tiempo_reaccion/blob/main/README_en.md#FUNCTIONALITY)

- [Installing the ESP8266 board in Arduino](https://github.com/fran-byte/tiempo_reaccion/blob/main/README_en.md#Installing-our-ESP8266-board-in-Arduino)

- [ESP8266 PINOUT](https://github.com/fran-byte/tiempo_reaccion/blob/main/README_en.md#pinout-datasheet)

- [CJMCU ADXL345 three-axis accelerometer](https://github.com/fran-byte/tiempo_reaccion/blob/main/README_en.md#cjmcu-adxl345-aceler%C3%B3metro-de-tres-ejes)

- [Components](https://github.com/fran-byte/tiempo_reaccion/blob/main/README_en.md#components)

- [Connections](https://github.com/fran-byte/tiempo_reaccion/blob/main/README_en.md#connections)

- [Code](https://github.com/fran-byte/tiempo_reaccion/tree/main/code/tiempo_reaccion)

- [BETA](https://github.com/fran-byte/tiempo_reaccion#beta)

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/giphy.gif"></p>

  
## FUNCTIONALITY

This repository aims to measure reaction times and quantify improvements in explosiveness during an athlete's training.

The starting blocks in athletics are used in 60/100/400-meter sprints and in 60/100/110-meter hurdles (including the first leg of the 4 x 200 meters and 4 x 400 meters relays) and are not used for any other longer-distance disciplines. In shorter distances, mastering this technique is crucial.

### CONNECTING TO THE DEVICE

- We will connect to the device via WIFI; in our case, it will be **Club-Atletismo-Leganes**. Next, our device will ask if we want to stay connected to this network since it does not have internet access. We will choose to stay connected.
- If, for any reason, we lose connection to our device, it is recommended to disconnect and reconnect, searching for our network: Club-Atletismo-Leganes.
- We connect to the following address: **192.168.4.1/START=O**. As soon as we connect, a test beep will be made, letting us know that the buzzer has connected. Immediately afterward, we will see the webpage we will interact with.

<p align="center">
 
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/wifi2.png">
</p>

- From our screen, we can select the sensitivities of our device and reset parameters.
- TEMPORARILY, we will have a deviation help to add or subtract milliseconds until the device is perfectly calibrated. Once this is achieved, this option will be removed.
- The **GO** button will activate the start shot, which will be **DELAYED** by a few milliseconds to capture any PRE-SHOOT movement.
- The start will be FALSE if it occurs before the shot or if it is performed with a time less than 100ms.

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/false_start.gif">
</p>

## Our Device

The device, powered by an 8.4V rechargeable battery, will be placed in the starting blocks and will be based on two components:

- [**NodeMCU ESP8266**](https://github.com/fran-byte/tiempo_reaccion/blob/main/README_en.md#nodemcu-esp8266) development board, which stores the program and hosts the HTML Web server.
- [**CJMCU ADXL345 Accelerometer Module**](https://github.com/fran-byte/tiempo_reaccion/blob/main/README_en.md#cjmcu-adxl345-aceler%C3%B3metro-de-tres-ejes) responsible for capturing the athlete's movement. We will use only the X-axis for this project.

We will use the Arduino IDE to program the ESP8266.

## Reaction Times in TOKYO 2021

- An acceptable time would be considered **< 200ms**, good **< 170ms**, and excellent **< 145ms**.
<img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/TR Tokio2.png">


<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/esp8266-esp&ADXL335jpg.jpg">
</p>

## Installing our ESP8266 board in Arduino

This process is necessary for the Arduino IDE to recognize our development board:

- Always ensure you have the latest version of Arduino IDE updated.

- Next, go to File/Preferences and in the “Additional Board Manager URLs” field, add:
http://arduino.esp8266.com/stable/package_esp8266com_index.json

```
http://arduino.esp8266.com/stable/package_esp8266com_index.json
```

- Now, go to Tools/Board: … /Board Manager and search for "esp8266" in the dropdown, select it, and install.

## COMPONENTS:
- NodeMCU ESP8266 development board.
- CJMCU ADXL345 Accelerometer Module.
- 8.4v Battery (Bicycle light battery) **Remember** you can use Vin voltages = 4.5V~9V (10VMAX)
- 1KΩ Resistor.
- PC 817 Optocoupler.
- Piezoelectric Buzzer 3-30V DC - 30mA 95dB
- **THE BUZZER CANNOT BE SOLDERED TO THE SAME BOARD AS THE ACCELEROMETER** as it causes false starts since the vibration (which are micro-accelerations) activates the sensor.
- It is important to place the Buzzer on a cushion or in a separate box to avoid such mechanical interferences.

  <p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/componentes.jpg">
</p>

## CONNECTIONS:
We connect the NodeMCU ESP8266 with the ADXL 345 accelerometer sensor using an **I2C** connection:

- To configure the **I2C** mode, connect the **CS** of the ADXL 345 to the **3.3V** of the NodeMCU ESP8266.
- PIN **D2** (SCL) of the NodeMCU ESP8266 to the **SCL** PIN of the accelerometer.
- PIN **D1** (SDA) of the NodeMCU ESP8266 to the **SDA** PIN of the accelerometer.
- PIN **GND** of the NodeMCU ESP8266 to the **GND** PIN of the accelerometer sensor.
- Connect the **Vin** and **Collector** PINs of the Opto to the **+8.4V** battery.
- Connect the Buzzer through an Optocoupler to avoid interferences.

  <p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/conectividades.jpg">
</p>

## Code

- Available here: [Link](https://github.com/fran-byte/tiempo_reaccion/tree/main/code/tiempo_reaccion)

## BETA

- Photo of the prototype still on a breadboard, pending to make the circuit and machine it.

  <p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/Proto.jpg">
</p>


## EXTRA
### BATTERY LEVEL

- We can include a str variable in the HTML to display the battery level.
- For this, we will use analog input 12 (GPIO12) to sense the battery voltage.

- This is not a truly analog input, but a 1024-part digital one. We can consider the 3.3V level as the highest part 1023 and the 0V level as the lowest part 0. And since we will use voltages of 8-10V, higher than those accepted for this 3.3V input, we will not be able to connect the battery directly to the analog input and will use a voltage divider.
- When constructing the voltage divider, we will use relatively high values to avoid high power consumption in it. To do this, we will try to use 5 parts (up to a maximum of 25V), dividing the input voltage into 5 parts, reading it, and then calculating the battery's actual voltage.
- Since the resistances on the market prevent us from having exactly those 5 parts, the calculations will be as follows:

for 49000 Ohms, which will be the —– 100 %

then for 10000 Ohms, it will be the —– x %

- So the actual percentage for that division will be 20.408 %. Then we will obtain that multiplier by dividing 100% by the calculated percentage, that is, 4.9000.

- To obtain the corresponding voltage part of each part of our analog input, we will divide the reference voltage by 1023.
3.3V / 1023 = 0.003225806452

```c
void leer_voltios()
{

<h2 style='color:orange'>Sensibilidad: MEDIA</h2>";

 float voltios;
 voltios= (analogRead(12))0,0032258064524.9000;
 
 if (voltios <= 5.50)
 {
  battery = "<h2 style='color:red'>BATERIA |</h2>";
 }
 
 if ((voltios > 5.50)  && (voltios < 6.60))
 {
  battery = "<h2 style='color:orange'>BATERIA |||</h2>";
 }
 
 else
 {
  battery = "<h2 style='color:green'>BATERIA |||||</h2>";
 }
 
}
```

## Breaking down the ESP8266

The ESP8266 usually comes integrated into a module. This is because the ESP8266 SoC itself does not have integrated Flash memory. The first to see the light was the ESP-01 which was designed to function as a WiFi interface for Arduino boards. However, it quickly became very popular in the Maker community.

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/250px-ESP-01.jpg"><img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/ESP8266 pla.jpg">
</p>


From this module many more emerged until the ESP-12 finally burst onto the market, the most popular of all the modules. This module is used in many boards, the most famous being NodeMCU and Wemos.

## NodeMCU ESP8266
It is a development platform similar to Arduino and oriented towards IoT (Internet of Things).
The **NodeMcu v2 ESP8266** board has as its core the ESP-12E SoM, which in turn is based on the ESP8266 Wi-Fi SoC, and also integrates the **USB-Serial TTL CP2102** converter and the necessary micro-USB connector. for programming and communication to PC.

It is specially designed to work mounted on a breadboard or soldered on a plate. It has a 3.3V voltage regulator on the board, this allows you to power the board directly from the micro-USB port or through the 5V and GND pins. **The input/output pins (GPIO) work at 3.3V** so for connection to 5V systems it is necessary to use converters


**TECHNICAL SPECIFICATIONS:**
- Power Voltage: 4.5V~9V (10VMAX) and/or USB powered
- Input/Output Voltage: 3.3V DC (**Do not use 5V**)
- Nominal current per pin: 12mA
- Board: NodeMCU v2 (Amica)
- USB-serial converter chip: CP2102
- SoM: ESP-12E (Ai-Thinker)
- SoC: ESP8266 (Espressif)
- CPU: Tensilica Xtensa LX3 (32 bit)
- Clock Frequency: 80MHz/160MHz
- Instruction RAM: 32KB
- Data RAM: 96KB
- External Flash Memory: 4MB
- GPIO Digital Pins: 17 (4 can be configured as PWM at 3.3V)
- Analog ADC Pin: 1 (0-1V)
- UART Serial Port: 2
- FCC Certification
- Antenna on PCB
- 802.11 b/g/n
- Wi-Fi Direct (P2P), soft-AP
- Integrated TCP/IP Protocol Stack
- Integrated PLLs, regulators, DCXO and power management
- Output power of +19.5dBm in 802.11b mode
- Leakage current less than 10uA
- STBC, 1×1 MIMO, 2×1 MIMO
- A-MPDU & A-MSDU aggregation & 0.4ms guard interval
- Wake up and transmit packets in < 2ms
- Standby power consumption < 1.0mW (DTIM3)
- RESET and FLASH button
- Led indicators: 2
- Dimensions: 49*26*12mm
- Weight: 9 grams
 
**CONNECTIVITY**

- SDIO 2.0, SPI, UART
- Integrates RF switch, balun, 24dBm PA, DCXO and PMU
- It has a RISC processor, on-chip memory and interface for external memory
- Integrated MAC/Baseband processor
- I2S interface for high quality audio applications
- On-chip "low-dropout" linear voltage regulators
- Proprietary "spurious free" clock generation architecture
- Integrated WEP, TKIP, AES and WAPI modules

## PINOUT datasheet

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/ESP-12E-Development-Board-ESP8266-NodeMCU-Pinout.png">
</p>

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/ESP8266 varias.jpg">
</p>

## PWM pins
You'll notice that some of the digital pins come with **Pulse Width Modulation**, or **PWM** functionality. This provides us with a means of simulating an analog signal using a rapid series of digital pulses.

PWM signals are commonly used to control motors.

This could be done using any of the MCU's digital outputs by writing a code loop that quickly cycles a given pin on and off, but this would interfere with the main program and consume valuable resources.

A better solution is to use one of the separate PWM outputs, which will handle all the loops for you once they have received a value.

You can write a value to a PWM using the **analogWrite()** function. Make sure you have selected a **PWM** compatible output.

On the NodeMCU, these are D2, D5, D6, and D8.

## Communication
The NodeMCU supports the three main serial communication protocols found on the Arduino (and a range of other MCU-equipped devices). These are:

### - UART
UART, or **Universal Asynchronous Receiver/Transmitter**, is a form of **serial communication** that relies on a single wire going in either direction. Since the format is asynchronous, there is no need to send a clock signal over a separate cable: data is simply transmitted at a predetermined rate (the rate in **baud**), with connected devices unpacking the data as that reach the other extreme. It is done through the **Rx** and **Tx** pins, which are used respectively to receive and transmit.

### - I2C (the communication we will use for this project)
The integrated circuit has a separate clock signal, but uses a single wire for data transmission. It's great for connecting a single master device to multiple slaves, each of which has a separate address.

I2C is also called '**TWI**', or '**two-wire interface**'. The **SCL** and **SDA** pins are on the digital pins **D1** and **D2**. As the name implies, I2C is great for connecting integrated circuits together.

### - SPI
 «**Serial peripheral interface**». It is commonly used to connect microcontrollers and other integrated circuits, such as I2C, but **uses three pins instead of just two**. It is also **full-duplex**, meaning that each **read operation is able to match a write** operation traveling in the other direction. Unlike I2C, only the master device in an SPI chain is capable of modifying the clock speed. On the NodeMCU, SPI uses three pins: **D5** is the **CLK**; **D6** is the Master In Slave Out (or **MISO**); **D7** is the Master Out Slave In (**MOSI**).

## CJMCU ADXL345 three-axis accelerometer

**Model: CJMCU ADXL345**

This module has a 3-axis ADXL335 accelerometer that allows us to measure accelerations in the +3G -3G range.

It is an analog sensor that will provide us, through 3 pins, with three voltages proportional to the acceleration of each axis.
<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/ADXL335.jpg">
</p>

This board has a built-in 3.3V voltage regulator to power the chip, so it can work with any voltage from 3.3V to 5V. However, there is no logic level conversion, so the connections I2C/SPI are at 3.3 V. Connection to a 5 V system will require a suitable logic level converter.

- Input voltage: 3.3V~5V

- Operating voltage: 2V~3.6V

- Operating current: 140uA

- Interface: I2C / SPI (5MHz)

- Self-test

- Axes x, y, z

- Internal clock frequency: 400KHz

- Sensitivity: 4 LSB/g

- Selectable sensitivity: 2g/4g/8g/16g

- Operating temperature: -40°C~85°C

- Dimensions: 19x14 mm
