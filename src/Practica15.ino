/*
 * Project Práctica 15
 * Description: Utilización de relevador.
 * Author: Javier Sánchez
 * Date: Noviembre 3, 2020.
 */
int tiempo = 10000;                   // tiempo de diez segundos
void setup() { pinMode(D6, OUTPUT); } // se establece el pin D6 como salida

void loop()
{
    digitalWrite(D6, HIGH); // se envía la señal de encendido al relevador
    delay(tiempo);          // esperando $tiempo milisegundos
    digitalWrite(D6, LOW);  // se envía la señal de apagado al relevador
    delay(tiempo);          // esperando $tiempo milisegundos
}