/*
 * Project Práctica 13
 * Description: Lectura del sensor de temperatura LM35.
 * Author: Javier Sánchez
 * Date: Octubre 26, 2020.
 */
double lectura = 0;     // se declara e inicializa la variable para almacenar la lectura
double voltaje = 0;     // se declara e inicializa una variable para almacenar la conversión a voltaje
double temperatura = 0; // se declara e inicializa una variable para almacenar la conversión a temperatura en C°
void setup()
{
    pinMode(A0, INPUT); // se declara la entrada analógica A0 como entrada
    Serial.begin(9600); // se inicializa el puerto serial para el monitoreo
}

void loop()
{
    lectura = analogRead(A0);                       // se lee la entrada analógica A0 que proporciona valores de 0-4095
    voltaje = lectura / 4095 * 3.3;                 // se convierte el valor con base en la traducción a voltaje
    temperatura = voltaje * 100;                    // se convierte el voltaje a temperatura en grados celsius
    Serial.print("A0 reporta un valor de ");        // concatenando en el puerto serial el string
    Serial.print(lectura);                          // se imprime el valor en lectura analógica
    Serial.print(" que equivale a ");               // concatenando en el puerto serial el string
    Serial.print(voltaje);                          // se imprime el valor en voltaje
    Serial.println(" volts. Además, representan "); // concatenando en el puerto serial el string
    Serial.print(temperatura);                      // se imprime el valor en temperatura
    Serial.println("C°.");                          // concatenando en el puerto serial el string
    delay(1000);                                    // esperando un segundo antes de la siguiente iteración
}