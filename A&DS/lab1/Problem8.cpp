#include <iostream>

int main()
{
    int n; std::cin >> n;
    int* rooms = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> rooms[i];
    }

    int first = 0, last = 0, cnt1 = 0;
    bool flag1 = false;


    for (int i = 1; i < n; ++i) {
        for (int j = last; j < i; ++j) {
            if ((rooms[i] & rooms[j]) != 0) {
                last = i;
                cnt1++;
                if (first == 0) {
                    first = i;
                }
                break;
            }
        }
    }
    for (int i = 0; i < first; ++i) {
        for (int j = last; j < n; ++j) {
            if ((rooms[i] & rooms[j]) != 0) {
                cnt1++;
                flag1 = true;
                break;
            }
        }
        if (flag1) {
            break;
        }
    }


    first = n - 1;
    last = n - 1;
    int cnt2 = 0;
    bool flag2 = false;

    for (int i = n - 2; i >= 0; --i) {
        for (int j = last; j > i; --j) {
            if ((rooms[i] & rooms[j]) != 0) {
                last = i;
                cnt2++;
                if (first == n - 1) {
                    first = i;
                }
                break;
            }
        }
    }
    for (int i = 0; i < last + 1; ++i) {
        for (int j = first + 1; j < n; ++j) {
            if ((rooms[i] & rooms[j]) != 0) {
                cnt2++;
                flag2 = true;
                break;
            }
        }
        if (flag2) {
            break;
        }
    }
    cnt1 = (cnt1 == 0) ? 1 : std::min(cnt1 == 1 ? 2 : cnt1, cnt2 == 1 ? 2 : cnt2);
    std::cout << cnt1;
    delete[] rooms;
    return 0;
}

