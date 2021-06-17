#include "integer_array.h"


void addItem(struct IntegerArray* integerArray, int newValue) {

	if (integerArray->count == 0) {

		struct Node* new_node = malloc(sizeof(struct Node));
		new_node->value = newValue;
		new_node->next_node = NULL;

		integerArray->root = new_node;
		integerArray->end = new_node;

	} else {

		struct Node* new_node = malloc(sizeof(struct Node));
		new_node->value = newValue;
		new_node->next_node = NULL;
	
		integerArray->end->next_node = new_node;
		integerArray->end = new_node;
	}

	integerArray->count++;
}

void deleteIntegerArray(struct IntegerArray* integerArray) {
	struct Node* currentNode = integerArray->root;
	struct Node* next = currentNode;

	do {
		next = currentNode->next_node;
		free(currentNode);
		currentNode = next;
	} while (currentNode->next_node != NULL);
}
