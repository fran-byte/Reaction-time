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

## Desgranando el ESP8266

El ESP8266 normalmente viene integrado en un módulo. Esto es debido a que el propio SoC ESP8266 no tiene memoria Flash integrada. El primero que vio la luz fue el ESP-01 el cual estaba pensado para funcionar como interfaz WiFi de las placas de Arduino. Sin embargo, enseguida se hizo muy popular en la comunidad Maker.

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/250px-ESP-01.jpg"><img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/ESP8266 pla.jpg">
</p>


A partir de este módulo surgieron muchos más hasta que finalmente irrumpió en el mercado el ESP-12, el más popular de todos los módulos. Este módulo se utiliza en multitud de placas siendo las más famosas NodeMCU y Wemos.

## NodeMCU ESP8266
Es una plataforma de desarrollo similar a Arduino y orientada a IoT (Internet de las cosas).
La placa **NodeMcu v2 ESP8266** tiene como núcleo al SoM ESP-12E que a su vez está basado en el SoC Wi-Fi ESP8266, integra además el conversor **USB-Serial TTL CP2102** y conector micro-USB necesario para la programación y comunicación a PC.

Está diseñado especialmente para trabajar montado en protoboard o soldado sobre una placa. Posee un regulador de voltaje de 3.3V en placa, esto permite alimentar la placa directamente del puerto micro-USB o por los pines 5V y GND. **Los pines de entradas/salidas (GPIO) trabajan a 3.3V** por lo que para conexión a sistemas de 5V es necesario utilizar conversores


**ESPECIFICACIONES TÉCNICAS:**
- Voltaje de Alimentación: 4.5V~9V (10VMAX) y/o alimentación por USB
- Voltaje de Entradas/Salidas: 3.3V DC (**No usar 5V**)
- Corriente nominal por pin: 12mA
- Placa: NodeMCU v2 (Amica)
- Chip conversor USB-serial: CP2102
- SoM: ESP-12E (Ai-Thinker)
- SoC: ESP8266 (Espressif)
- CPU: Tensilica Xtensa LX3 (32 bit)
- Frecuencia de Reloj: 80MHz/160MHz
- Instruction RAM: 32KB
- Data RAM: 96KB
- Memoria Flash Externa: 4MB
- Pines Digitales GPIO: 17 (4 pueden configurarse como PWM a 3.3V)
- Pin Analógico ADC: 1 (0-1V)
- Puerto Serial UART: 2
- Certificación FCC
- Antena en PCB
- 802.11 b/g/n
- Wi-Fi Direct (P2P), soft-AP
- Stack de Protocolo TCP/IP integrado
- PLLs, reguladores, DCXO y manejo de poder integrados
- Potencia de salida de +19.5dBm en modo 802.11b
- Corriente de fuga menor a 10uA
- STBC, 1×1 MIMO, 2×1 MIMO
- A-MPDU & A-MSDU aggregation & 0.4ms guard interval
- Wake up and transmit packets in < 2ms
- Consumo de potencia Standby < 1.0mW (DTIM3)
- Pulsador RESET y FLASH
- Led indicadores: 2
- Dimensiones: 49*26*12 mm
- Peso: 9 gramos
 
**CONECTIVIDAD**

- SDIO 2.0, SPI, UART
- Integra RF switch, balun, 24dBm PA, DCXO y PMU
- Posee un procesador RISC, memoria en chip e interface para memoria externa
- Procesador MAC/Baseband integrado
- Interface I2S para apliaciones de audio de alta calidad
- Reguladores de voltaje lineales "low-dropout" en chip
- Arquitectura propietaria de generacion de clock "spurious free"
- Módulos WEP, TKIP, AES y WAPI integrados


## PINOUT datasheet

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/ESP-12E-Development-Board-ESP8266-NodeMCU-Pinout.png">
</p>

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/ESP8266 varias.jpg">
</p>

## Pines PWM
Notarás que algunos de los pines digitales vienen con la funcionalidad de **Modulación de Ancho de Pulso**, o **PWM**. Esto nos proporciona un medio de simular una señal analógica usando una serie rápida de pulsos digitales.

Las señales PWM se usan comúnmente para controlar motores.

Se podría hacer esto usando cualquiera de las salidas digitales de la MCU escribiendo un ciclo de código que haga un ciclo rápido de encendido y apagado de un pin determinado, pero esto interferiría con el programa principal y consumiría recursos valiosos.

Una mejor solución es usar una de las salidas PWM separadas, que se encargará de todos los ciclos por ti una vez que hayan recibido un valor.

Puedes escribir un valor en un PWM usando la función **analogWrite()**. Asegúrate de que has seleccionado una salida compatible con **PWM**.

En el NodeMCU, estos son D2, D5, D6 y D8.

## Comunicación
El NodeMCU soporta los tres principales protocolos de comunicación en serie que se encuentran en el Arduino (y una gama de otros dispositivos equipados con MCU). Estos son:

### - UART
UART, o **Receptor/Transmisor Asíncrono Universal**, es una forma de **comunicación en serie** que depende de que un solo cable vaya en cualquier dirección. Dado que el formato es asíncrono, no hay necesidad de enviar una señal de reloj por un cable separado: los datos se transmiten simplemente a una velocidad predeterminada (la velocidad en **baudios**), con los dispositivos conectados desempaquetando los datos a medida que llegan al otro extremo. Se hace a través de los pines **Rx** y **Tx**, que se utilizan respectivamente para recibir y transmitir.

### - I2C  (la comunicación que usaremos para este proyecto)
El circuito integrado tiene una señal de reloj separada, pero usa un solo cable para la transmisión de datos. Es genial para conectar un único dispositivo maestro a múltiples esclavos, cada uno de los cuales tiene una dirección separada.

I2C también se llama ‘**TWI**’, o ‘**interfaz de dos cables**’. Los pines **SCL** y **SDA** están en los pines digitales **D1** y **D2**. Como su nombre lo indica, I2C es genial para conectar circuitos integrados entre sí.

### - SPI
 «**Interfaz periférica en serie**». Se usa comúnmente para conectar microcontroladores y otros circuitos integrados, como el I2C, pero **usa tres pines en lugar de sólo dos**. También es **full-dúplex**, lo que significa que cada operación de **lectura es capaz de coincidir con una operación de escritura** que viaja en la otra dirección. A diferencia del I2C, sólo el dispositivo maestro de una cadena SPI es capaz de modificar la velocidad del reloj. En el NodeMCU, SPI utiliza tres pines: **D5** es el **CLK**; **D6** es el Master In Slave Out (o **MISO**); **D7** es el Master Out Slave In (**MOSI**).

## CJMCU ADXL345 acelerómetro de tres ejes

**Modelo: CJMCU ADXL345**

Este módulo tiene un acelerómetro ADXL335 de 3 ejes que nos permite medir aceleraciones del rango de +3G -3G.

Se trata de un sensor analógico que nos proporcionará mediante 3 pines, tres voltajes proporcionales a la aceleración de cada eje.

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/ADXL335.jpg">
</p>

Esta placa tiene un regulador de voltaje de 3,3 V incorporado para alimentar el chip, por lo que puede funcionar con cualquier voltaje de 3,3 V a 5 V. Sin embargo, no hay conversión de nivel lógico, por lo que las conexiones I2C/SPI están a 3,3 V. La conexión a un sistema de 5 V requerirá un convertidor de nivel lógico adecuado.

- Voltaje de entrada: 3.3V~5V

- Voltaje de operación: 2V~3.6V

- Corriente de operación: 140uA

- Interfaz:  I2C / SPI (5MHz)

- Auto-test

- Ejes x, y, z

- Frecuencia de reloj interna:  400KHz

- Sensibilidad:  4 LSB/g

- Sensibilidad seleccionable:  2g/4g/8g/16g

- Temperatura de operación: -40°C~85°C

- Dimensiones:  19x14 mm


