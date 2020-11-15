/*
 * Project Examen 1
 * Description: Examen xd 
 * Encender LED2 y LED4 por 1/2 segundo y apagarlos por medio segundo
 * PWM LED1 y LED3 de 0-100% y de 100% a 0%
 * Secuencia de izquierda a derecha y de derecha a izquierda por 1/4 de segundo
 * Todos PWM de 0-100% y de 100-0%
 * Secuencia de derecha a izquierda y de izquierda a derecha por 1/4 segundo
 * Author: Javier Sánchez
 * Date: Octubre 20, 2020.
 */

int tiempoEntreLEDs = 250; // tiempo entre LEDs
int tiempoPWM = 5; // tiempo entre actualizaciones PWM
// Las instrucciones dentro del bloque setup sólo se ejecutan una vez
void setup()
{
    for (int i = 0; i <= 3; i++) // Inicializando D0 a D3.
    {
        pinMode(i, OUTPUT);
    }
}

// Las instrucciones dentro de la función loop se repiten indefinidamente.
void loop()
{
    // Encender LED2 y LED4 por medio segundo y apagar por medio segundo #1
    digitalWrite(1,HIGH);
    digitalWrite(3,HIGH);
    delay(500);
    digitalWrite(1,LOW);
    digitalWrite(3,LOW);
    delay(500);
    // PWM LED1 y LED3 de 0-100%  y de regreso #2
    for(int i=0; i<255; i++){ // yendo de 0% a 100%
        analogWrite(0,i);
        analogWrite(2,i);
        delay(tiempoPWM);
    }
    for(int i=255; i>=0; i--){ // yendo de 100% a 0%
        analogWrite(0,i);
        analogWrite(2,i);
        delay(tiempoPWM);   
    }
    // Secuencia de LEDs de izquierda a derecha y viceversa #3
    for (int i = 0; i <= 2; i++) // encendiendo y apagando hacia la derecha
    {
        digitalWrite(i, HIGH);
        delay(tiempoEntreLEDs);
        digitalWrite(i, LOW);
        delay(tiempoEntreLEDs);
    }
    for (int i = 3; i >= 0; i--) // encendiendo y apagando hacia la izquierda
    {
        digitalWrite(i, HIGH);
        delay(tiempoEntreLEDs);
        digitalWrite(i, LOW);
        delay(tiempoEntreLEDs);
    }
    // Los cuatro LEDs en PWM de 0-100% y de 100-0% #4
    for(int i=0; i<=255; i++){ // PWM de 0% a 100%
        analogWrite(0,i);
        analogWrite(1,i);
        analogWrite(2,i);
        analogWrite(3,i);
        delay(tiempoPWM);
    }
    for(int i=255; i>=0; i--){ // PWM de 100% a 0%
        analogWrite(0,i);
        analogWrite(1,i);
        analogWrite(2,i);
        analogWrite(3,i);
        delay(tiempoPWM);
    }
    // Encendiendo de derecha a izquierda y apagando en orden inverso a ritmo de 1/4 de segundo #5
    for (int i = 3; i >= 0; i--) // encendiendo cada LED 250ms después del anterior
    {
        digitalWrite(i, HIGH);
        delay(tiempoEntreLEDs);
    }
    for (int i = 0; i <= 3; i++) // apagando cada LED 250ms después del anterior
    {
        digitalWrite(i, LOW);
        delay(tiempoEntreLEDs);
    }
}