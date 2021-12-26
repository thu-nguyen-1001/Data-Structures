/*
 * Implement unordered singly linked list
 */
#include<iostream>
using namespace std;

struct Node {
	int value;
	Node* next;
};

class SLList {
private:
	Node* head;
public:
	// constructor
	SLList() {
		head = nullptr;
	}

	// destructor
	~SLList() {}

	// display all elements to console
	void print() {
		Node* temp = head;
		while(temp) {
			cout << temp->value << " ";
			temp = temp->next;
		}
	}

	// get number of all elements
	int size() {
		int count = 0;;
		Node* temp = head;
		while(temp) {
			count++;
			temp = temp->next;
		}
		return count;
	}

	// determine if a value is in the list
	bool contains(int val) {
		Node* temp = head;
		while(temp) {
			if (temp->value == val) 
				return true;
			else 
				temp = temp->next;
		}
		return false;
	}

	// add a value
	void add(int val) {
		Node* temp = new Node;
		temp->value = val;
		temp->next = head;
		head = temp;
	}

	// remove a node containing given value
	void remove(int val) {

	}
};

int main() {
	SLList sllist;
	sllist.add(1);
	sllist.add(2);
	sllist.add(3);
	sllist.add(4);
	sllist.print();
	return 0;
}