#ifndef SEQUENCE_REPETITION_H
#define SEQUENCE_REPETITION_H

#include <math.h>
#include <string.h>
#include <stdio.h>

#include "integer_array.h"


#define PRIME_MODULUS 101

//Returns the index of the first repetition
int findDNARepetition(const char* sequence, const char* motif);

//Returns indices of all repetitions
struct IntegerArray* findAllDNARepetitions(const char* sequence, const char* motif);


#endif