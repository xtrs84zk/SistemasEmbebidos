Servo servo;
void setup()
{
    pinMode(D0, OUTPUT);
    servo.attach(D0);
    pinMode(D1, INPUT_PULLUP);
}

void loop()
{
    if (digitalRead(D1) == LOW)
    { //botón presionado
        for (int i = 1; i < 255; i++)
        {
            servo.write(i);
            delay(6);
        }
        for (int i = 255; i > 1; i--)
        {
            servo.write(i);
            delay(10);
        }
    }
}