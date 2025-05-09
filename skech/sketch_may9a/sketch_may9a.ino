// Medición de temperatura y humedad con sensor DHT22 o DHT11.
// Desarrollo totalmente compatible para ambos sensores.
// Revisar diferencias.
// El fabricante indica que se debe colocar una resistencia de pull up de aproximadamente 4.7 kOhm
// "pull up" --> conectarse a tensión. "pull down" --> a masa.
// Notar que por un único pin se reciben los valores de temperatura y humedad
// Hay librerías que facilitan enormemente el uso de este sensor. Se deben instalar.
#include <DHT.h>
#include <DHT_U.h>

int SENSOR = 2;
int TEMPERATURA;
int HUMEDAD;

// Se crea un objeto del tipo dht para obtener las funciones
// asociadas al sensor. En este caso nuestro objeto se llama "dht".
DHT dht (SENSOR, DHT11);

void setup(){
  Serial.begin(9600);   // Se inicializa la comunicación serial
  dht.begin();          // Se inicializa el sensor
  // pinMode(SENSOR);    
}

void loop(){
  // Se obtiene el valor de temperatura que lee el sensor.
  // Aquí se ve la importancia de las librerías.
  float TEMPERATURA = dht.readTemperature();

  // Se lee la humedad que lee el sensor
  float HUMEDAD = dht.readHumidity();

  // Se imprimen en el monitor serial las mediciones
  Serial.print("Temperatura: ");
  Serial.print(TEMPERATURA);
  Serial.print(" Humedad: ");
  Serial.println(HUMEDAD);      // Este da un salto de línea
  delay(2000);
}