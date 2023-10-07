#include <iostream>


int main() {
	int x = 256;
	int* pi = &x;
	bool* pb = (bool *) pi;
	std::cout << *pb << "\n";
	return 0;
}