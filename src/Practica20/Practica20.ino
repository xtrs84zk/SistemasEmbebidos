/*
 * Project Práctica 20
 * Description: Utilización de relevador.
 * Author: Javier Sánchez
 * Date: Noviembre 11, 2020.
 */

#include <Adafruit_DHT.h> // DHT library

/* Constantes donde almacenar la ruta y el tipo del sensor digital */
#define DHTPIN D3
#define DHTTYPE DHT11
#define RELAY D2

DHT dht(DHTPIN, DHTTYPE); // Inicializando el objeto DHT

/* Variables donde almacenar las lecturas del sensor digital */
double gradosCelsius = 0;
double humedad = 0;
double gradosFarenheit = 0;

int milisegundos = 200;

void setup()
{
    pinMode(RELAY, OUTPUT);                                         // Establece el pin en que está el relay como salida
    pinMode(DHTPIN, INPUT);                                         // Estableciendo el pin del DHT como entrada
    dht.begin();                                                    // Inicializando el sensor en el pin establecido (D3)
    Particle.variable("gradosCelsius", &gradosCelsius, DOUBLE);     // Se declara gradosCelsius como una variable accesible desde la nube
    Particle.variable("humedad", &humedad, DOUBLE);                 // Se declara humedad como una variable accesible desde la nube
    Particle.variable("gradosFarenheit", &gradosFarenheit, DOUBLE); // Se declara gradosFarenheit como una variable accesible desde la nube
}

void loop()
{
    gradosCelsius = dht.getTempCelcius();     //Obtener la temperatura en °C
    gradosFarenheit = dht.getTempFarenheit(); //Temperatura en °F
    humedad = dht.getHumidity();              //Obtenemos la humedad en %

    if (isnan(gradosCelsius) || isnan(humedad) || isnan(gradosFarenheit)) // En caso de recibir un valor incorrecto en el puerto serial
    {
        return; // Se continua el ciclo
    }
    else
    {
        if (gradosCelsius > 20)
        { // If temp > 20 turn on light bulb
            digitalWrite(RELAY, HIGH);
        }
        else if (gradosCelsius < 18)
        { // If temp < 18 turn off light bulb
            digitalWrite(RELAY, LOW);
        } else {
            // omg, el limbo
            return;
        }
    }
    delay(milisegundos);
}