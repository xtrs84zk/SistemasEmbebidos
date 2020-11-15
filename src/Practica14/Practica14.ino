/*
 * Project Práctica 14
 * Description: Lectura del sensor de temperatura LM35 y representación por LEDs.
 * Author: Javier Sánchez
 * Date: Octubre 27, 2020.
 */
double lectura = 0;     // se declara e inicializa la variable para almacenar la lectura
double voltaje = 0;     // se declara e inicializa una variable para almacenar la conversión a voltaje
double temperatura = 0; // se declara e inicializa una variable para almacenar la conversión a temperatura en C°
int tiempo = 500;       // tiempo de cuarto segundo
void setup()
{
    pinMode(A0, INPUT); // se declara la entrada analógica A0 como entrada
    Serial.begin(9600); // se inicializa el puerto serial para el monitoreo
    for (int i = 0; i <= 2; i++)
    {
        pinMode(i, OUTPUT); // establece el pin $i como salida
    }
}

void loop()
{
    lectura = analogRead(A0);           // se lee la entrada analógica A0 que proporciona valores de 0-4095
    voltaje = (lectura * 3.3) / 4095.0; // se convierte el valor con base en la traducción a voltaje
    temperatura = voltaje * 100;        // se convierte el voltaje a temperatura en grados celsius

    if (temperatura <= 20) // hace parpadear sólo el led D0 cuando la temperatura está en menos de veinte grados
    {
        digitalWrite(0, HIGH); // enciende el led 0
        delay(tiempo);         // espera $tiempo
        digitalWrite(0, LOW);  // apaga el led 0
        delay(tiempo);         // espera $tiempo
        digitalWrite(1, LOW);  // apaga el led 1
        digitalWrite(2, LOW);  // apaga el led 2
    }
    else if (temperatura > 20 && temperatura < 30) //  hace parpadear sólo el led D1 cuando la temperatura está entre 20 y 30 grados
    {
        digitalWrite(0, LOW);  // apaga el led 0
        digitalWrite(1, HIGH); // enciende el led 1
        delay(tiempo);         // espera $tiempo
        digitalWrite(1, LOW);  // apaga el led 1
        delay(tiempo);         // espera $tiempo
        digitalWrite(2, LOW);  // apaga el led 2
    }
    else // hace parpadear sólo el led D0 cuando la temperatura está a más de treinta grados
    {
        digitalWrite(0, LOW);  // apaga el led 0
        digitalWrite(1, LOW);  // apaga el led 1
        digitalWrite(2, HIGH); // enciende el led 2
        delay(tiempo);         // espera $tiempo
        digitalWrite(2, LOW);  // apaga el led 2
        delay(tiempo);         // espera $tiempo
    }
    Serial.print("La temperatura actual es: "); // se concatena el String al serial
    Serial.print(temperatura);                  // imprime el valor actual en temperatura
    Serial.println("C°.");                      // concatena el String al serial e inserta un salto de línea
}