/*
 * Project Práctica 8
 * Description: Incrementar lentamente la intensidad de un led  y luego descender.
 * Author: Javier Sánchez
 * Date: Octubre 14, 2020.
 */

int tiempo = 20;
// setup() runs once, when the device is first turned on.
void setup()
{
    // Put initialization like pinMode and begin functions here.
    pinMode(0, OUTPUT);
}

// loop() runs over and over again, as quickly as it can execute.
void loop()
{
    // Incrementando lentamente la intensidad del LED.
    for (int i = 0; i <= 255; i++)
    {
        analogWrite(0, i);
        delay(tiempo);
    }
    // Decrementando lentamente la intensidad del LED.
    for (int i = 255; i >= 0; i--)
    {
        analogWrite(0, i);
        delay(tiempo);
    }
}