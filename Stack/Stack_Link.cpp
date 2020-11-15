#include <iostream>	
using namespace std;

typedef int element;

typedef struct stackNode {
	element data;
	struct stackNode* link;
}stackNode;

stackNode* top;

int isEmpty() {
	if (top == NULL) return 1;
	else return 0;
}

void push(element item) {
	stackNode* temp = new stackNode ;
	temp->data = item;
	temp->link = top;
	top = temp;
}

element pop() {
	element item;
	stackNode* temp = top;

	if (top == NULL) {
		cout << endl << endl << "Stack is empty!" << endl;
		return 0;
	}
	else {
		item = temp->data;
		top = temp->link;
		delete temp;
		return item;
	}
}

element peek() {
	if (top == NULL) {
		cout<<endl<<endl<<"Stack is empty!"<<endl;
		return 0;
	}
	else {
		return (top->data);
	}
}

void printStack() {
	stackNode* p = top;
	cout<<endl<<"STACK [ ";
	while (p) {
		cout<<p->data<<" ";
		p = p->link;
	}
	cout<<"] ";
}

int main() {
	element item;
	top = NULL;
	cout<<endl<<"Link stack operation "<<endl;
	printStack();
	push(1); printStack();
	push(2); printStack();
	push(3); printStack();

	item = peek(); printStack();
	cout<<"peek=>"<<item;

	item = pop(); printStack();
	cout << "pop=>" << item;

	item = pop(); printStack();
	cout << "pop=>" << item;

	item = pop(); printStack();
	cout << "pop=>" << item;
}
