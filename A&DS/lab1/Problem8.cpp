#include <iostream>

int main()
{
    int n; std::cin >> n;
    int* rooms1 = new int[3*n];
    for (int i = 0; i < n; ++i) {
        std::cin >> rooms1[i];
        rooms1[n + i] = rooms1[i];
        rooms1[2 * n + i] = rooms1[i];
    }


    int cnt = 0, last = 0;
    for (int i = 1; i < n*3; ++i) {
        for (int j = last; j < i; ++j) {
            if ((rooms1[i] & rooms1[j]) != 0) {
                last = i;
                cnt += 1;
                break;
            }
        }
    }
    std::cout << (cnt+cnt % 3)/3;
    delete[] rooms1;
    return 0;
}

