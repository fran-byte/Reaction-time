/*
  NodeMCU Access Point - Servidor Web por Dani No www.esploradores.com
  Crea un servidor Web en modo Access Point que permite encender y apagar un LED conectado a la salida D4 (GPIO02) del módulo NodeMCU.
  Este código de ejemplo es de público dominio.
*/
#include <SPI.h>
#include <Wire.h>
#include <SparkFun_ADXL345.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include <ESP8266WiFi.h>                  //Incluye la librería ESP8266WiFi

ADXL345 adxl = ADXL345();
unsigned long timer1 = 0;
unsigned long timer2 = 0;
unsigned long resultado = 0;


const char ssid[] = "NodeMCU-ESP8266";   //Definimos la SSDI de nuestro servidor WiFi -nombre de red-
const char password[] = "Itoiz222";       //Definimos la contraseña de nuestro servidor
WiFiServer server(80);                    //Definimos el puerto de comunicaciones

int PinBUZZER = 2;                           //Definimos el pin de salida - GPIO2 / D4
int estado = LOW;                         //Definimos la variable que va a recoger el estado del BUZZER

void setup() {
  Serial.begin(115200);

  Serial.println("Iniciar");
  Serial.println();

  adxl.powerOn();
  adxl.setRangeSetting(2);       //Definir el rango, valores 2, 4, 8 o 16




  pinMode(PinBUZZER, OUTPUT);                //Inicializamos el GPIO2 como salida
  digitalWrite(PinBUZZER, LOW);              //Dejamos inicialmente el GPIO2 apagado

  server.begin();                         //inicializamos el servidor
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);            //Red con clave, en el canal 1 y visible
  //WiFi.softAP(ssid, password,3,1);      //Red con clave, en el canal 3 y visible
  //WiFi.softAP(ssid);                    //Red abierta

  Serial.println();

  Serial.print("Direccion IP Access Point - por defecto: ");      //Imprime la dirección IP
  Serial.println(WiFi.softAPIP());
  Serial.print("Direccion MAC Access Point: ");                   //Imprime la dirección MAC
  Serial.println(WiFi.softAPmacAddress());

  //IPAddress local_ip(192, 168, 1, 1);                           //Modifica la dirección IP
  //IPAddress gateway(192, 168, 1, 1);
  //IPAddress subnet(255, 255, 255, 0);
  //WiFi.softAPConfig(local_ip, gateway, subnet);
  //Serial.println();
  //Serial.print("Access Point - Nueva direccion IP: ");
  //Serial.println(WiFi.softAPIP());
}


int medX() {
  int x, y, z;
  int mX = 0;
  for (int i = 0; i < 10; i++) {
    adxl.readAccel(&x, &y, &z);
    mX = mX + x;
  }
  mX = mX / 10;
  return mX;
}


void loop()
{
  // Comprueba si el cliente ha conectado
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Espera hasta que el cliente envía alguna petición
  Serial.println("nuevo cliente");
  while (!client.available()) {
    delay(1);
  }

  // Imprime el número de clientes conectados
  Serial.printf("Clientes conectados al Access Point: %dn", WiFi.softAPgetStationNum());

  // Lee la petición
  String peticion = client.readStringUntil('r');
  Serial.println(peticion);
  client.flush();





  // **********************************************************************************************************
  int x, y, z, x1;


  // Comprueba la petición
  if (peticion.indexOf('/START=ON') != -1) {

    estado = HIGH;

    timer1 = millis();
    x = medX();


    // x=x-Xcal;

    while (true)//  ******************** MIENTRAS NO TE MUEVAS  ************
    {
      x1 = medX();
      if ((x1 - x) > 50 || (x1 - x) < -50) {
        x1 = medX();
        timer2 = millis();
        resultado = timer2 - timer1;
        break;
      }
    }



  }

  if (peticion.indexOf('/START=OFF') != -1) {
    estado = LOW;
    x = 0;
    x1 = 0;
    y = 0;
    z = 0;
    resultado = 0;
    timer1 = 0;
    timer2 = 0;
  }


  digitalWrite(PinBUZZER, estado);    //Enciende o apaga el BUZZER en función de la petición

  // Envía la página HTML de respuesta al cliente
  client.println("HTTP/1.1 200 OK");
  client.println("");                                     //No olvidar esta línea de separación
  client.println("<!DOCTYPE HTML>");
  client.println("<meta charset='UTF-8'>");
  client.println("<html>");


  // Web Page Heading
  client.println("<h1>CLUB ATLETISMO LEGANES</h1>");

  client.println("<h2>Tiempos de Reacción</h2>");
  client.println("<p>- Salida de Tacos -</p>");

  client.println("<p>Tiempo menor a 100ms: SALIDA NULA</p>");

  client.println(x);
  client.println("<br><br>");
  client.println(y);
  client.println("<br><br>");
  client.println(z);
  client.println("<br><br>");

  client.println(resultado);
client.println("<br><br>");



  //Se crean botones con estilos
  client.println("<button type='button' onClick=location.href='/START=ON' style='margin:auto; background-color:green; color:#A9F5A9; padding:5px; border:2px solid black; width:200;'><h2> GO</h2> </button>");
  client.println("<button type='button' onClick=location.href='/START=OFF' style='margin:auto; background-color:red; color:#F6D8CE; padding:5px; border:2px solid black; width:200;'><h2> RESET</h2> </button><br><br>");


  client.println("</html>");
  delay(1);
  Serial.println("Petición finalizada");          // Se finaliza la petición al cliente. Se inicaliza la espera de una nueva petición.

}
