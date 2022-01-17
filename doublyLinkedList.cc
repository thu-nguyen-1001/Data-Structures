/*
 *	Implement doubly linked list 
 *	By: Thu
 *  Date: 01/06/2022
 */

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
	~DLList() {
		Node* temp = head;
		while (temp) {
			if (temp == head) {
				if (temp == tail) {
					head = nullptr;
					tail = nullptr;
				} else {
					head->next->prev = nullptr;
					head = head->next;
				}
				delete temp;
				return;
			}
		}
	}

	// display
	void display() {
		Node* temp = head;
		while(temp) {
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	// get number of elements
	int size() {
		int count = 0;
		Node* temp = head;
		while(temp) {
			count++;
			temp = temp->next;
		}
		return count;
	}

	// determine if the list contains a value
	bool contains(int val) {
		Node* temp = head;
		while(temp) {
			if (temp->value == val)
				return true;
			temp = temp->next;
		} 
		return false;
	}
	// add new node
	void add(int val) {
		Node* newNode = new Node;
		newNode->value = val;
		if (head == nullptr)
			head = newNode;
		else {
			head->prev = newNode;
			newNode->next = head;
			head = newNode;
		}
		if (tail == nullptr) 
			tail = newNode;
	}

	// remove a value
	void remove(int val) {
		Node* temp = head;
		while(temp) {
			if (temp->value == val) {
				if (temp == head && head == tail) {
					head = nullptr;
					tail = nullptr;
					delete temp;
					return;
				}
				if (temp == head) {
					head->next->prev = nullptr;
					head = head->next;
					delete temp;
					return;
				}
				if (temp == tail) {
					tail->prev->next = nullptr;
					tail = tail->prev;
					delete temp;
					return;
				}
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				delete temp;
				return;
			}
			temp = temp->next;
		}
	}
	// reverse the list
	void reverse() {
		Node* cur = head;
		Node* pre;
		Node* nex;
		while (cur != tail) {
			pre = cur->prev;
			nex = cur->next;
			cur->prev = nex;
			cur->next = pre;
			cur = nex;
		}
		if (tail) {
			tail->next = tail->prev;
			tail->prev = nullptr;
		}
		tail = head;
		head = cur;
	}

};

int main() {
	DLList list;
	list.add(0);
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);
	list.add(5);
	list.add(7);
	list.remove(0);
	cout << "Size of list: " << list.size() << endl;
	cout << "Display: ";
	list.display();
	cout << "Does the list contain 5? " << list.contains(5) << endl;
	cout << "Does the list contain 6? " << list.contains(6) << endl;
	cout << "Reverse list: " <<endl;
	list.reverse();
	list.display();
	return 0;
}