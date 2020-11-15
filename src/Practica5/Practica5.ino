/*
 * Project Práctica 5
 * Description: Enciende los led uno a uno con un segundo de diferencia.
 * Author: Javier Sánchez
 * Date: Octubre 8, 2020.
 */

int tiempo = 500; // medio segundo

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
  //encendiendo leds
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(i, HIGH);
    delay(tiempo);
  }
  //apagando leds
  for (int i = 3; i >= 0; i--)
  {
    digitalWrite(i, LOW);
    delay(tiempo);
  }
}