#include <iostream>
#include <string>


int main() {
	int t; std::cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, min_score = 15, max_score = 30; std::cin >> n;
		for (int j = 0; j < n; ++j) {
			std::string sign; std::cin >> sign;
			int score; std::cin >> score;
			if (sign == "<=" && score < max_score) {
				max_score = score;
			}
			else if (sign == ">=" && score > min_score) {
				min_score = score;
			}
			int res = min_score <= max_score ? min_score : -1;
			std::cout << res << std::endl;
		}
	}
	return 0;
}