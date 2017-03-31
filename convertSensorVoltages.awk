#!/bin/awk

BEGIN {
	# comma field separators
	FS=",";
}

{
	printf("IR_Data(");

	# Convert voltage from 0->3.3 to 0->1023
	voltage = ($1 * 1023) / 3.3;
	printf("%i", voltage)

	printf(", ")

	# Convert distance from cm to mm
	distance = $2 * 10;
	printf("%i", distance);

	if (NR != awk_fileLines + 1) {
		print "),";
	} else {
		printf(")");
	}
}