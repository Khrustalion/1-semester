#include <iostream>
#include <vector>
#include <string>


int main() {
	int* number = new int[1007]{ 0 };
	int n; std::cin >> n;
	std::string str;
	int str_size = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> str;
		if (str[0] == '-') {
			str_size = str.size();
			for (int i = str_size - 1; i >= 1; --i) {
				number[str_size - 1 - i] -= (str[i] - '0');
			}
		}
		else {
			str_size = str.size();
			for (int i = str_size - 1; i >= 0; --i) {
				number[str_size - 1 - i] += (str[i] - '0');
			}
		}
	}

	int current_rank = 0;
	int ind_number_start = 0;
	for (int i = 0; i <= 1007; ++i) {
		number[i] += current_rank;
		if (number[i] < 0) {
			number[i + 1] -= ((-number[i]) / 10 > 0) ? (-number[i]) / 10 : 1;
			number[i] = ((-number[i]) / 10 > 0) ? (-number[i]) % 10 : 10 -(-number[i]) % 10;
			current_rank = 0;
		}
		else {
			current_rank = number[i] / 10;
			number[i] %= 10;
		}
	}
	bool number_start = false;
	for (int i = 1006; i >= 0; --i) {
		if (number[i] && (!number_start)) {
			std::cout << number[i];
			number_start = true;
		}
		else if (number_start) {
			std::cout << number[i];
		}
	}
	if (!number_start) {
		std::cout << 0;
	}
	return 0;
}