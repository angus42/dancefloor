int ledPin = 13;
int soundSensorPin = A0;
bool ledOn;
int thresholdValue = 128;

int lastSoundSample;

void setup() {
	pinMode(ledPin, OUTPUT);
	pinMode(soundSensorPin, INPUT);
	// Serial.begin(115200);
	Serial.begin(38400);
}

void loop() {
	int soundSample = analogRead(soundSensorPin);
	Serial.println(soundSample);
	if (soundSample < thresholdValue && lastSoundSample > thresholdValue) {
		ledOn = !ledOn;
		digitalWrite(ledPin, ledOn ? HIGH : LOW);
	}
	lastSoundSample = soundSample;
	delay(50);
}