/*
 * Project Práctica 4
 * Description: Enciende y apaga cada led por medio segundo y lego de regreso
 * 
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
  delay(tiempo);
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(i, HIGH);
    delay(tiempo);
    digitalWrite(i, LOW);
    delay(tiempo);
  }
  for (int i = 3; i > 0; i--)
  {
    digitalWrite(i, HIGH);
    delay(tiempo);
    digitalWrite(i, LOW);
    delay(tiempo);
  }
}