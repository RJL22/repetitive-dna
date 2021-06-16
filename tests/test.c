#include <stdio.h>

#include "../src/sequence_repetition.h"

//Compile code: gcc test.c ../src/sequence_repetition.c

int main() {

	int index = findDNARepetition("AAABBABA", "BBA");

	printf("Index of Repetition: %d\n", index);


}