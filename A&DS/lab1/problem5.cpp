#include <iostream>
#include <string>



int main()
{
    int n; std::cin >> n;
    bool flag = false;
    std::string word, res = "YES"; std::cin >> word;
    int i = 0, j = n - 1;
    while (i < j) {
        if (word[i] != word[j]) {
            if (not flag) {
                flag = true;
                j--;
            }
            else {
                res = "NO";
                break;
            }
        }
        else {
            i++;
            j--;
        }
    }
    if (res != "YES") {
        int i = 0, j = n - 1;
        bool flag = false;
        res = "YES";
        while (i < j) {
            if (word[i] != word[j]) {
                if (not flag) {
                    flag = true;
                    i++;
                }
                else {
                    res = "NO";
                    break;
                }
            }
            else {
                i++;
                j--;
            }
        }
    }
    std::cout << res;
    return 0;
}