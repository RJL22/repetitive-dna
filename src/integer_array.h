#ifndef INTEGER_ARRAY_H
#define INTEGER_ARRAY_H

#include <stdlib.h>

struct Node {
	int value;
	struct Node* next_node;
};

struct IntegerArray {
	int count;
	struct Node* root;
	struct Node* end;

};

void addItem(struct IntegerArray* integerArray, int newValue);
void deleteIntegerArray(struct IntegerArray* integerArray);

#endif