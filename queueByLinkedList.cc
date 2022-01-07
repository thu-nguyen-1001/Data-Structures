/*
 *	Implement queue using doubly linked list 
 *	By: Thu
 *  Date: 01/07/2022
 */
#include<iostream>
using namespace std;

struct Node {
	int value;
	Node* prev;
	Node* next;
};

class Queue {
private:
	Node* front;
	Node* rear;
public:
	// constructor
	Queue() {
		front = nullptr;
		rear = nullptr;
	}
	// destructor
	~Queue() {

	}
	// display
	void display() {
		Node* temp = rear;
		while (temp) {
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	// get number of elements
	int size() {
		int count = 0;
		Node* temp = rear;
		while (temp) {
			count++;
			temp = temp->next;
		}
		return count;
	}
	// add a new node at rear
	void enqueue(int val) {
		Node* newNode = new Node;
		newNode->value = val;
		if (rear == nullptr) { 
			rear = newNode;	
		} else {
			rear->prev = newNode;
			newNode->next = rear;
			rear = newNode;
		}
		if (front == nullptr) 
			front = newNode;
	}
	// remove a node at front
	void dequeue() {
		Node* temp = front;
		if (rear == front) {
			if (temp) { 
				delete temp;
				rear = nullptr;
				rear = nullptr;
			}
			return;
		}
		front = front->prev;
		delete temp;
		front->next = nullptr;
	}
};

int main() {
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.dequeue();
	q.display();
	return 0;
}