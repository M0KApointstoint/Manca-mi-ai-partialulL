#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct queue {
	struct node *front;
	struct node *tail;
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

struct queue *create_queue(void)
{
	struct queue *new_queue = malloc(sizeof(struct queue));
	if (!new_queue) {
		return NULL;
	}
	new_queue->front = NULL;
	new_queue->tail = NULL;
	return new_queue;
}

int enqueue(struct queue *q, int data)
{
	if (!q) {
		return -1;
	}
	struct node *new_node = create_node(data);
	if (!new_node) {
		return -1;
	}
	if (!q->front) {
		q->front = new_node;
		q->tail = new_node;
		return 0;
	}
	q->tail->next = new_node;
	q->tail = new_node;
	return 0;
}

int dequeue(struct queue *q)
{
	if (!q || !q->front) {
		return -1;
	}
	if (q->front == q->tail) {
		free(q->front);
		q->front = NULL;
		q->tail = NULL;
		return 0;
	}
	struct node *target = q->front;
	q->front = target->next;
	free(target);
	return 0;
}

int front(struct queue *q, int *output_adr)
{
	if (!q || !q->front || !output_adr) {
		return -1;
	}
	*output_adr = q->front->data;
	return 0;
}

int is_empty(struct queue *q)
{
	if (!q) {
		printf("The queue was not initialized!\n");
		return 0;
	}
	if (!q->front) {
		printf("The queue is empty!\n");
		return 1;
	}
	printf("The queue is not empty!\n");
	return 0;
}

void print(struct queue *q)
{
	if (!q || !q->front) {
		return;
	}
	struct node *p = q->front;
	while (p) {
		printf("data: %d\n", p->data);
		p = p->next;
	}
}

void destroy_queue_list(struct queue *q)
{
	if (!q || !q->front) {
		return;
	}
	struct node *p = q->front;
	while (p) {
		struct node *target = p;
		p = p->next;
		free(target);
	}
	q->front = NULL;
	q->tail = NULL;
}

void destroy_queue(struct queue **q_adr)
{
	if (!q_adr || !*q_adr) {
		return;
	}
	destroy_queue_list(*q_adr);
	free(*q_adr);
	*q_adr = NULL;
}

int main(void)
{
	struct queue *q = create_queue();
	int value;

	// Test 1: coada vida
	printf("Test 1:\n");
	dequeue(q);
	front(q, &value);
	is_empty(q);
	print(q);

	// Test 2: enqueue
	printf("\nTest 2:\n");
	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);
	print(q); // asteptat: 1 2 3

	// Test 3: front
	printf("\nTest 3:\n");
	if (!front(q, &value)) {
		printf("Front: %d\n", value); // asteptat: 1
	}

	// Test 4: dequeue PAS CU PAS (clar)
	printf("\nTest 4:\n");

	dequeue(q);
	printf("Dupa dequeue 1:\n");
	print(q); // asteptat: 2 3

	dequeue(q);
	printf("Dupa dequeue 2:\n");
	print(q); // asteptat: 3

	dequeue(q);
	printf("Dupa dequeue 3:\n");
	print(q); // asteptat: gol

	// Test 5: dequeue pe gol
	printf("\nTest 5:\n");
	printf("dequeue empty: %d\n", dequeue(q)); // -1

	// Test 6: front pe gol
	printf("\nTest 6:\n");
	printf("front empty: %d\n", front(q, &value)); // -1

	// Test 7: reutilizare
	printf("\nTest 7:\n");
	enqueue(q, 42);
	print(q); // 42

	// Test 8: is_empty
	printf("\nTest 8:\n");
	is_empty(q);
	dequeue(q);
	is_empty(q);

	// Test 9: destroy
	printf("\nTest 9:\n");
	enqueue(q, 10);
	enqueue(q, 20);
	enqueue(q, 30);
	destroy_queue(&q);
	print(q);
	printf("q dupa destroy: %p\n", (void *)q); // (nil)

	return 0;
}

