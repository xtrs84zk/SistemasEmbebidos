/*
 * Project Práctica 6
 * Description: Enciende los led a diferentes intensidades.
 * Led con intensidad al 100% 
 * Led con intensidad al 50%
 * Led con intensidad al 20%
 * Led con intensidad al 5%
 * Author: Javier Sánchez
 * Date: Octubre 13, 2020.
 */

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
    // The core of your code will likely live here.
    // 100%
    analogWrite(0, 255);
    // 50%
    analogWrite(1, 125.5);
    // 20%
    analogWrite(2, 51);
    // 5%
    analogWrite(3, 12.75);
}