# repetitive-dna
 Identifies occurences of a given DNA sequence in a larger sequence.
## Install
 Download source code and compile static library (Unix).
```
git clone https://github.com/RJL22/repetitive-dna/edit/main/README.md
cd repetitive-dna/src/
gcc -c sequence_repetition.c integer_array.c
ar rcs librepetitivedna.a sequence_repetition.o integer_array.o
ranlib librepetitivedna.a
```
## Usage
Simple example printing the first repetition found in the sequence
```
#include <stdio.h>
#include <repetitive_dna.h>

int main() {
 int index = findDNARepetition("ABAABABBABABA", "BBAB");
 printf("Index of Repetition: %d\n", index);
}
```
### Output:
```
Index of Repetition: 6
```
