#include <iostream>
#include <math.h>


unsigned long long binn(bool* arr, int n) {
	unsigned long long res = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] == 1) {
			res += pow(2, n - i - 1);
		}
		
	}
	return res;
}


int main() {
	unsigned long long x, y;
	std::cin >> x >> y;
	bool flag1 = false, flag2 = true;
	int cnt = 0;
	for (int n = 3; n < 61; n++) {
		for (int i = 0; i < n - 2; ++i) {
			bool* num = new bool[n] {0};
			for (int k = 0; k < i+1; ++k) {
				num[k] = 1;
			}
			for (int j = n-1; j > i + 1; --j) {
				num[j] = 1;
				cnt++;
				if (flag2 && binn(num, n) >= x){
					cnt = 1;
					flag2 = false;
				}
				if (binn(num, n) > y) {
					cnt--;
					flag1 = true;
					break;
				}
			}
			delete[]num;
			if (flag1) {
				break;
			}
		}
		if (flag1) {
			break;
		}
	}
	std::cout << cnt;
	return 0;
}