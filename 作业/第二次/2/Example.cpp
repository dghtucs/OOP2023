#include <iostream>
#include "Example.h"

using namespace std;

	// (2)
int Example::count = 0;

Example::Example(int data) {
	// (3)
	data_ = data;
	count++;
	id = count;
	cout << "Example #" << id << " is created" << endl;
}

void Example::getData() {
	// (4)
	cout << "The data of Example #" << id << " is " << data_ << endl;
}

Example::~Example() {
	// (5)
	cout << "Example #" << id << " is destroyed" << endl;
}