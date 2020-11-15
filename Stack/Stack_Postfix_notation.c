#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element; // 연산자 스택 원소(element)의 자료형을 int로 정의

typedef struct stackNode { // 스택의 노드를 구조체로 정의
	element data;
	struct stackNode* link;
} stackNode;

stackNode* top = NULL; // 스택의 top 노드를 지정하기 위해 포인터 top 선언
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

int precedence(char op)
{
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}
void infix_to_postfix(char expr[])
{
	int i = 0;
	char c, op;
	while (expr[i] != '\0') {
		c = expr[i++];
		// 피연산자면 출력
		if ((c >= '0' && c <= '9')) {
			printf("%c ", c);
		}
		// 왼쪽 괄호면, 스택에 push
		else if (c == '(')
			push(c);
		// 오른쪽 괄호면, 왼쪽 괄호를 만날 때까지 출력
		else if (c == ')') {
			while (isEmpty() == 0) {
				op = pop();
				if (op == '(') break;
				else printf("%c ", op);
			}
		}
		// 연산자일 경우, 스택 안의 연산자의 우선순위가 높거나
		// 같은 연산자를 출력
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			while (isEmpty() == 0) {
				op = peek();
				if (precedence(c) <= precedence(op)) {
					printf("%c ", op);
					pop();
				}
				else break;
			}
			push(c);// 연산자 push
		}
	}
	while (isEmpty() == 0)// 스택에 남은 연산자를 모두 출력
		printf("%c ", pop());
	printf("\n");
}

int main() {
	char expr[2][80] = { "8 / 2 - 3 + (3 * 2)", "1 / 2 * 4 * (1 / 4)" };
	printf("중위수식: %s ==> 후위수식:", expr[0]);
	infix_to_postfix(expr[0]);
	printf("중위수식: %s ==> 후위수식:", expr[1]);
	infix_to_postfix(expr[1]);
}
