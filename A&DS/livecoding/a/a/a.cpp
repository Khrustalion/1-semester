#include <iostream>
#include <vector>
#include <string>

int main() {
	std::vector<long long> stack;
	std::string str;
	long long num;
	while (std::cin >> str) {
		if (std::isdigit(str[0])) {
			stack.push_back(std::stoi(str));
		}
		else if (str == "*") {
			num = stack[stack.size()- 1] * stack[stack.size() - 2];
			stack.pop_back();
			stack.pop_back();
			stack.push_back(num);
		}
		else if (str == "+") {
			num = stack[stack.size() - 1] + stack[stack.size() - 2];
			stack.pop_back();
			stack.pop_back();
			stack.push_back(num);
		}
		else if (str == "-") {
			num = stack[stack.size() - 2] - stack[stack.size() - 1];
			stack.pop_back();
			stack.pop_back();
			stack.push_back(num);
		}
    }
	std::cout << stack[0];
	return 0;
}