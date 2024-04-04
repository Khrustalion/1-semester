#include <iostream>
#include <string>

struct Card {
	long long damage = 0;
	std::string name = "";
};


int binary_search_right(long long x, Card* cards, int n) {
	if (x < cards[0].damage) {
		return -1;
	}
	else if (x > cards[n - 1].damage) {
		return n - 1;
	}
	long long i = 0, j = n, mid;
	while (i + 1 < j) {
		mid = (i + j) / 2;
		if (cards[mid].damage > x) j = mid;
		else i = mid;
	}
	return i;
}

int binary_search_left(long long x, Card* cards, int n) {
	if (x <= cards[0].damage) {
		return 0;
	}
	else if (x > cards[n - 1].damage) {
		return n;
	}
	long long i = 0, j = n, mid;
	while (i + 1 < j) {
		mid = (i + j) / 2;
		if (cards[mid].damage >= x) j = mid;
		else i = mid;
	}
	return j;
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, damage = 0, min = -1, max = -1; std::cin >> n;
	std::string name;
	Card* tmp = new Card[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> damage;
		tmp[i].damage = damage;
		if (min == -1 || damage < min) {
			min = damage;
		}
		if (max == -1 || damage > max) {
			max = damage;
		}
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> name;
		tmp[i].name = name;
	}

	int* cnt = new int[max - min + 1] {0};

	Card* cards = new Card[n];
	for (int i = 0; i < n; ++i) {
		++cnt[tmp[i].damage - min];
	}
	for (int i = 1; i < max - min + 1; ++i) {
		cnt[i] += cnt[i - 1];
	}

	for (int i = n - 1; i >= 0; --i) {
		cards[(cnt[tmp[i].damage - min]--) - 1] = tmp[i];
	}
	delete[] tmp;

	long long* prefix_sum = new long long[n + 1] {0};
	long long* prefix_xor = new long long[n + 1] {0};

	for (int i = 0; i < n; ++i) {
		std::cout << cards[i].damage;
		if (i != n - 1) {
			std::cout << " ";
		}

		prefix_sum[i + 1] = prefix_sum[i] + cards[i].damage;
		prefix_xor[i + 1] = prefix_xor[i] ^ cards[i].damage;

	}
	std::cout << '\n';
	for (int i = 0; i < n; ++i) {
		std::cout << cards[i].name;
		if (i != n - 1) {
			std::cout << " ";
		}
	}
	std::cout << '\n';

	int q; std::cin >> q;
	long long l, r;
	int l_i, r_i;
	std::string action;
	for (int i = 0; i < q; ++i) {
		std::cin >> action >> l >> r;

		r_i = binary_search_right(r, cards, n);
		l_i = binary_search_left(l, cards, n);

		if (action == "Count") {
			std::cout << r_i - l_i + 1 << '\n';
		}
		else if (action == "Sum") {
			std::cout << prefix_sum[r_i + 1] - prefix_sum[l_i] << '\n';
		}
		else if (action == "Xor") {
			std::cout << (prefix_xor[r_i + 1] ^ prefix_xor[l_i]) << '\n';
		}
	}
	return 0;
}