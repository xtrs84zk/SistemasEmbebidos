// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT_Particle.h>

// This #include statement was automatically added by the Particle IDE.
#include <HC-SR04.h>
#include "lib1.h"

#define DHTPIN D0
#define DHTTYPE DHT11
#define TRIGGERPIN A0
#define ECHOPIN D1
DHT dht(DHTPIN, DHTTYPE);
// interfaz gráfica : https://github.com/xtrs84zk/coffeeboard
Servo servo; // Objeto donde se asigna el servomotor
HC_SR04 rangefinder = HC_SR04(TRIGGERPIN, ECHOPIN);
double distanceInCentimeters = 0;
int minute = 0; // Variable para almacenar el minuto actual
int hour = 0;   // Variable para almacenar la hora actual
String lastActivation = "0:00am";
String nextActivation = "9:40am";
int startedBoiling = 0;
double coffeetemp = 0;
double temp = 0;
bool hasBeenBoiled = false; // Bandera para almacenar si el café ha sido calentado recientemente
bool triedToStartButCant = false;
bool elCafeEstaListo = false;
void setup()
{
    rangefinder.init();
    dht.begin();
    pinMode(A1, INPUT);
    Particle.variable("nextActivation", &nextActivation, STRING); // Se comparte la variable nextActivation con la nube de particle
    Particle.variable("lastActivation", &lastActivation, STRING); // Se comparte la variable nextActivation con la nube de particle
    Particle.variable("coffeetemp", &coffeetemp, DOUBLE);         // Se comparte la variable coffeetemp con la nube de particle
    Particle.variable("distanceInCentimeters", &distanceInCentimeters, DOUBLE);         // Se comparte la variable coffeetemp con la nube de particle
    Particle.variable("triedToStartButCant", &triedToStartButCant, BOOLEAN);         // Se comparte la variable coffeetemp con la nube de particle
    Particle.variable("elCafeEstaListo", &elCafeEstaListo, BOOLEAN);         // Se comparte la variable coffeetemp con la nube de particle
    Time.zone(-6);                                                // Se establece la zona horaria en corcondancia con aquella de México actualmente, GMT -6
    pinMode(D3, OUTPUT);
    pinMode(D7, OUTPUT);
    Particle.function("boilCoffee", boilCoffe);
}

void loop()
{
    if(elCafeEstaListo) {stopBoilling()}
    minute = Time.minute(); // Se asigna el minuto actual a la variable minute
    hour = Time.hour();     // Se asigna la hora actual a la variable hora
    temp = dht.getTempCelcius();
    if(!std::isnan(temp)){
        coffeetemp = temp;    
    }
    distanceInCentimeters = rangefinder.distInch() * 2.54;
    if (hour == 9 && minute == 40) // Se compara la hora actual con las 19:24
    {
        if (!hasBeenBoiled) // Se verifica que el pez no haya sido alimentado en este minuto
        {
            actuallyBoil();
            hasBeenBoiled = false; // Se establece que el pez ha sido almentado
        }
    }
    if (hour == 9 && minute == 45) // Se espera a que la hora sea diferente a la indicada para activar al alimentador
    {
        hasBeenBoiled = true; // Se establece que el pez no ha sido alimentado para la próxima iteración
        stopBoilling();
    }
    if(triedToStartButCant){

    }
}

// Función que enciende la cafetera
int boilCoffe(String par)
{
    if (par == "on")
    {
        actuallyBoil();
        return 0;
    }
    else if (par == "off")
    {
        stopBoilling();
        return 0;
    }
}

void actuallyBoil()
{
    if(distanceInCentimeters > 5){
        elCafeEstaListo = false;
        lastActivation = minute + ":"+  hour;
        digitalWrite(D7, HIGH);
        digitalWrite(D3, LOW);
    }else {
        triedToStartButCant = true;
    }
}

void stopBoilling()
{
    digitalWrite(D7, LOW);
    digitalWrite(D3, HIGH);
}