/**
plant v0.01 Reads analog values from moisture sensor to stdout
Copyright (C) 2013  Juan Toledo Carrasco

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

*/

#include<core.h>


int sensorPin = 0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
	if(argc < 2)
	{
		fprintf(stderr, "ERROR: You must specify an analog pin\n", __LINE__);
		exit(1);
	}
	sensorPin = atoi(argv[1]);
	pinMode(sensorPin,INPUT);
}

void loop() {
	sensorValue = analogRead(sensorPin);               
	printf("%i\n",sensorValue);      
	exit(0);
}

