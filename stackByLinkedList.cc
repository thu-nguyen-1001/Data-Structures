/*
 *	Implement stack using linked list 
 *	By: Thu
 *  Date: 12/25/2021
 */
#include <iostream>
using namespace std;

struct Node {
	int value;
	Node* next;
};

class StackL {
private: 
	Node* top;
public:
	// constructor
	StackL() {
		top = nullptr;
	}
 	
 	// destructor
 	~StackL() {
 		clear();
 		top = nullptr;
 	}
 	
 	// remove all elements in the stack
	void clear() {
		Node* temp = top;
		while (temp) {
			top = temp->next;
			delete temp;
			temp = top;
		}
	}
	
	// check if the stack is empty
	bool isEmpty() {
		return (top == nullptr);
	}
	
	// determine if stack contains a value
	bool contains(int val) {
		Node* temp = top;
		while (temp) {
			if (temp->value == val)
				return true;
			temp = temp->next;
		} 
		return false;
	}
	
	// get number of elements
	int size() {
		int count = 0;
		Node* temp = top;
		while (temp) {
			count++;
			temp= temp->next;
		}
		return count;
	}

	// get the value at the top without removing
	int peek() {
		try {
			if (!top)
				throw "Empty stack";
			else
				return top->value;
		} catch (exception &e) {
			cout << "Empty stack\n";
		}
		return -1;
	}

	// get and return the value at the top
	int pop() {
		try {
			if (!top)
				throw ;
			else {
				int val = top->value;
				Node* temp = top;
				top = top->next;
				delete temp;
				return val;
			}
		} catch (exception &e) {
			cout <<"Empty stack\n";
		}
		return -1;
	}
	
	// add a value to the stack
	void push(int val) {
		Node* newNode = new Node;
		newNode->value = val;
		newNode->next = top;
		top = newNode;
	}

	// display all elements
	void print() {
		Node* temp = top;
		while (temp) {
			cout << temp->value << " ";
			temp = temp->next;
		} 
		cout << "\n";
	}
};

int main() {
	StackL s;
	s.push(5);
	s.push(7);
	s.push(23);
	s.push(35);
	s.print();
	cout << s.peek() << endl;
	cout << s.pop() << endl;
	s.print();
	return 0;
}