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

- Es necesario para que el IDE de arduino reconozca nuestra placa de desarrollo como tarjeta.

- Verificar siempre que tenemos actualizado nuestra versión más reciente de Arduino IDE.

- A continuación vamos a archivo/Preferencias y en la casilla  “Gestor de URLs Adicionales de Tarjetas” agregamos:

http://arduino.esp8266.com/stable/package_esp8266com_index.json

- Ahora nos vamos a Herramientas/placa: … /Gestor de Tarjetas y buscamos en el desplegable "esp8266 by ESP8266 Community", seleccionamos e instalamos.

---

## Autor ️
<img src="mdArchives/logo.png"/> **fran-byte**



## Licencia
[MIT](https://choosealicense.com/licenses/mit/)

---
