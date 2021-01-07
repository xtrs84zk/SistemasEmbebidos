Servo servo;              // Objeto donde se asigna el servomotor
int minute = 0;           // Variable para almacenar el minuto actual
int hour = 0;             // Variable para almacenar la hora actual
bool hasBeenFeed = false; // Bandera para almacenar si el pez ha sido alimentado recientemente
void setup()
{
    pinMode(D0, OUTPUT);                       // Se define el pin D0 como salida
    servo.attach(D0);                          // Se ancla el pin D0 al objeto servomotor
    pinMode(D1, INPUT_PULLUP);                 // Se define el pin D1 como entrada de botón con resistencia
    Particle.function("serv", servoFunction);  // Se comparte la función servo con la nube de particle
    Particle.variable("minute", &minute, INT); // Se comparte la variable minute con la nube de particle
    Particle.variable("hour", &hour, INT);     // Se comparte la variable hour con la nube de particle
    Time.zone(-6);                             // Se establece la zona horaria en corcondancia con aquella de México actualmente, GMT -6
}

void loop()
{
    minute = Time.minute();      // Se asigna el minuto actual a la variable minute
    hour = Time.hour();          // Se asigna la hora actual a la variable hora
    if (digitalRead(D1) == HIGH) // Se lee el botón y, si está presionado,
    {                            // Se procede a alimentar el pez
        alimentarPez();
    }
    if (hour == 19 && minute == 24) // Se compara la hora actual con las 19:24
    {
        if (!hasBeenFeed) // Se verifica que el pez no haya sido alimentado en este minuto
        {
            alimentarPez();     // Se alimenta al pez
            hasBeenFeed = true; // Se establece que el pez ha sido almentado
        }
    }
    if (hour == 19 && minute == 25) // Se espera a que la hora sea diferente a la indicada para activar al alimentador
    {
        hasBeenFeed = false; // Se establece que el pez no ha sido alimentado para la próxima iteración
    }
}

// Función que se comparte a la nube de particle.
// Recibe un parámetro, en caso de ser 'on',
// procede a alimentar el pez.
int servoFunction(String parametro)
{
    if (parametro == "on")
    {
        alimentarPez();
        return 0;
    }
}

// Función que gira el servomotor lentamente hacia abajo
// de manera que la comida caiga del contenedor hacia el pez
// y después, gira hacia la posición inicial.
// Toma alrededor de siete segundos en total.
void alimentarPez()
{
    for (int i = 1; i < 255; i++)
    {
        servo.write(i);
        delay(15);
    }
    for (int i = 255; i > 1; i--)
    {
        servo.write(i);
        delay(15);
    }
}