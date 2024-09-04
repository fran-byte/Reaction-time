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

## CONNECTIONS:
We connect the NodeMCU ESP8266 with the ADXL 345 accelerometer sensor using an **I2C** connection:

- To configure the **I2C** mode, connect the **CS** of the ADXL 345 to the **3.3V** of the NodeMCU ESP8266.
- PIN **D2** (SCL) of the NodeMCU ESP8266 to the **SCL** PIN of the accelerometer.
- PIN **D1** (SDA) of the NodeMCU ESP8266 to the **SDA** PIN of the accelerometer.
- PIN **GND** of the NodeMCU ESP8266 to the **GND** PIN of the accelerometer sensor.
- Connect the **Vin** and **Collector** PINs of the Opto to the **+8.4V** battery.
- Connect the Buzzer through an Optocoupler to avoid interferences.

## Code

- Available here: [Link](https://github.com/fran-byte/tiempo_reaccion/tree/main/code/tiempo_reaccion)

## BETA

- Photo of the prototype still on a breadboard, pending to make the circuit and machine it.

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

## PINOUT datasheet

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/ESP-12E-Development-Board-ESP8266-NodeMCU-Pinout.png">
</p>

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/ESP8266 varias.jpg">
</p>
