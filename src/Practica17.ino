/*
 * Project Práctica 17
 * Description: Utilización de relevador.
 * Author: Javier Sánchez
 * Date: Noviembre 5, 2020.
 */
int tiempo = 10000; // Tiempo de diez segundos
double lectura = 0; // Se declara una variable lectura inicializándola en 0
double voltaje = 0; // Se declara una variable voltaje inicializándola en 0
double mVolts = 0;  // Se declara una variable mVolts inicializándola en 0
double gradosC = 0; // Se declara una variable gradosC inicializándola en 0
void setup()
{
    pinMode(A0, INPUT);                             // Se declara la entrada analógica A0 como entrada
    Particle.variable("lectura", &lectura, DOUBLE); // Se declara lectura como una variable accesible desde la nube
    Particle.variable("voltaje", &voltaje, DOUBLE); // Se declara voltaje como una variable accesible desde la nube
    Particle.variable("mVolts", &mVolts, DOUBLE);   // Se declara mVolts como una variable accesible desde la nube
    Particle.variable("gradosC", &gradosC, DOUBLE); // Se declara gradosC como una variable accesible desde la nube
}

void loop()
{
    lectura = analogRead(A0);           // Se realiza la lectura desde la entrada A0
    voltaje = (lectura * 3.3) / 4095.0; // Se convierte la lectura en voltaje
    mVolts = voltaje * 1000.0;          // Se convierte el voltaje en milivolts
    gradosC = (mVolts * 1.0) / 10.0;    // Se convierten los milivolts en grados celsius
}