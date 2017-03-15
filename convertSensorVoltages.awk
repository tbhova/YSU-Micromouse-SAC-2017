#!/bin/awk

BEGIN {
	# comma field separators
	FS=",";
}

{
	printf("IR_Data(");

	# Convert voltage from 0->5 to 0->1023
	voltage = ($1 * 1023) / 5;
	printf("%i", voltage)

	printf(", ")

	# Convert distance from cm to mm
	distance = $2 * 1000;
	printf("%i", distance);

	if (NR != awk_fileLines + 1) {
		print "),";
	} else {
		printf(")");
	}
}