/*
 * Project Práctica 16
 * Description: Utilización de relevador.
 * Author: Javier Sánchez
 * Date: Noviembre 4, 2020.
 */
double lectura = 0;     // Se declara e inicializa la variable para almacenar la lectura
double voltaje = 0;     // Se declara e inicializa una variable para almacenar la conversión a voltaje
double temperatura = 0; // Se declara e inicializa una variable para almacenar la conversión a temperatura en C°
int tiempo = 10000;     // Tiempo de diez segundos
void setup()
{
    pinMode(A0, INPUT);                                     // Se declara la entrada analógica A0 como entrada
    Serial.begin(9600);                                     // Se inicializa el puerto serial para el monitoreo
    pinMode(D6, OUTPUT);                                    // Se declara el pin D6 como salida
    Particle.variable("temperatura", &temperatura, DOUBLE); // Se declara gradosC como una variable accesible desde la nube
}

void loop()
{
    lectura = analogRead(A0);                   // Se lee la entrada analógica A0 que proporciona valores de 0-4095
    voltaje = (lectura * 3.3) / 4095.0;         // Se convierte el valor con base en la traducción a voltaje
    temperatura = voltaje * 100;                // Se convierte el voltaje a temperatura en grados celsius
    Serial.print("La temperatura actual es: "); // Se concatena el String en la salida serial
    Serial.print(temperatura);                  // Imprime el valor en temperatura a serial
    Serial.println("C°.");                      // Concatena el String en la salida serial e imprime un salto de línea
    if (temperatura > 30)                       // En cuanto se detecte una temperatura mayor a 30° comienza la secuencia
    {
        digitalWrite(D6, HIGH); // Se envía la señal de encendido al relevador
        delay(tiempo);          // Se espera $tiempo milisegundos
        digitalWrite(D6, LOW);  // Se envía la señal de apagado al relevador
        delay(4000);            // Se espera 4,000 milisegundos
    }
    else
    {
        digitalWrite(D6, LOW); // Se envía la señal de apagado al relevador
        delay(4000);           // Se espera 4,000 milisegundos
    }
}