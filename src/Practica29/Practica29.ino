Servo servo;
int minute = 0;
int hour = 0;
bool hasBeenFeed = false;
void setup()
{
    pinMode(D0, OUTPUT);
    servo.attach(D0);
    pinMode(D1, INPUT_PULLUP);
    Time.zone(-6);
    Particle.variable("minute", &minute, INT);
    Particle.variable("hour", &hour, INT);
}

void loop()
{
    minute = Time.minute();
    hour = Time.hour();
    if (digitalRead(D1) == HIGH)
    {
        alimentarPez();
    }
    if (hour == 22 && minute == 33)
    {
        if (!hasBeenFeed)
        {
            alimentarPez();
            hasBeenFeed = true;
        }
    }
    if (hour == 22 && minute == 34)
    {
        hasBeenFeed = false;
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