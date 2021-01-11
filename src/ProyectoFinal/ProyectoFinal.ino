// interfaz gráfica : https://github.com/xtrs84zk/coffeeboard
Servo servo;    // Objeto donde se asigna el servomotor
int minute = 0; // Variable para almacenar el minuto actual
int hour = 0;   // Variable para almacenar la hora actual
int lastActivationMinute = 0;
int lectura = 0;
double voltaje = 0.0;
double gradosCelsius = 0.0;
String nextActivation = "9:40am";
double coffeetemp = 0;
bool hasBeenBoiled = false; // Bandera para almacenar si el café ha sido calentado recientemente
void setup()
{
    pinMode(A1, INPUT);
    Particle.variable("minute", &minute, INT);                    // Se comparte la variable minute con la nube de particle
    Particle.variable("hour", &hour, INT);                        // Se comparte la variable hour con la nube de particle
    Particle.variable("nextActivation", &nextActivation, STRING); // Se comparte la variable nextActivation con la nube de particle
    Particle.variable("coffeetemp", &coffeetemp, DOUBLE);         // Se comparte la variable coffeetemp con la nube de particle
    Time.zone(-6);                                                // Se establece la zona horaria en corcondancia con aquella de México actualmente, GMT -6
    pinMode(D3, OUTPUT);
    pinMode(D7, OUTPUT);
    Particle.function("boilCoffee", boilCoffe);
}

void loop()
{
    minute = Time.minute();   // Se asigna el minuto actual a la variable minute
    hour = Time.hour();       // Se asigna la hora actual a la variable hora
    lectura = analogRead(A1); //0-4095
    voltaje = ((lectura * 3.3) / 4095.0);
    gradosCelsius = ((3.3 * (10.0 / voltaje)) - 10); // Se lee la temperatura del café
    coffeetemp = gradosCelsius;
    if (hour == 9 && minute == 40) // Se compara la hora actual con las 19:24
    {
        if (!hasBeenBoiled) // Se verifica que el pez no haya sido alimentado en este minuto
        {
            lastActivationMinute = 40;
            actuallyBoil();
            hasBeenBoiled = false; // Se establece que el pez ha sido almentado
        }
    }
    if (hour == 9 && minute == 45) // Se espera a que la hora sea diferente a la indicada para activar al alimentador
    {
        hasBeenBoiled = true; // Se establece que el pez no ha sido alimentado para la próxima iteración
        stopBoilling();
    }
}

// Función que enciende la cafetera
void boilCoffe(String par)
{
    if (par == "on")
    {
        actuallyBoil();
    }
    else if (par == "off")
    {
        stopBoilling();
    }
}

void actuallyBoil()
{
    digitalWrite(D7, LOW);
    digitalWrite(D3, LOW);
}

void stopBoilling()
{
    digitalWrite(D7, HIGH);
    digitalWrite(D3, HIGH);
}