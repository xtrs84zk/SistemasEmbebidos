Servo servo;
void setup()
{
    pinMode(D0, OUTPUT);
    servo.attach(D0);
    pinMode(D1, INPUT_PULLUP);
    Particle.function("serv", servoFunction);
}

void loop()
{
    if (digitalRead(D1) == LOW)
    {
        alimentarPez();
    }
}

int servoFunction(String parametro)
{
    if (parametro == "on")
    {
        alimentarPez();
    } else {
        
    }
}

void alimentarPez()
{
    for (int i = 1; i < 255; i++)
    {
        servo.write(i);
        delay(15);
    }
    for (int i = 255; i > 1; i--)
    {
        servo.write(i);
        delay(15);
    }
}