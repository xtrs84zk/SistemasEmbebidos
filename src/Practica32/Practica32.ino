/*
 * Project Práctica 22
 * Description: Utilización de relay con particle functions.
 * Author: Javier Sánchez
 * Date: Diciembre 8, 2020.
 */
void setup()
{
    pinMode(D7, OUTPUT);
    Particle.function("relay", relayFunction);
}

void loop();

int relayFunction(String par)
{
    if (par == "on")
    {
        digitalWrite(D7, LOW);
        return 1;
    }
    else if (par == "off")
    {
        digitalWrite(D7, HIGH);
        return 0;
    }
    else
    {
        return -1;
    }
}