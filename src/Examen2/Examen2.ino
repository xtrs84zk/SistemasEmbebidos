/*
 * Project Examen 2
 * Description: Quiz #2
 * Author: Javier Sánchez
 * Date: Noviembre 18, 2020.
 */
double lectura = 0; // Se declara una variable lectura inicializándola en 0
double voltaje = 0; // Se declara una variable voltaje inicializándola en 0
double mVolts = 0;  // Se declara una variable mVolts inicializándola en 0
double gradosC = 0; // Se declara una variable gradosC inicializándola en 0
void setup()
{
    pinMode(A3, INPUT);
    Particle.variable("gradosC", &gradosC, DOUBLE); // Se declara gradosC como una variable accesible desde la nube
    pinMode(D0, OUTPUT); // led1
    pinMode(D1, OUTPUT); // led2
    pinMode(D6, OUTPUT); // foco
}

void loop()
{
    lectura = analogRead(A3);           // Se realiza la lectura desde la entrada A3
    voltaje = (lectura * 3.3) / 4095.0; // Se convierte la lectura en voltaje
    mVolts = voltaje * 1000.0;          // Se convierte el voltaje en milivolts
    gradosC = (mVolts * 1.0) / 10.0;    // Se convierten los milivolts en grados celsius

    // temperatura ambiente menor o igual a 17°
    // parpadear el led conectado a D0
    if(gradosC <= 17){
        digitalWrite(D0, HIGH);
        delay(1000);
        digitalWrite(D0,LOW);
        delay(1000);
        digitalWrite(D6, HIGH);
    }
    

    // temperatura entre 17° y 25°
    // PWM el led en D1
    if(gradosC > 17 &&  gradosC <= 25){
        for(int i = 0; i<256; i++){
            analogWrite(D1, i);
            delay(10);
        } 
        for(int i = 255; i>0; i--){
            analogWrite(D1,i);
            delay(10);
        }
        digitalWrite(D6, HIGH);
        delay(1000);
    }

    // temperatura mayor a 25°
    // encender foco
    if(gradosC > 25 ){
        digitalWrite(D6, LOW);
        delay(1000);
    }
}