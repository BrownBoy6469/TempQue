#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::~LinkedList() {
	clear();
}

LinkedList::LinkedList(const LinkedList& source) : head(nullptr), tail(nullptr) {
	//cout << "copy constructor" << endl;
	Node* current = source.head;
	while(current != nullptr) {
		insert(current->data.id,current->data.year,current->data.month,current->data.temperature);
		current = current->next;
	}
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	//cout << "copy assignment" << endl;
	Node* current = source.head;
	while(current != nullptr) {
		insert(current->data.id,current->data.year,current->data.month,current->data.temperature);
		current = current->next;
	}
	return *this;
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	if(temperature < -50 or temperature > 50)  {
		cout << "Error: Invalid temperature " << temperature << endl;
		return;
	}
	if(year < 1800 or year > 2022) {
		cout << "Error: Invalid year " << year << endl;
		return;
	}
	if(month < 1 or month > 12) {
		cout << "Error: Invalid month " << month << endl;
	}
	
	Node *newNode = new Node(location, year, month, temperature);
	Node *current = head;

	// cout << newNode->data.id << endl;
	// cout << newNode->data.year << endl;
	// cout << newNode->data.month << endl;
	// cout << newNode->data.temperature << endl;
	// cout << endl;
	// cout << current->data.id << endl;
	// cout << current->data.year << endl;
	// cout << current->data.month << endl;
	// cout << current->data.temperature << endl;	
	// cout << (newNode->data < current->data) << endl;

	if(current == nullptr) {
		// no nodes in ll
		//cout << "ll is empty" << endl;
		head = newNode;
		tail = newNode;
		return;
	}	

	if(*newNode < *current) {
		// new node is now head
		//cout << "newNode is now the head" << endl;
		newNode->next = current;
		head = newNode;
		return;
	}

	Node *prev = current;
	current = current->next;
	while(current != nullptr) {
		if(*newNode < *current) {
			//cout << "newNode is in the middle" << endl;
			newNode->next = current;
			prev->next = newNode;
			return;
		}
		else {
			prev = current;
			current = current->next;
		}
	}

	// new node is at the end
	//cout << "newNode is now the tail" << endl;
	prev->next = newNode;
	tail = newNode;	
	newNode->next = nullptr;
}

void LinkedList::clear() {
	Node *current = head;
	while(current != nullptr) {
		Node *temp = current->next;
		delete current;
		current = temp;
	}
	head = nullptr;
	tail = nullptr;
}

Node* LinkedList::getHead() const {
	return head;
}

string LinkedList::print() const {
	string outputString;
	Node *current = head;
	while(current != nullptr) {
		outputString += current->data.id;
		outputString += " ";
		outputString += to_string(current->data.year);
		outputString += " ";
		outputString += to_string(current->data.month);
		outputString += " ";
		string tempStr = to_string(current->data.temperature);
		for(int i = tempStr.size() - 1; i >= 0; i--) {
			if(tempStr[i] != '0') {
				tempStr.erase(i + 1, tempStr.size() - 1);
				break;
			}
		}
		if(tempStr.back() == '.')
			tempStr.pop_back();
		outputString += tempStr;
		outputString += "\n";

		current = current->next;
	}
	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}
