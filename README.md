# TIEMPO REACCIÓN EN SALIDAS DE TACOS
# CARRERAS DE VELOCIDAD - ATLETISMO

[![LICENSE](https://img.shields.io/badge/license-MIT-lightgrey.svg)](/LICENSE.txt)

📕  [DOC](/doc)         📕  [CODE](/code)         📕  [IMG](/img)        


Este repositorio pretende ser un proyecto de ayuda al entrenamiento de las salidas de tacos en carreras en atletismo, un intento de acercamiento a los sistemas profesionales, salvando siempre las distancias. Tiene como propósito medir los tiempos de reacción y cuantificar las mejorías en el atleta.




<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/tacos_salida.jpg">
</p>


---
# Funcionamiento

El sistema se basará en dos componentes un acelerómetro ADXL335 y una placa de desarrollo ESP8266.
Utilizaremos el IDE de Arduino para programar el ESP8266.

Básicamente consistirá en un disparo simulado, que incluiremos en una app por bluetooth en un simple teléfono móvil, dando paso a una cuenta en milisegundos y viendose esta interrumpida por el movimiento captado en elaccelerómetro ADXL335 generado en uno de los tacos de salida al darse impulso con el pie el atleta, capturaremos ese tiempo y lo transmitiremos de vuelta a nuestra app.

---

## Autor ️
<img src="mdArchives/logo.png"/> **fran-byte**



## Licencia
[MIT](https://choosealicense.com/licenses/mit/)

---
