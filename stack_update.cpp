/*
**** This application is made to implment the functionality of stack in C++ programming ****
How it works !
it is on the github.com site by searching my name ala al-hajj
*/
#include <iostream>
#include <stdlib.h>


using namespace std;

//Stack dynamic stack wiht double size Ala al-hajj

class stack {

private:
	int top;

public:
	int *array;
	int size;

	stack(): top(-1) {};

	friend void init(stack *sp, int size);
	void push(stack *sp, int );
	int pop(stack *sp);
	friend void dealloavtedMmeory(stack *);
	int getSize(stack *);

};


int getSize(stack *sp){

	return sp->size;
}

void init(stack *sp, int size) {
	sp->top = -1;
	sp->array = new int[size];
	if (sp-> array == NULL) {
		cout << "Unable to locate anything" << endl;
		exit(1);
	}
	sp->size = size;
}

void stack::push(stack *sp, int value) {
	if (sp->top == sp->size - 1) {
		int *temp;
		temp = new int[sp->size * 2];
		if(temp == NULL){
			cout << "The stack is overflow \n";
			return;
		}
		for (int i = 0; i <=sp->top;i++)
		{
			temp[i] = sp->array[i];
		}
		free(sp->array);
		sp->array=temp;
		sp->size *=2; 
	}

	sp->top ++;
	sp->array[sp->top] = value;
}

int stack::pop(stack *sp) {

	if (sp->top == -1) {
		cout << "underflow \n";

		exit(0);
	}

	int value;
	value = sp->array[sp->top];
	sp->top--;
	return value;
}

void dealloavtedMmeory(stack *sp) {
	if (sp->array != NULL)
		free(sp->array);

	sp->top = -1;
	sp->size = 0;
}

int main() {

	stack s1;
	init(&s1, 3);
	cout << "1. push \n 2. pop \n 3.exit \n";
	int choice, value;

	while (0) {
		cout << "Enter the choice: ";
		cin >> choice;
		cout << "the size of stack : "<< getSize(&s1)<<endl; 
		switch (choice) {
		case 1:
			cout << "Enter the value: ";
			cin >> value;
			s1.push(&s1, value);
			break;
		case 2:
			value  = s1.pop(&s1);
			if ( value != false) {
				cout << "Popped value : " << value << endl;
			}
			break;
		case 3: dealloavtedMmeory(&s1);
		exit(1);

		default: cout << "Invalide choice \n";
		break;
		}
	}
	return 0;
}