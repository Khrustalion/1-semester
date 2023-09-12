#include <iostream>


int main() {
	int t; std::cin >> t;
	//int** resultats = new int* [t];
	for  (int i = 0; i < t; ++i) {
		int n, min_score = 15, max_score = 30; std::cin >> n;
		//resultats[i] = new int[n];
		for (int j = 0; j < n; ++j) {
			char sign[2];
			for (int i = 0; i < 2; ++i) {
				std::cin >> sign[i];
			}
			int score; std::cin >> score;
			if (sign[0] == '<' && score < max_score) {
				max_score = score;
			}
			else if (sign[0] == '>' && score > min_score) {
				min_score = score;
			}
			int res = min_score <= max_score ? min_score : -1;
			std::cout << res << '\n';
			//resultats[i][j] = res;
		}
	}

	return 0;
}