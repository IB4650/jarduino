#!/bin/bash
OUTPUT_DIR=output
BIN_DIR=bin
BINFILE=$BIN_DIR/tmp36
echo "Starting Temperature Logging Tool"

for i in $(cat etc/temperature.conf); do 
	SENSOR=`echo $i | awk -F "," '{print $1}'`
	INTERVAL=`echo $i | awk -F "," '{print $2}'`
	PIN=`echo $i | awk -F "," '{print $3}'`
	MEASURE_UNIT=`echo $i | awk -F "," '{print $4}'`
	echo "Reading data from $SENSOR and sending to PCDuino Analog Pin $PIN with $INTERVAL minute(s) interval. Results are saved in $OUTPUT_DIR/$SENSOR"
	(
		while [ 1 ]; do  echo $(date +%Y-%m-%dT%H:%M:%S) `$BINFILE $PIN $MEASURE_UNIT` >> $OUTPUT_DIR/$SENSOR; sleep $(($INTERVAL * 60)); done &
	)
done
