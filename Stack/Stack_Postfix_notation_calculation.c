#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;// 피연산자 스택 원소(element)의 자료형을 int로 정의

typedef struct stackNode { // 스택의 노드를 구조체로 정의
	element data;
	struct stackNode* link;
} stackNode;
stackNode* top = NULL;

// 스택 관련 함수는 이전과 동일함
int isEmpty() {
	if (top == NULL) return 1;
	else return 0;
}

void push(element item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;
	top = temp;
}

element pop() {
	element item;
	stackNode* temp = top;

	if (top == NULL) {
		printf("\n\n Stack is empty!\n");
		return 0;
	}
	else {
		item = temp->data;
		top = temp->link;
		free(temp);
		return item;
	}
}

element peek() {
	if (top == NULL) {
		printf("\n\n Stack is empty!\n");
		return 0;
	}
	else {
		return (top->data);
	}
}

element evalPostfix(char* exp) {
	int opr1, opr2, value, i = 0;
	int lenth = strlen(exp);
	char symbol;
	top = NULL;

	for (i = 0; i < lenth; i++) {
		symbol = exp[i];
		if (symbol != '+' && symbol != '-' &&
			symbol != '*' && symbol != '/') {
			value = symbol - '0';
			push(value);
		}
		else {
			opr2 = pop();
			opr1 = pop();
			switch (symbol) {
			case '+': push(opr1 + opr2); break;
			case '-': push(opr1 - opr2); break;
			case '*': push(opr1 * opr2); break;
			case '/': push(opr1 / opr2); break;
			}
		}
	}
	return pop();
}
int main() {
	int result;
	char* express = "35*62/-";
	printf("후위 표기식 : %s", express);
	result = evalPostfix(express);
	printf("\n\n연산 결과 => %d", result);
}
