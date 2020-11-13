/*
 * Project Práctica 10
 * Description: Lectura de las entradas analógicas
 * Author: Javier Sánchez
 * Date: Octubre 21, 2020.
 */
double lectura = 0; // se declara e inicializa la variable para almacenar la lectura
void setup()
{
    pinMode(A0, INPUT); // se declara la entrada analógica A0 como entrada
    Serial.begin(9600); // se inicializa el puerto serial para el monitoreo
}

void loop()
{
    lectura = analogRead(A0); // se lee la entrada analógica A0 que proporciona valores de 0-4095
    Serial.print("La lectura en A0 es: ");
    Serial.println(lectura); // se imprime el valor en lectura
    delay(1000);             // esperando 1 segundo entre cada iteración
}