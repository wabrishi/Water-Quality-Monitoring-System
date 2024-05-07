int measurePin = A1; //Connect dust sensor to Arduino Ao pin

int ledPower = 2; //Connect to led driver pins of dust sensor to Arduino D2

int samplingTime = 280;

int deltaTime = 40;

int sleepTime = 9680;


float voMeasured = 0;
float calcVoltage = 0;

float dustDensity = 0;
void setup() {
  // put your setup code here, to run once:


Serial.begin(9600);
pinMode(ledPower, OUTPUT);

}




void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(ledPower, LOW); // power on the LED



delayMicroseconds (samplingTime);
voMeasured = analogRead(measurePin); // read the dust value
delayMicroseconds (deltaTime);


digitalWrite(ledPower, HIGH); // turn the LED off


delayMicroseconds (sleepTime);
calcVoltage = voMeasured *(5.0/ 1024.0); // 0-5V mapped to 01023 integer values
dustDensity = 170 *calcVoltage - 0.1;

Serial.print("AQI: ");
Serial.print( voMeasured);

Serial.print("\n");
Serial.print(calcVoltage);

Serial.print("\n");
Serial.print(dustDensity );

Serial.print("\n \n");

delay(9680);
}
