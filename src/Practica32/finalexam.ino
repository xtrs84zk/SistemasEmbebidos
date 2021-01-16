#define DHTPIN D0
#define DHTTYPE DHT11
#define TOKEN "BBFF-1VK4ROXzIhprWruYG2hTZJQRkYV1KU"
Ubidots ubidots(TOKEN, UBI_TCP);
DHT dht(DHTPIN, DHTTYPE);
double gradosCelsius = 0.0;
void setup()
{
    dht.begin();
    Particle.function("relay", relayFunction);
    Particle.variable("gradosC", &gradosCelsius, DOUBLE);
}

void loop()
{
    if (gradosCelsius > 15)
    {
        digitalWrite(D0, LOW);
    }
    else
    {
        digitalWrite(D0, HIGH);
    }
    ubidots.add("gradosC", gradosCelsius);
    gradosCelsius = dht.getTempCelcius();
    bool bufferSent = false;
    bufferSent = ubidots.send(); // Will send data to a device label that matches the device Id
    if (bufferSent)
    {
        // Do something if values were sent properly
        Serial.println("Values sent by the device");
    }
};