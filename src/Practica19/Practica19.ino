/*
 * Project Práctica 18
 * Description: Utilización de relevador.
 * Author: Javier Sánchez
 * Date: Noviembre 11, 2020.
 */
#include <Adafruit_DHT.h> // DHT library

/* Constantes donde almacenar la ruta y el tipo del sensor digital */
#define DHTPIN D3
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

/* Variables donde almacenar las lecturas del sensor digital */
double gradosCelsius = 0;
double humedad = 0;
double gradosFarenheit = 0;

int milisegundos = 1000;

void setup()
{
  pinMode(D3, INPUT); // Estableciendo el pin D3 como salida
  dht.begin();        // Inicializando el sensor en el pin establecido (D3)
  Serial.begin(9600); // Inicializando el puerto Serial
}

void loop()
{
  gradosCelsius = dht.getTempCelcius();     //Obtener la temperatura en °C
  gradosFarenheit = dht.getTempFarenheit(); //Temperatura en °F
  humedad = dht.getHumidity();              //Obtenemos la humedad en %

  if (isnan(gradosCelsius) || isnan(humedad) || isnan(gradosFarenheit)) // En caso de recibir un valor incorrecto en el puerto serial
  {
    Serial.println("Error de lectura de datos"); // Se imprime el error a serial
    return;                                      // Y se continua el ciclo
  }
  Serial.print("La temperatura actual es ");
  Serial.print(gradosCelsius);
  Serial.print("°C, equivalente a ");
  Serial.print(gradosFarenheit);
  Serial.print("F° con ");
  Serial.print(humedad);
  Serial.println("% de humedad");
  delay(milisegundos);
}