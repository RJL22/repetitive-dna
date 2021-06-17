#include <stdio.h>

#include "../src/sequence_repetition.h"
#include "../src/sequence_repetition.h"

//Compile code: gcc test.c ../src/sequence_repetition.c ../src/integer_array.c


int main() {


	int index = findDNARepetition("ABAABABBABABA", "BBAB");

	printf("Index of Repetition: %d\n", index);

	struct IntegerArray* indices = findAllDNARepetitions("BABABABA", "BA");

	struct Node* current = indices->root;

	for (int i = 0; i < indices->count; i++) {
		printf("Index: %d\n", current->value);
		current = current->next_node;
	}
}