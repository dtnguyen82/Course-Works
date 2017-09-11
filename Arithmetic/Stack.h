#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct node {
	string letter;
	node* next;
	node() {
		letter = "";
		next = NULL;
	};
};

class Stack {
public:
	Stack();   // default construct
	~Stack();  // deconstruct
	node* GetHead() const;
	void push(string op);
	void pop();
	string top();
	bool isEmpty() const;
	void destroyList();
	void Print() const;
public:
	node* head;
	int count = 0;
};

Stack::Stack()
{
	head = NULL;
	count = 0;
}

Stack::~Stack() {
	destroyList();
}

void Stack::destroyList() {
	node * temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		delete temp;
	}
	count = 0;
}
node* Stack::GetHead()const {
	return head;
}
bool Stack::isEmpty() const {
	return (head == NULL);
}
string Stack::top() {
	return head->letter;
}
void Stack::push(string op) {
	node* newNode = new node();
	if (head == NULL) {
		head = newNode;
		newNode->letter = op;
		newNode->next = NULL;
	}
	else {
		newNode->letter = op;
		newNode->next = head;
		head = newNode;
	}
	count++;
}
void Stack::pop() {
	node *temp = new node();
	if (head != NULL) {
		temp = head;
		head = head->next;
		delete temp;
		count--;
	}
	else
		return;
}
void Stack::Print() const {
	node *current;
	current = head;
	if (current == NULL) {
		return;
	}
	while (current != NULL) {
		if (current == head) { //print the head first
			cout << current->letter;
		}
		else
			cout << setfill('0') << current->letter; //add 0 infront of numbers until it have the digitspernode size
		current = current->next;
	}
	cout << endl;
}
#endif
