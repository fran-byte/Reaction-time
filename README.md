# TIEMPO REACCIÓN EN SALIDAS DE TACOS (En proyecto)
# CARRERAS DE VELOCIDAD - ATLETISMO

[![LICENSE](https://img.shields.io/badge/license-MIT-lightgrey.svg)](/LICENSE.txt)

📕  [DOC](/doc)         📕  [CODE](/code)         📕  [IMG](/img)        


Este repositorio pretende ser un proyecto de ayuda al entrenamiento de las salidas de tacos en carreras en atletismo, un intento de acercamiento a los sistemas profesionales, salvando siempre las distancias. Tiene como propósito medir los tiempos de reacción y cuantificar las mejorías en el atleta.




<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/tacos_salida.jpg">
</p>



---
# Funcionamiento

El sistema se basará en dos componentes:
- Una placa de desarrollo ESP8266.
- Un acelerómetro ADXL335.

Utilizaremos el IDE de Arduino para programar el ESP8266.

Básicamente consistirá en un disparo simulado, que incluiremos en una app por wifi en un simple teléfono móvil, dando paso a una cuenta en milisegundos.
Esta cuenta será interrumpida por el movimiento (generado en uno de los tacos de salida al darse impulso con el pie el atleta) captado en el accelerómetro ADXL335, posteriormente ese registro de tiempo lo transmitiremos de vuelta a nuestra app.

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/modulo-esp8266-esp&ADXL335jpg.jpg">
</p>

---

# Diagrama

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/diag.jpg">
</p>

---

# Instalando nuestra tarjeta ESP8266 en Arduino



Este proceso es necesario para que el IDE de arduino reconozca nuestra placa de desarrollo como tarjeta:

- Verificar siempre que tenemos actualizado nuestra versión más reciente de Arduino IDE.

- A continuación vamos a Archivo/Preferencias y en la casilla  “Gestor de URLs Adicionales de Tarjetas” agregamos:

```
http://arduino.esp8266.com/stable/package_esp8266com_index.json
```
- Ahora nos vamos a Herramientas/placa: … /Gestor de Tarjetas y buscamos en el desplegable "esp8266", seleccionamos e instalamos.

---

# Desgranando el ESP8266

El ESP8266 normalmente viene integrado en un módulo. Esto es debido a que el propio SoC ESP8266 no tiene memoria Flash integrada. El primero que vio la luz fue el ESP-01 el cual estaba pensado para funcionar como interfaz WiFi de las placas de Arduino. Sin embargo, enseguida se hizo muy popular en la comunidad Maker.

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/250px-ESP-01.jpg"><img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/ESP8266 pla.jpg">
</p>


A partir de este módulo surgieron muchos más hasta que finalmente irrumpió en el mercado el ESP-12, el más popular de todos los módulos. Este módulo se utiliza en multitud de placas siendo las más famosas NodeMCU y Wemos.

# NodeMCU ESP8266
Plataforma de código abierto que puede conectar objetos y permitir transferencia de datos utilizando protocolo Wi-Fi.

Características generales:

- Fácil aprendizaje
- Programación a través de Arduino IDE o IUA
- Disponible como punto de acceso, estación practicable en apps de API impulsadas por eventos
- Atena interna
- Voltaje : 3.0 ~ 3.6V
- Corriente: 80mA
- CPU Tensilica Xtensa LX106 de 32 bits RISC que funciona a 80 MHz
- 16 Pines GPIO
- SPI
- I2C
- I2S
- UART – 2x TX y 1x RX
- 1x 10bit ADC
- Temperatura de funcionamiento : -40°C ~ 125°C
- Rango de frecuencia: 2400 ~ 2483.5MHz

# PINOUT datasheet

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/gpio-nodemcu-esp8266.svg">
</p>

## Pines PWM
Notarás que algunos de los pines digitales vienen con la funcionalidad de Modulación de Ancho de Pulso, o PWM. Esto nos proporciona un medio de simular una señal analógica usando una serie rápida de pulsos digitales. Cuanto más larga sea la parte «on» de estos ciclos, más fuerte parecerá la señal.

Así que, si enciendes y apagas un LED rápidamente, cuanto más largo sea el ciclo de encendido, más brillante parecerá el LED.

Las señales PWM también se usan comúnmente para controlar motores. Cuanto más alta sea la función PWM, más potencia se transmitirá al motor.

Se podría hacer esto usando cualquiera de las salidas digitales de la MCU escribiendo un ciclo de código que haga un ciclo rápido de encendido y apagado de un pin determinado, pero esto interferiría con el programa principal y consumiría recursos valiosos.

Una mejor solución es usar una de las salidas PWM separadas, que se encargará de todos los ciclos por ti una vez que hayan recibido un valor.

Puedes escribir un valor en un PWM usando la función analogWrite(). Asegúrate de que has seleccionado una salida compatible con PWM.

En el NodeMCU, estos son D2, D5, D6 y D8.

## Comunicación
El NodeMCU soporta los tres principales protocolos de comunicación en serie que se encuentran en el Arduino (y una gama de otros dispositivos equipados con MCU). Estos son:

### - UART
UART, o Receptor/Transmisor Asíncrono Universal, es una forma de comunicación en serie que depende de que un solo cable vaya en cualquier dirección. Dado que el formato es asíncrono, no hay necesidad de enviar una señal de reloj por un cable separado: los datos se transmiten simplemente a una velocidad predeterminada (la velocidad en baudios), con los dispositivos conectados desempaquetando los datos a medida que llegan al otro extremo. En el NodeMCU, la UART se hace a través de los pines Rx y Tx, que se utilizan respectivamente para recibir y transmitir.

### - I2C
El circuito integrado tiene una señal de reloj separada, pero usa un solo cable para la transmisión de datos. Es genial para conectar un único dispositivo maestro a múltiples esclavos, cada uno de los cuales tiene una dirección separada.

I2C también se llama ‘TWI’, o ‘interfaz de dos cables’. Los pines SCL y SDA están en los pines digitales D1 y D2. Como su nombre lo indica, I2C es genial para conectar circuitos integrados entre sí.

### - SPI
Nuestra tercera variedad de comunicación en serie es SPI, o «interfaz periférica en serie». Se usa comúnmente para conectar microcontroladores y otros circuitos integrados, como el I2C, pero usa tres pines en lugar de sólo dos. También es full-dúplex, lo que significa que cada operación de lectura es capaz de coincidir con una operación de escritura que viaja en la otra dirección. A diferencia del I2C, sólo el dispositivo maestro de una cadena SPI es capaz de modificar la velocidad del reloj. En el NodeMCU, SPI utiliza tres pines: D5 es el CLK; D6 es el Master In Slave Out (o MISO); D7 es el Master Out Slave In (MOSI).

---

## Autor ️
<img src="mdArchives/logo.png"/> **fran-byte**



## Licencia
[MIT](https://choosealicense.com/licenses/mit/)

---
