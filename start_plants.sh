#!/bin/bash
OUTPUT_DIR=output
BIN_DIR=bin
BINFILE=$BIN_DIR/plant
echo "Starting Plants Logging Tool"

for i in $(cat etc/plants.conf); do 
	PLANT=`echo $i | awk -F "," '{print $1}'`
	INTERVAL=`echo $i | awk -F "," '{print $2}'`
	PIN=`echo $i | awk -F "," '{print $3}'`
	echo "Reading data from $PLANT and sending to PCDuino Analog Pin $PIN with $INTERVAL minute(s) interval. Results are saved in $OUTPUT_DIR/$PLANT"
	(
		while [ 1 ]; do  echo $(date +%Y-%m-%dT%H:%M:%S) `$BINFILE $PIN` >> $OUTPUT_DIR/$PLANT; sleep $(($INTERVAL * 60)); done &
	)
done
