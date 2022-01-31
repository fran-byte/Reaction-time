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
Características importantes de los microcontroladores como GPIO, PWM, ADC... 
puede resolver muchas de las necesidades del proyecto por sí mismo.

Características generales:

Fácil aprendizaje
Programación a través de Arduino IDE o IUA
Disponible como punto de acceso, estación practicable en apps de API impulsadas por eventos
Atena interna
13 pines GPIO
10 canales PWM
I2C
SPI
ADC
UART
1-Wire

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/gpio-nodemcu-esp8266.svg">
</p>


---

## Autor ️
<img src="mdArchives/logo.png"/> **fran-byte**



## Licencia
[MIT](https://choosealicense.com/licenses/mit/)

---
