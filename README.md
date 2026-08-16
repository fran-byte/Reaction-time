
# 🏃 TIEMPO DE REACCIÓN (T.R.)
### *Medición del TR en Salidas de Tacos*

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE.txt)
[![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D?logo=arduino)](https://www.arduino.cc/)
[![ESP8266](https://img.shields.io/badge/ESP8266-NodeMCU-1C9E3A?logo=espressif)](https://www.espressif.com/)
[![Version](https://img.shields.io/badge/version-2.0-brightgreen)](https://github.com/fran-byte/tiempo_reaccion)
[![Status](https://img.shields.io/badge/status-Beta-yellow)](https://github.com/fran-byte/tiempo_reaccion)

---

## 📖 Índice

- [🎯 Descripción del Proyecto](#-descripción-del-proyecto)
- [⚙️ Funcionamiento](#️-funcionamiento)
- [🔧 Instalación de la ESP8266 en Arduino](#-instalación-de-la-esp8266-en-arduino)
- [📡 PINOUT ESP8266](#-pinout-esp8266)
- [📦 Componentes](#-componentes)
- [🔌 Conexiones](#-conexiones)
- [💻 Código](#-código)
- [🧪 BETA](#-beta)
- [🔋 Nivel de Batería (Extra)](#-nivel-de-batería-extra)
- [🧠 Desgranando el ESP8266](#-desgranando-el-esp8266)
- [📜 Licencia](#-licencia)

---

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/giphy.gif" alt="Demo del dispositivo" width="600">
</p>

---

## 🎯 Descripción del Proyecto

Este repositorio tiene como objetivo **medir los tiempos de reacción** y cuantificar las mejorías de **explosividad** en entrenamientos de atletismo.

> La salida de tacos se utiliza en pruebas de:
> - 🏃 60m / 100m / 400m lisos
> - 🏃 60m / 100m / 110m vallas
> - 🏃 4x200m / 4x400m (primer relevo)

**Dominar esta técnica es fundamental** en distancias cortas.

---

## ⚙️ Funcionamiento

### 📶 Conectando con el dispositivo

1. **Conexión WiFi**  
   Conéctate a la red: `Club-Atletismo-Leganes`  
   *(El dispositivo no tiene acceso a internet, confirma que quieres permanecer en esta red)*

2. **Acceso a la Web**  
   Abre tu navegador y ve a:  
   `http://192.168.4.1/START=O`

   > 🔔 Al conectarte, el dispositivo realizará un **disparo de prueba**. Si escuchas el pitido del **buzzer**, la conexión fue exitosa.

3. **Interfaz de usuario**  
   <p align="center">
     <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/wifi2.png" alt="Interfaz Web" width="400">
   </p>

   Desde la pantalla podrás:
   - ✅ Seleccionar **sensibilidad**
   - ✅ **Resetear** parámetros
   - ✅ Calibrar con desviación (temporal)
   - ✅ Pulsar **GO** para iniciar el disparo

4. **Disparo**  
   - El botón **GO** activa el disparo con **retardo** (para capturar movimientos previos)
   - La salida es **NULA** si ocurre antes del disparo o en menos de **100ms**

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/false_start.gif" alt="False Start" width="400">
</p>

---

## 🔧 Instalación de la ESP8266 en Arduino

1. **Abre Arduino IDE** (versión más reciente)

2. **Agrega el gestor de URLs**  
   Ve a `Archivo > Preferencias` y añade:
   ```
   http://arduino.esp8266.com/stable/package_esp8266com_index.json
   ```

3. **Instala la placa**  
   Ve a `Herramientas > Placa > Gestor de Tarjetas`  
   Busca **esp8266** e instala.

---

## 📡 PINOUT ESP8266

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/ESP-12E-Development-Board-ESP8266-NodeMCU-Pinout.png" alt="Pinout ESP8266" width="500">
</p>

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/ESP8266 varias.jpg" alt="ESP8266 Varios" width="500">
</p>

---

## 📦 Componentes

| Componente | Cantidad | Descripción |
|------------|----------|-------------|
| NodeMCU ESP8266 | 1 | Placa de desarrollo |
| CJMCU ADXL345 | 1 | Acelerómetro 3 ejes |
| Batería 8.4V | 1 | Recargable (de foco de bicicleta) |
| Resistencia 1KΩ | 1 | Para optoacoplador |
| Optoacoplador PC817 | 1 | Aislamiento eléctrico |
| Buzzer piezoeléctrico | 1 | 3-30V DC, 30mA, 95dB |

> ⚠️ **IMPORTANTE:**  
> El **buzzer NO debe soldarse en la misma placa del acelerómetro**, ya que las vibraciones pueden activar falsas lecturas.  
> Colócalo sobre una **almohadilla** o en una **caja separada**.

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/componentes.jpg" alt="Componentes" width="500">
</p>

---

## 🔌 Conexiones

### 📐 Esquema I2C

| Componente | Pin | Conectar a |
|------------|-----|------------|
| ADXL345 | CS | 3.3V (ESP8266) |
| ADXL345 | SCL | D2 (ESP8266) |
| ADXL345 | SDA | D1 (ESP8266) |
| ADXL345 | GND | GND (ESP8266) |
| Optoacoplador | Vin / Colector | Batería +8.4V |

> 🧠 El **buzzer** se conecta a través del **optoacoplador** para evitar interferencias.

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/conectividades.jpg" alt="Conexiones" width="500">
</p>

---

## 💻 Código

El código completo está disponible en:  
👉 [Code / tiempo_reaccion](https://github.com/fran-byte/tiempo_reaccion/tree/main/code/tiempo_reaccion)

---

## 🧪 BETA

> 📸 Prototipo actual montado en **protoboard**. Próximamente: circuito mecanizado.

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/Proto.jpg" alt="Prototipo" width="400">
</p>

---

## 🔋 Nivel de Batería (Extra)

### 📊 Medición Analógica

Se puede añadir una variable en el HTML para visualizar el nivel de batería usando el **GPIO12** como entrada analógica.

#### ⚡ Divisor de Tensión

Dado que la batería es de **8-10V** y el ESP8266 solo admite **3.3V**, usamos un divisor de tensión:

```
Tensión de entrada → 49KΩ → GPIO12
                      |
                    10KΩ
                      |
                     GND
```

#### 📐 Cálculo

- Referencia: 3.3V / 1023 = **0.0032258** por unidad
- Multiplicador: 100% / 20.408% = **4.9**

#### 💻 Código de ejemplo

```cpp
void leer_voltios() {
    float voltios;
    voltios = (analogRead(12)) * 0.003225806452 * 4.9;
    
    if (voltios <= 5.50) {
        battery = "<h2 style='color:red'>BATERÍA ⚡</h2>";
    } else if (voltios > 5.50 && voltios < 6.60) {
        battery = "<h2 style='color:orange'>BATERÍA ⚡⚡⚡</h2>";
    } else {
        battery = "<h2 style='color:green'>BATERÍA ⚡⚡⚡⚡⚡</h2>";
    }
}
```

---

## 🧠 Desgranando el ESP8266

### 📌 ¿Qué es el ESP8266?

El **ESP8266** es un SoC (System on Chip) con **WiFi integrado**. Originalmente diseñado como interfaz WiFi para Arduinos, se popularizó rápidamente en la comunidad maker.

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/250px-ESP-01.jpg" alt="ESP-01" width="200">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/ESP8266 pla.jpg" alt="ESP8266" width="200">
</p>

### 📟 NodeMCU ESP8266

Placa de desarrollo orientada a **IoT**, basada en el módulo **ESP-12E**.

#### 🔧 Especificaciones Técnicas

| Característica | Detalle |
|----------------|---------|
| Voltaje Alimentación | 4.5V~9V (máx 10V) o USB |
| Voltaje I/O | 3.3V (NO usar 5V) |
| Corriente por pin | 12mA |
| Procesador | Tensilica Xtensa LX3 (32-bit) |
| Frecuencia | 80MHz / 160MHz |
| Memoria Flash | 4MB |
| GPIO | 17 (4 con PWM) |
| ADC | 1 (0-1V) |
| WiFi | 802.11 b/g/n |
| Dimensiones | 49x26x12mm |
| Peso | 9g |

---

### 📡 Comunicación

El NodeMCU soporta los principales protocolos:

| Protocolo | Pines | Descripción |
|-----------|-------|-------------|
| **UART** | Rx / Tx | Comunicación serie asíncrona |
| **I2C** ⭐ | D1 (SDA) / D2 (SCL) | El que usamos en este proyecto |
| **SPI** | D5 (CLK) / D6 (MISO) / D7 (MOSI) | Full-duplex, 3 pines |

> ⭐ **I2C** es ideal para conectar el acelerómetro porque usa solo 2 cables.

---

## 🏆 Tiempos de Reacción en Tokio 2021

| Nivel | Tiempo |
|-------|--------|
| Aceptable | < 200ms |
| Bueno | < 170ms |
| **Excelente** | **< 145ms** |

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/TR Tokio2.png" alt="Tiempos Tokio 2021" width="500">
</p>

---

## 📜 Licencia

Este proyecto está bajo la licencia **MIT**.  
[Ver licencia completa](LICENSE.txt)

---

## 🤝 Contribuciones

¿Quieres mejorar este proyecto?  
¡Las **issues** y **pull requests** son bienvenidas!

---

⭐ **Si te gusta este proyecto, no olvides darle una estrella en GitHub!** ⭐

---

