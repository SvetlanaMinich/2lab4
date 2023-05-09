#include<iostream>
#include "shared_ptr.h"
#include "unique_ptr.h"
int main() {

	unique_ptr<int>* a = new unique_ptr<int>(new int(1));
	unique_ptr<int>* b = new unique_ptr<int>();
	b = std::move(a);

	return 0;
}