#!/bin/bash

lines=`cat sharpIrSensorData.csv | wc -l`
awk -f convertSensorVoltages.awk -v awk_fileLines="$lines" < sharpIrSensorData.csv > irDataCode.txt

echo "Success! code is now in irDataCode.txt"