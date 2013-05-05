/*
* Temperature sensor test program for a10
*/
#include <core.h>

//The analog pin the TMP36's Vout (sense) pin is connected to
//the resolution is 10 mV / degree centigrade with a
//500 mV offset to allow for negative temperatures
int sensorPin = 0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
char* mu; //Measure Unit

void setup(){
	if(argc < 3 || ( strcmp(argv[2],"C") != 0 && strcmp(argv[2],"F") != 0) || strlen(argv[2]) > 1 )
	{
		fprintf(stderr, "ERROR: You must specify an analog pin and unit measure for output C: Celcius    F: Fahrenheit \n", __LINE__);
		exit(1);
	}
	mu = argv[2];
	sensorPin = atoi(argv[1]);
	pinMode(sensorPin,INPUT);
	delay(500);
} 
 
void loop()
{
	 delay(1000);
	 //getting the voltage reading from the temperature sensor
	 int reading = analogRead(sensorPin);  
	 
	 // converting that reading to voltage
	 float voltage = reading * 3.3;
	 voltage /= 4096.0; 
	 //printf("adc:%d\n", reading);
	 // print out the voltage
	 //printf("%.2f volts\n", voltage);
	 
	 // now print out the temperature
	 float temperature = (voltage - 0.6) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
												   //to degrees ((volatge - 500mV) times 100)
	if(mu[0]=='F'){
		temperature = (temperature * 9.0 / 5.0) + 32.0;
	}
	printf("%.1f\n", temperature);
	exit(0);
}
