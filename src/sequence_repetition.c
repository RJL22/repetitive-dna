#include "sequence_repetition.h"

static int getSequenceHash(const char* sequence) {
	int hash = sequence[0];
	for (int i = 1; i < strlen(sequence); i++) {
		hash = (hash * 256) % PRIME_MODULUS;
		hash += sequence[i];
	}
	hash = hash % PRIME_MODULUS;

	return hash;
}

int findDNARepetition(const char* sequence, const char* motif) {
	int r = getSequenceHash(motif);

	//First characters of the sequence
	char possibleSub[strlen(motif) + 1];
	strncpy(possibleSub, sequence, strlen(motif));
	possibleSub[strlen(motif)] = '\0';

	int h = getSequenceHash(possibleSub);

	int leftBaseOffset = 1;

	for (int i = 0; i < strlen(motif) - 1; i++) {
		leftBaseOffset = (leftBaseOffset * 256) % PRIME_MODULUS;
	}

	//Computing rolling hash
	for (int i = 0; i < strlen(sequence) - strlen(motif) + 1; i++) {

		if (r == h) {
			strncpy(possibleSub, sequence + i, strlen(motif));
			if (strcmp(motif, possibleSub) == 0) {
				return i;
			}
		}
		h += PRIME_MODULUS - ((leftBaseOffset * sequence[i]) % PRIME_MODULUS); 
		h *= 256;
		h += sequence[i + strlen(motif)];
		h = h % PRIME_MODULUS;

		if (h < 0) {
			h += PRIME_MODULUS;
		}
	}

	return -1;

}

struct IntegerArray* findAllDNARepetitions(const char* sequence, const char* motif) {
	int r = getSequenceHash(motif);

	//First characters of the sequence
	char possibleSub[strlen(motif) + 1];
	strncpy(possibleSub, sequence, strlen(motif));
	possibleSub[strlen(motif)] = '\0';

	int h = getSequenceHash(possibleSub);

	int leftBaseOffset = 1;

	for (int i = 0; i < strlen(motif) - 1; i++) {
		leftBaseOffset = (leftBaseOffset * 256) % PRIME_MODULUS;
	}

	struct IntegerArray* integerArray = malloc(sizeof(struct IntegerArray));
	integerArray->count = 0;

	//Computing rolling hash
	for (int i = 0; i < strlen(sequence) - strlen(motif) + 1; i++) {

		if (r == h) {
			strncpy(possibleSub, sequence + i, strlen(motif));
			if (strcmp(motif, possibleSub) == 0) {
				addItem(integerArray, i);
			}
		}
		h += PRIME_MODULUS - ((leftBaseOffset * sequence[i]) % PRIME_MODULUS); 
		h *= 256;
		h += sequence[i + strlen(motif)];
		h = h % PRIME_MODULUS;

		if (h < 0) {
			h += PRIME_MODULUS;
		}
	}

	return integerArray;

}

