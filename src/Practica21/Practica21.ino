/*
 * Project Práctica 21
 * Description: Utilización de led con particle functions.
 * Author: Javier Sánchez
 * Date: Diciembre 8, 2020.
 */
void setup()
{
    pinMode(D6, OUTPUT);
    Particle.function("led", ledfunction);
}

void loop();

int ledfunction(String parametro)
{
    if (parametro == "on")
    {
        digitalWrite(D6, LOW);
        return 1;
    }
    else if (parametro == "off")
    {
        digitalWrite(D6, LOW);
        return 0;
    }
    else
    {
        return -1;
    }
}