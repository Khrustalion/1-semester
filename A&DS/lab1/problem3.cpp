#include <iostream>


int main() {
	int a, b;
	std::cin >> a >> b;
	if (a < b) {
		std::swap(a, b);
	}
	while (b != 0) {
		a = a % b;
		std::swap(a, b);
	}
	std::cout << a;
	return 0;
}