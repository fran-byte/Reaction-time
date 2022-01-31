#include <SPI.h>
#include <Wire.h>
#include <SparkFun_ADXL345.h> 

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

ADXL345 adxl = ADXL345();

const unsigned long intervaloLecturaTemp = 200; // leeremos cada ... milisegundos  (Evito usar la función delay)
unsigned long tiempoAnterior = 0; // almacena la ultima vez que se lanzo nuestro evento

void setup() 
{
   Serial.begin(9600);             
   Serial.println("Iniciar");
   Serial.println();

   adxl.powerOn();            
   adxl.setRangeSetting(16);       //Definir el rango, valores 2, 4, 8 o 16
}

void loop() 
{
   //leer los valores e imprimirlos
   unsigned long tiempoActual = millis();
  if (tiempoActual - tiempoAnterior >= intervaloLecturaTemp)  {
       int x, y, z;
       adxl.readAccel(&x, &y, &z);  
       Serial.print(x);
       Serial.print(", ");
       Serial.print(y);
       Serial.print(", ");
       Serial.println(z); 
       tiempoAnterior = tiempoActual;
   }
}
