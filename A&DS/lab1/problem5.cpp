#include <iostream>


int main()
{
    int n; std::cin >> n;
    bool flag = false, res = true;

    char* word = new char[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> word[i];
    }
    int i = 0, j = n - 1;
    while (i < j) {
        if (word[i] != word[j]) {
            if (not flag) {
                flag = true;
                j--;
            }
            else {
                res = false;
                break;
            }
        }
        else {
            i++;
            j--;
        }
    }
    if (not res) {
        int i = 0, j = n - 1;
        bool flag = false;
        res = true;
        while (i < j) {
            if (word[i] != word[j]) {
                if (not flag) {
                    flag = true;
                    i++;
                }
                else {
                    res = false;
                    break;
                }
            }
            else {
                i++;
                j--;
            }
        }
    }
    if (res) {
        std::cout << "YES";
    }
    else {
        std::cout << "NO";
    }
    return 0;
}