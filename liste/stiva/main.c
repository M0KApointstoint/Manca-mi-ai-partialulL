#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *create_node(int data)
{
	struct node *new_node = malloc(sizeof(struct node));
	if (!new_node) {
		return NULL;
	}
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

int push(struct node **head_adr, int data)
{
	if (!head_adr) {
		return -1;
	}
	struct node *new_node = create_node(data);
	if (!new_node) {
		return -1;
	}
	new_node->next = *head_adr;
	*head_adr = new_node;
	return 0;
}

int pop(struct node **head_adr)
{
	if (!head_adr || !*head_adr) {
		return -1;
	}
	struct node *target = *head_adr;
	*head_adr = (*head_adr)->next;
	free(target);
	return 0;
}

int top(struct node *head, int *output_adr)
{
	if (!head || !output_adr) {
		return -1;
	}
	*output_adr = head->data;
	return 0;
}

int is_empty(struct node *head)
{
	if (!head) {
		printf("The stack is empty!\n");
		return 1;
	}
	printf("The stack is not empty!\n");
	return 0;
}

int nr_nodes(struct node *head)
{
	int nr = 0;
	while (head) {
		++nr;
		head = head->next;
	}
	return nr;
}

void print(struct node *head)
{
	int nr = nr_nodes(head);
	for (int i = 0; i < nr; ++i) {
		if (!i) {
			printf("Top of the stack: ");
		}
		if (i == (nr - 1)) {
			printf("Base of the stack: ");
		}
		printf("data: %d\n", head->data);
		head = head->next;
	}
}

void destroy(struct node **head_adr)
{
	if (!head_adr || !*head_adr) {
		return;
	}
	while (*head_adr) {
		struct node *target = *head_adr;
		*head_adr = (*head_adr)->next;
		free(target);
	}
}

int main(void)
{
	struct node *stack = NULL;
	int value;

	// Test 1: operatii pe stiva vida
	printf("Test 1:\n");
	pop(&stack);
	top(stack, &value);
	is_empty(stack);
	print(stack);

	// Test 2: push
	printf("\nTest 2:\n");
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	print(stack); // asteptat: 3 2 1

	// Test 3: top
	printf("\nTest 3:\n");
	if (!top(stack, &value)) {
		printf("Top: %d\n", value); // asteptat: 3
	}

	// Test 4: pop
	printf("\nTest 4:\n");
	pop(&stack);
	print(stack); // asteptat: 2 1

	pop(&stack);
	print(stack); // asteptat: 1

	pop(&stack);
	print(stack); // asteptat: gol

	// Test 5: pop pe stiva vida
	printf("\nTest 5:\n");
	printf("pop empty: %d\n", pop(&stack)); // asteptat: -1

	// Test 6: top pe stiva vida
	printf("\nTest 6:\n");
	printf("top empty: %d\n", top(stack, &value)); // asteptat: -1

	// Test 7: push dupa golire
	printf("\nTest 7:\n");
	push(&stack, 42);
	print(stack); // asteptat: 42

	// Test 8: is_empty
	printf("\nTest 8:\n");
	is_empty(stack); // nu e empty
	pop(&stack);
	is_empty(stack); // empty

	// Test 9: destroy
	printf("\nTest 9:\n");
	push(&stack, 10);
	push(&stack, 20);
	push(&stack, 30);
	destroy(&stack);
	print(stack); // asteptat: nimic
	printf("stack dupa destroy: %p\n", (void *)stack); // asteptat: (nil)

	return 0;
}

