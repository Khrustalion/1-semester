#include <iostream>
#include <vector>


int main() {
	int n; std::cin >> n;
	std::vector <int> nums(n+1, 0);
	for (int i = 1; i <= n; ++i) {
		std::cin >> nums[i];
		nums[i] += nums[i - 1];
	}
	int sum_r = nums[n], index = -1;
	for (int i = 1; i <= n; i++) {
		if (nums[i-1] == sum_r - nums[i]) {
			index = i - 1;
			break;
		}
	}
	std::cout << index;
	return 0;
}