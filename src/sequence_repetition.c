#include "sequence_repetition.h"

static int getSequenceHash(const char* sequence) {
	int hash = 0;
	for (int i = 0; i < strlen(sequence); i++) {
		hash += pow(256, strlen(sequence) - i - 1) * sequence[i];
		hash = hash % PRIME_MODULUS;
	}

	return hash;
}

int findDNARepetition(const char* sequence, const char* motif) {
	int r = getSequenceHash(motif);

	//First characters of the sequence
	char possibleSub[strlen(motif) + 1];
	strncpy(possibleSub, sequence, strlen(motif));
	possibleSub[strlen(motif)] = '\0';

	int h = getSequenceHash(possibleSub);

	for (int i = 0; i < strlen(sequence) - strlen(motif); i++) {
		if (r == h) {
			strncpy(possibleSub, sequence + i, strlen(motif));
			if (strcmp(motif, possibleSub) == 0) {
				return i;
			}
		}
		h -= (int)(sequence[i] * pow(256, strlen(motif) - 1));
		h *= 256;
		h += sequence[i + strlen(motif)];
		h = h % PRIME_MODULUS;
		if (h < 0) {
			h += PRIME_MODULUS;
		}
	}

	return -1;

}
