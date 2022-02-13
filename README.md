# TIEMPO DE REACCIÓN
## MEDICIÓN del TR en SALIDAS de TACOS

<center>
 
 [![Alt text](https://img.youtube.com/vi/0nLaTIaZ6vY/0.jpg)](https://www.youtube.com/watch?v=0nLaTIaZ6vY)
 
<p align="center">
  
 
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/movil.png">
 
 </p>

</center>

[![LICENSE](https://img.shields.io/badge/license-MIT-lightgrey.svg)](/LICENSE.txt)

        
## Índice 

- [Intro](https://github.com/fran-byte/tiempo_reaccion/blob/main/README.md#intro)

- [Instalando la tarjeta ESP8266 en Arduino](https://github.com/fran-byte/tiempo_reaccion/blob/main/README.md#instalando-nuestra-tarjeta-esp8266-en-arduino)

- [PINOUT ESP8266](https://github.com/fran-byte/tiempo_reaccion/blob/main/README.md#pinout-datasheet)

- [CJMCU ADXL345 acelerómetro de tres ejes](https://github.com/fran-byte/tiempo_reaccion/blob/main/README.md#cjmcu-adxl345-aceler%C3%B3metro-de-tres-ejes)

- [Componentes](https://github.com/fran-byte/tiempo_reaccion/blob/main/README.md#componentes)

- [Conexiones](https://github.com/fran-byte/tiempo_reaccion/blob/main/README.md#conexiones)

- [Código](https://github.com/fran-byte/tiempo_reaccion/tree/main/code/tiempo_reaccion)

- [BETA](https://github.com/fran-byte/tiempo_reaccion/tree/main/code/tiempo_reaccion)



## Intro

Este repositorio pretende medir los tiempos de reacción y cuantificar las mejorías de explosividad en los entrenamientos de un atleta.

La salida de tacos en atletismo, se realiza en pruebas de 60/100/400 metros lisos y en 60/100/110 metros vallas (incluido el primer relevo de los 4 x 200 metros y 4 x 400 m) y no siendo utilizada para ninguna otra disciplina de mayor distancia. En las distancias más cortas, es fundamental dominar esta técnica.

El dispositivo alimentado con una bateria de 7,4V recargable estará situado en los tacos de salida y estará basado en dos componentes:

- Placa de desarrollo [**NodeMCU ESP8266**](https://github.com/fran-byte/tiempo_reaccion/blob/main/README.md#nodemcu-esp8266)
- Módulo Acelerómetro [**CJMCU ADXL345**](https://github.com/fran-byte/tiempo_reaccion/blob/main/README.md#cjmcu-adxl345-aceler%C3%B3metro-de-tres-ejes)

Utilizaremos el IDE de Arduino para programar el ESP8266.

Básicamente consistirá en un disparo simulado situado en una app/web en un móvil, dando paso a una cuenta en milisegundos.
Esta cuenta o timer será interrumpida por el movimiento (generado en los tacos de salida al impulsarse con el pie el atleta) captado en el accelerómetro ADXL335, posteriormente ese registro de tiempo lo transmitiremos de vuelta a nuestra app.

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/modulo-esp8266-esp&ADXL335jpg.jpg">
</p>


## Instalando nuestra tarjeta ESP8266 en Arduino



Este proceso es necesario para que el IDE de arduino reconozca nuestra placa de desarrollo como tarjeta:

- Verificar siempre que tenemos actualizado nuestra versión más reciente de Arduino IDE.

- A continuación vamos a Archivo/Preferencias y en la casilla  “Gestor de URLs Adicionales de Tarjetas” agregamos:

```
http://arduino.esp8266.com/stable/package_esp8266com_index.json
```
- Ahora nos vamos a Herramientas/placa: … /Gestor de Tarjetas y buscamos en el desplegable "esp8266", seleccionamos e instalamos.


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

## COMPONENTES:
- Placa de desarrollo NodeMCU ESP8266.
- Módulo Acelerómetro CJMCU ADXL345.
- Batería 7.4v.
- Resistenvia de 1KΩ.
- Transistor NPN 2N2222.
- Buzzer Piezoeléctrico 3-30V DC - 30mA 95dB

## CONEXIONES:
Conectamos el NodeMCU ESP8266 con el sensor del acelerómetro ADXL 345 utilizando una conexión **I2C**:

- Para configurar el modo **I2C** conectaremos **CS** del ADXL 345 a **3.3V** del NodeMCU ESP8266.
- PIN **D2** (SCL) del NodeMCU ESP8266 al PIN **SCL** del acelerómetro. 
- PIN **D1** (SDA) del NodeMCU ESP8266 al PIN **SDA** del acelerómetro.
- PIN **GND** del NodeMCU ESP8266 al PIN **GND** del sensor del acelerómetro.
- **Batería** de **7.4v** a entrada **Vin** del NodeMCU ESP8266.
- PIN **3.3V** del NodeMCU a **3.3V** del sensor del acelerómetro ADXL-345.
- PIN **D8 (GPIO15)** del NodeMCU ESP8266 a **Resistencia de **1 KΩ** y esta a la **Base** del transistor 2N2222.
- **Emisor** del transistor 2N2222 a **GND**.
- **Colector** del transistor 2N2222 a **Negativo del Buzzer**
- **Positivo del Buzzer** a **Vin** del NodeMCU ESP8266 **(+7.4V)**

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/circuit.jpg">
</p>

## Código

``` c
/*
  Este programa pretende medir los tiempos de reacción y cuantificar las mejorías en los entrenamientos de un atleta.
  Para ello utilizaremos una Placa de desarrollo NodeMCU ESP8266 y Módulo Acelerómetro CJMCU ADXL345
  Un Buzzer que hará las veces de pistoletazo de salida
  y todo controlado a través de un enlace WIFI y a unservidor Web
*/

#include <SparkFun_ADXL345.h> // Esta biblioteca le permite comunicar con el acelerómetro ADXL345
#include <ESP8266WebServer.h> // Biblioteca se utiliza para simplificar la creación de un servidor web.

ADXL345 adxl = ADXL345();
unsigned long timer1 = 0;
unsigned long timer2 = 0;
unsigned long tiempo_desde_disparo = 0;
int sensibilidad = 50;
unsigned long resultado = 0;
String sensibilidadSTR = " MEDIA";
int PinBUZZER = 15;                              //Definimos el pin de salida - GPIO15 / D8

const char ssid[] = "Club-Atletismo-Leganes";   //Definimos la SSDI de nuestro servidor WiFi -nombre de red-
const char password[] = "complejoeuropa";       //Definimos la contraseña de nuestro servidor
WiFiServer server(80);                          //TCPservidor en el puerto 80

// -------------------------------------------------------------------------------------------------------------
void setup() {

  Serial.begin(115200);
  Serial.println("Iniciar");
  Serial.println();

  adxl.powerOn();                               // Power on the ADXL345
  adxl.setRangeSetting(2);                      // Definir el rango del Acelerómetro, valor en 2g

  pinMode(PinBUZZER, OUTPUT);                   // Inicializamos el GPIO2 como salida (Buzzer)
  digitalWrite(PinBUZZER, LOW);                 // Dejamos inicialmente el GPIO2 apagado

  server.begin();                               // Inicializamos el servidor
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);                  // Red con clave, en el canal 1 y visible

  Serial.println();
  Serial.print("Direccion IP Access Point - por defecto: ");      //Imprime la dirección IP
  Serial.println(WiFi.softAPIP());
  Serial.print("Direccion MAC Access Point: ");                   //Imprime la dirección MAC
  Serial.println(WiFi.softAPmacAddress());

}

void beep() {
  digitalWrite(PinBUZZER, HIGH);
  delay(50);
  digitalWrite(PinBUZZER, LOW);
}
int medX() {                                    // Función que devuelve una muestra pònderada de 10 medidas del eje X

  int x, y, z;
  int mX = 0;

  for (int i = 0; i < 25; i++) {
    adxl.readAccel(&x, &y, &z);
    mX = mX + x;
  }
  mX = mX / 25;
  return mX;
}

// -------------------------------------------------------------------------------------------------------------
void loop()
{
  WiFiClient client = server.available();               // Comprueba si el cliente ha conectado
  if (!client) {
    return;
  }

  Serial.println("nuevo cliente");                      // Espera hasta que el cliente envía alguna petición

  while (!client.available()) {
    delay(1);
  }

  Serial.printf("Clientes conectados al Access Point: %dn", WiFi.softAPgetStationNum());   // Imprime el número de clientes conectados

  String peticion = client.readStringUntil('r');          // Lee la petición
  Serial.println(peticion);
  client.flush();

  int x, y, z, x1;
  String salida = "<h2>**************</h2>";


  if (peticion.indexOf('/START=L') == 11) {               // Comprueba la petición de sensibilidad
    sensibilidad = 70;
    sensibilidadSTR = "<h2 style='color:green'>Sensibilidad: BAJA</h2>";
    beep();
  }
  if (peticion.indexOf('/START=M') == 11) {
    sensibilidad = 40;
    sensibilidadSTR = "<h2 style='color:orange'>Sensibilidad: MEDIA</h2>";
    beep();
  }
  if (peticion.indexOf('/START=H') == 11) {
    sensibilidad = 28;
    sensibilidadSTR = "<h2 style='color:red'>Sensibilidad: ALTA</h2>";
    beep();
  }

  if (peticion.indexOf('/START=O') != -1) {                // Comprueba la petición de DISPARO

    digitalWrite(PinBUZZER, HIGH);                         //  Activamos el BUZZER ( DISPARO !!! )
    timer1 = millis();
    x = medX();


    // x=x-Xcal;

    while (true)                                           //Realizar este bucle mientras NO tengamos(una mínima) Accelearación en el EJE de las X
    {
      x1 = medX();
      if ((x1 - x) > sensibilidad || (x1 - x) < -sensibilidad) {  //  Accelearación +-50(Sensibilidad Media) en el EJE de las X  ******
        x1 = medX();
        timer2 = millis();
        resultado = timer2 - timer1;
        if (resultado < 100) {                              //Por debajo de 100ms en Atletismo se considera SALIDA NULA   ************
          salida = "<h2 style='color:red'>** SALIDA NULA **</h2>";
        }
        else {
          salida = "<h2 style='color:green'>* SALIDA CORRECTA *</h2>";
        }
        digitalWrite(PinBUZZER, LOW);
        break;
      }
      else
      {
        tiempo_desde_disparo = millis();
        if ((tiempo_desde_disparo - timer1) > 3000) {  // **********  Apagamos el buzzer 3 segundos después del disparo y colocamos el mensaje "SIN SALIDA"
          digitalWrite(PinBUZZER, LOW);
          salida = "<h2 style='color:pink'>- NO HUBO SALIDA -</h2>";
          resultado = 0;
          break;
        }
      }
    }
  }

  if (peticion.indexOf('START=F') != -1) {  // RESET valores
    x = 0;
    x1 = 0;
    resultado = 0;
    timer1 = 0;
    timer2 = 0;
    digitalWrite(PinBUZZER, LOW);
    String salida = "<h2>*******-******</h2>";
  }

  // *******************************************************    Envía la página HTML de respuesta al cliente
  client.println("HTTP/1.1 200 OK");
  client.println("");                                        // No olvidar esta línea de separación
  client.println("<!DOCTYPE HTML>");
  client.println("<meta charset='UTF-8'>");
  client.println("<meta name='MobileOptimized' content='width' />");
  client.println("<html>");

  client.println("<body style='background-color:black;'>");   // Web Page Heading
  client.println("<font color='grey'>");

  client.println("<center><h1 style='color:orange'>CLUB ATLETISMO</h1>");
  client.println("<center><h1 style='color:orange'>LEGANES</h1>");

  client.println("<h2>Tiempos de Reacción</h2>");
  client.println("<p><100ms: SALIDA NULA</p>");

  //client.println(x);
  client.println("<br><br>");

  client.println("<h1 style='color:yellow'>");
  client.print(resultado);                           // Mostramos el resultado, es decir el TR (Tiempo de reacción)
  client.println(" ms</h1>");
  client.println("<br><br>");
  client.println(salida);                            // Mostramos Salida NULA o CORRECTA
  client.println("<br><br>");

  //Se crean botones con estilos
  client.println("<button type='button' onClick=location.href='START=O' style='margin:auto; background-color:green; color:#A9F5A9; padding:5px; border:2px solid black; width:200;'><h2> -- GO --</h2> </button>");
  client.println("<button type='button' onClick=location.href='START=F' style='margin:auto; background-color:red; color:#F6D8CE; padding:5px; border:2px solid black; width:200;'><h2> RESET</h2> </button><br><br>");

  client.println(sensibilidadSTR);                      //Mostramos la sensibilidad del Acelerómetro

  //Se crean 3 botones para modificar la sensibilidad del Acelerómetro

  client.println("<button type='button' onClick=location.href='/START=L'> Sens BAJA </button>");
  client.println("<button type='button' onClick=location.href='/START=M'> Sens MEDIA </button>");
  client.println("<button type='button' onClick=location.href='/START=H'> Sens ALTA </button><br><br>");

  client.println("</center></font></body></html>");
  delay(1);
  Serial.println("Petición finalizada");          // Se finaliza la petición al cliente. Se inicaliza la espera de una nueva petición.
}
```
## BETA

- Foto del prototipo aún en una protoboard, Pendiente de realizar circuito y mecanizar.

<p align="center">
  <img src="https://github.com/fran-byte/tiempo_reaccion/blob/main/mdArchives/Proto.jpg">
</p>



## Licencia
[MIT](https://choosealicense.com/licenses/mit/)


