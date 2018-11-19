// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
	Name:       chaoshengbo.ino
	Created:	2018/11/15 19:43:43
	Author:     ndun-PC\ndun
*/

// Define User Types below here or use a .h file
//


// Define Function Prototypes that use User Types below here or use a .h file
//


// Define Functions below here or use other .ino or cpp files
//

// The setup() function runs once each time the micro-controller starts
const int pingPin = 14;
const int echiPin = 12;
int ledpin = 5;


void setup()
{
	Serial.begin(9600);
	pinMode(ledpin, OUTPUT);

}

// Add the main program code into the continuous loop() function
void loop()
{
	long duration, inches, cm;
	pinMode(pingPin, OUTPUT);
	digitalWrite(pingPin, LOW);
	delayMicroseconds(2);
	digitalWrite(pingPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(pingPin, LOW);

	pinMode(echiPin, INPUT);
	duration = pulseIn(echiPin, HIGH);
	inches = microsecondsToInches(duration);
	cm = microsecondsToCentimeters(duration);
	Serial.print(inches);
	Serial.print("in,");
	Serial.print(cm);
	Serial.print("cm");
	Serial.println();
	delay(1000);
	if (cm < 20)
	{
		digitalWrite(ledpin, HIGH);
	}
	else
	{
		digitalWrite(ledpin, LOW);
	}
}

long microsecondsToInches(long microseconds)
{
	return  microseconds / 74 / 2;
}
long microsecondsToCentimeters(long microseconds)
{
	return microseconds / 29 / 2;
}