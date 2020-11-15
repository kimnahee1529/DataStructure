#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;
typedef struct stackNode {
	element data;
	struct stackNode* link;
 }stackNode;

stackNode* top = NULL;

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
int testPair(char* exp) {
	char symbol, open_pair;
	// char형 포인터 매개변수로 받은 수식 exp의 길이를 계산하여 length 변수에 저장
	int i, length = strlen(exp);
	top = NULL;

	for (i = 0; i < length; i++) {
		symbol = exp[i];
		switch (symbol) {
			// (1) 왼쪽 괄호는 스택에 삽입
		case '(':
		case '[':
		case '{':
			push(symbol); break;
			// (2) 오른쪽 괄호를 읽으면,
		case ')':
		case ']':
		case '}':
			if (top == NULL) return 0;
			else {
				// (2)-1 스택에서 마지막으로 읽은 괄호를 꺼냄
				open_pair = pop();
				// (2)-2 괄호 쌍이 맞는지 검사
				if ((open_pair == '(' && symbol != ')') ||
					(open_pair == '[' && symbol != ']') ||
					(open_pair == '{' && symbol != '}'))
					return 0; // 틀리면 0 반환
				else break; // 맞으면 다음 symbol 검사
			}
		}
	}
	// 수식 검사를 마친 후 스택이 공백이면 1을 반환
	if (top == NULL) return 1;
	else return 0; // 공백이 아니면 0을 반환(수식 괄호 틀림)
}

int main() {
	char express[100];
	for (;;) {
		printf("Enter the expresstion: ");
		scanf("%s", express);

		if (testPair(express) == 1)
			printf("right\n\n");
		else
			printf("wrong\n\n");
	}
}
