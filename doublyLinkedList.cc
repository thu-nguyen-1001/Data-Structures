#include<iostream>
using namespace std;

struct Node {
	int value;
	Node* prev;
	Node* next;
};

class DLList {
private:
	Node* head;
	Node* tail;
public:
	// constructor
	DLList() {
		head = nullptr;
		tail = nullptr;
	}
	// destructor
	~DLList() {}

	// display
	void display() {
		Node* temp = head;
		while(temp != tail) {
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	// get number of elements
	int size() {
		int count = 0;
		Node* temp = head;
		while(temp != tail) {
			count++;
			temp = temp->next;
		}
		return count;
	}

	// add new node
	void add(int val) {
		Node* newNode = new Node;
		newNode->value = val;
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		if (tail == nullptr) 
			tail = newNode;
	}
	// remove a value
	void remove(int val) {
		Node* temp = head;
	}

};

int main() {
	DLList list;
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);
	cout << "Size of list: " << list.size() << endl;
	cout << "Display: ";
	list.display();
	return 0;
}