/*
 * Project Práctica 1
 * Description: Hacer que un led parpadee en el pin D0.
 * Author: Javier Sánchez
 * Date: Octubre 6, 2020.
 */
int led = D0;
int tiempoS = 1000;

// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(led, OUTPUT);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  digitalWrite(led, HIGH);
  delay(tiempoS);
  digitalWrite(led, LOW);
  delay(tiempoS);
}