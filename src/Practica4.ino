/*
 * Project Práctica 4
 * Description: Enciende y apaga cada led por medio segundo y lego de regreso
 * 
 * Author: Javier Sánchez
 * Date: Octubre 8, 2020.
 */
int led1 = D0;
int led2 = D1;
int led3 = D2;
int led4 = D3;

int tiempoS = 500; // medio segundo

// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  //encender hacia un lado
  digitalWrite(led1, HIGH); // primer led
  delay(tiempoS);
  digitalWrite(led1, LOW);
  delay(tiempoS);
  digitalWrite(led2, HIGH); // segundo led
  delay(tiempoS);
  digitalWrite(led2, LOW);
  delay(tiempoS);
  digitalWrite(led3, HIGH); // tercer led
  delay(tiempoS);
  digitalWrite(led3, LOW);
  delay(tiempoS);
  digitalWrite(led4, HIGH); // cuarto led
  delay(tiempoS);
  //encender hacia el otro
  digitalWrite(led4, LOW);
  delay(tiempoS);
  digitalWrite(led3, HIGH); // segundo led
  delay(tiempoS);
  digitalWrite(led3, LOW);
  delay(tiempoS);
  digitalWrite(led2, HIGH); // tercer led
  delay(tiempoS);
  digitalWrite(led2, LOW);
  delay(tiempoS);
}