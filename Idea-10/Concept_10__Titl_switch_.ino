int SensorPin = 2;
int LEDPin = 13;

int LEDstate = HIGH;
int reading;
int previous = LOW;

long time = 0;
long debounce = 50;

void setup()
{
pinMode(SensorPin, INPUT);
digitalWrite(SensorPin, HIGH);
pinMode(LEDPin, OUTPUT);
}

void loop()
{
int switchstate;

reading = digitalRead(SensorPin);
if (reading != previous) {

time = millis();
}

if ((millis() - time) > debounce) {

switchstate = reading;

if (switchstate == HIGH)
LEDstate = LOW;
else
LEDstate = HIGH;
}
digitalWrite(LEDPin, LEDstate);

previous = reading;
}
