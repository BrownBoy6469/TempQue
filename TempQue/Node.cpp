#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

// Default constructor
Node::Node() : data(), next(nullptr) {} // remember to initialize next to nullptr

// Parameterized constructor
Node::Node(string id, int year, int month, double temperature) : data(id,year,month,temperature), next(nullptr) {}
// remember to initialize next to nullptr

bool Node::operator<(const Node& b) {
	if(this->data < b.data) {
		return true;
	}
	else {
		return false;
	}
	
}
