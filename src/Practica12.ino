/*
 * Project Práctica 12
 * Description: 
 * Author: Javier Sánchez
 * Date: Octubre 22, 2020.
 */
double lectura = 0; // se declara e inicializa la variable para almacenar la lectura
double voltaje = 0; // se declara e inicializa una variable para almacenar la conversión a voltaje
void setup()
{
    pinMode(A0, INPUT); // se declara la entrada analógica A0 como entrada
    Serial.begin(9600); // se inicializa el puerto serial para el monitoreo
}

void loop()
{
    lectura = analogRead(A0);                // se lee la entrada analógica A0 que proporciona valores de 0-4095
    voltaje = lectura / 4095 * 3.3;          // se convierte el valor con base en la traducción a voltaje
    Serial.print("A0 reporta un valor de "); // concatenando en el puerto serial el string
    Serial.print(lectura);                   // se imprime el valor en lectura analógica
    Serial.print(" que equivale a ");        // concatenando en el puerto serial el string
    Serial.print(voltaje);                   // se imprime el valor en voltaje
    Serial.println(" volts.");               // concatenando en el puerto serial el string
    delay(1000);
}