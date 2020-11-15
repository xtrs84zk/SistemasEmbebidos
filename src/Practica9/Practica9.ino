/*
 * Project Práctica 9
 * Description: Práctica Mixta.
 * 1. Secuencia de LEDs de izquierda a derecha y viceversa.
 * 2. PWM a los 4 LEDs de 0 al 100% y del 100 al 0%.
 * 3. Secuencia de encendido y apagado de izquierda a derecha y viceversa.
 * 4. Se repite el ciclo.
 * Author: Javier Sánchez
 * Date: Octubre 14, 2020.
 */

int tiempo = 500; // tiempo entre LEDs
int tiempoPWM = 20; // tiempo entre actualizaciones PWM
// setup() runs once, when the device is first turned on.
void setup()
{
    // Put initialization like pinMode and begin functions here.
    for (int i = 0; i <= 3; i++)
    {
        pinMode(i, OUTPUT);
    }
}

// loop() runs over and over again, as quickly as it can execute.
void loop()
{
    // Secuencia de LEDs de izquierda a derecha y viceversa
    for (int i = 0; i <= 2; i++) // encendiendo y apagando hacia la derecha
    {
        digitalWrite(i, HIGH);
        delay(tiempo);
        digitalWrite(i, LOW);
        delay(tiempo);
    }
    for (int i = 3; i >= 0; i--) // encendiendo y apagando de regreso
    {
        digitalWrite(i, HIGH);
        delay(tiempo);
        digitalWrite(i, LOW);
        delay(tiempo);
    }
    // PWM a los 4 LEDs de 0 a 100% y de 100 a 0%
    for (int i = 0; i <= 255; i++) // incrementando intensidad
    {
        analogWrite(0, i);
        analogWrite(1, i);
        analogWrite(2, i);
        analogWrite(3, i);
        delay(tiempoPWM);
    }
    for (int i = 255; i >= 0; i--) // decrementando intensidad
    {
        analogWrite(0, i);
        analogWrite(1, i);
        analogWrite(2, i);
        analogWrite(3, i);
        delay(tiempoPWM);
    }
    // Secuencia de encendido y apagado de izquierda a derecha y viceversa
    for (int i = 0; i <= 3; i++) // encendiendo leds
    {
        digitalWrite(i, HIGH);
        delay(tiempo);
    }
    for (int i = 3; i >= 0; i--) // apagando leds
    {
        digitalWrite(i, LOW);
        delay(tiempo);
    }
}