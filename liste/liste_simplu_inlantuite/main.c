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

int insert_start(struct node **head_adr, int data)
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

int insert_end(struct node **head_adr, int data)
{
	if (!head_adr) {
		return -1;
	}
	struct node *new_node = create_node(data);
	if (!new_node) {
		return -1;
	}
	struct node *p = *head_adr;
	if (!p) {
		*head_adr = new_node;
		return 0;
	}
	while (p->next) {
		p = p->next;
	}
	p->next = new_node;
	return 0;
}

// Functie ajutatoare pentru insert_pos() si delete_pos().
int nr_nodes(struct node *head)
{
	int nr = 0;
	while (head) {
		++nr;
		head = head->next;
	}
	return nr;
}

// Primul nod este are pozitia egala cu zero.
int insert_pos(struct node **head_adr, int data, int pos)
{
	if (!head_adr || pos < 0 || pos > nr_nodes(*head_adr)) {
		return -1;
	}
	struct node *new_node = create_node(data);
	if (!new_node) {
		return -1;
	}
	if (!pos) {
		new_node->next = *head_adr;
		*head_adr = new_node;
		return 0;
	}
	struct node *p = *head_adr;
	for (int i = 1; i < pos; ++i) {
		p = p->next;
	}
	new_node->next = p->next;
	p->next = new_node;
	return 0;
}

void delete_start(struct node **head_adr)
{
	if (!head_adr || !*head_adr) {
		return;
	}
	struct node *p = *head_adr;
	p = p->next;
	free(*head_adr);
	*head_adr = p;
}

void delete_end(struct node **head_adr)
{
	if (!head_adr || !*head_adr) {
		return;
	}
	struct node *p = *head_adr;
	if (!p->next) {
		free(p);
		*head_adr = NULL;
		return;
	}
	while (p->next && p->next->next) {
		p = p->next;
	}
	struct node *target = p->next;
	p->next = target->next;
	free(target);
}

// Primul nod are pozitia egala cu zero.
void delete_pos(struct node **head_adr, int pos)
{
	if (!head_adr || pos < 0 || pos >= nr_nodes(*head_adr)) {
		return;
	}
	struct node *target = NULL;
	if (!pos) {
		target = *head_adr;
		*head_adr = target->next;
		free(target);
		return;
	}
	struct node *p = *head_adr;
	for (int i = 1; i < pos; ++i) {
		p = p->next;
	}
	target = p->next;
	p->next = target->next;
	free(target);
}

int search(struct node *head, int data)
{
	while (head) {
		if (head->data == data) {
			return 0;
		}
		head = head->next;
	}
	return -1;
}

void print(struct node *head)
{
	int i = 0;
	while (head) {
		printf("pos: %d data: %d\n", i++, head->data);
		head = head->next;
	}
}

void destroy(struct node **head_adr)
{
	if (!head_adr || !*head_adr) {
		return;
	}
	struct node *target = *head_adr;
	while (*head_adr) {
		*head_adr = target->next;
		free(target);
		target = *head_adr;
	}
}

// Testing facut de Claude.
int main(void)
{
	struct node *head = NULL;

	// Test 1: operatii pe lista vida
	delete_start(&head);
	delete_end(&head);
	delete_pos(&head, 0);
	print(head);

	// Test 2: insert_start
	insert_start(&head, 3);
	insert_start(&head, 2);
	insert_start(&head, 1);
	print(head); // asteptat: 1 2 3

	// Test 3: insert_end
	insert_end(&head, 4);
	insert_end(&head, 5);
	print(head); // asteptat: 1 2 3 4 5

	// Test 4: insert_pos pozitie valida
	insert_pos(&head, 99, 0); // la inceput
	print(head); // asteptat: 99 1 2 3 4 5

	insert_pos(&head, 88, 3); // la mijloc
	print(head); // asteptat: 99 1 2 88 3 4 5

	insert_pos(&head, 77, nr_nodes(head)); // la final
	print(head); // asteptat: 99 1 2 88 3 4 5 77

	// Test 5: insert_pos pozitie invalida
	int ret = insert_pos(&head, 11, -1);
	printf("insert_pos(-1): %d\n", ret); // asteptat: -1

	ret = insert_pos(&head, 11, 999);
	printf("insert_pos(999): %d\n", ret); // asteptat: -1

	// Test 6: delete_start
	delete_start(&head);
	print(head); // asteptat: 1 2 88 3 4 5 77

	// Test 7: delete_end
	delete_end(&head);
	print(head); // asteptat: 1 2 88 3 4 5

	// Test 8: delete_pos pozitie valida
	delete_pos(&head, 0); // la inceput
	print(head); // asteptat: 2 88 3 4 5

	delete_pos(&head, 2); // la mijloc
	print(head); // asteptat: 2 88 4 5

	delete_pos(&head, nr_nodes(head) - 1); // la final
	print(head); // asteptat: 2 88 4

	// Test 9: delete_pos pozitie invalida
	delete_pos(&head, -1);
	delete_pos(&head, 999);
	print(head); // asteptat: 2 88 4

	// Test 10: search
	printf("search(88): %d\n", search(head, 88)); // asteptat: 0
	printf("search(99): %d\n", search(head, 99)); // asteptat: -1

	// Test 11: lista cu un singur element
	destroy(&head);
	insert_start(&head, 42);
	delete_start(&head);
	print(head); // asteptat: nimic, lista vida

	// Test 12: destroy
	insert_start(&head, 1);
	insert_start(&head, 2);
	insert_start(&head, 3);
	destroy(&head);
	print(head); // asteptat: nimic, lista vida
	printf("head dupa destroy: %p\n", (void *)head); // asteptat: (nil)

	return 0;
}

