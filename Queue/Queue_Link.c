#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

typedef struct {
	int data;
	struct Node* next;
}Node;

typedef struct {
	Node* front;
	Node* rear;
	int count;//queue에 포함되어 있는 원소의 개수를 담음
}Queue;

void push(Queue* queue, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	if (queue->count == 0) {
		queue->front = node;
	}
	else {
		queue->rear->next = node;
	}
	queue->rear = node;
	queue->count++;
}
int pop(Queue* queue) {
	if (queue->count == 0) {
		printf("underflow\n");
		return -INF;
	}
	Node* node = queue->front;
	int data = node->data;
	queue->front = node->next;
	free(node);
	queue->count--;
	return data;
}
void show(Queue* queue) {
	Node* cur = queue->front;
	printf("---Queue's front---\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("---Queue's rear---\n");
}
int main(void) {
	Queue queue;
	queue.front = queue.rear = NULL;
	queue.count = 0;
	push(&queue, 7);
	push(&queue, 5);
	push(&queue, 4);
	pop(&queue);
	push(&queue, 6);
	pop(&queue);
	show(&queue);
	system("pause");
	return 0;
}
