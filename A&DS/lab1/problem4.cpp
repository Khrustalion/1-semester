#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);


    int n, m, q, cnt = 0;
    std::cin >> n >> m >> q;
    bool** seriess = new bool* [n];
    for (int i = 0; i < n; ++i) {
        seriess[i] = new bool[m] { false };
    }


    for (int i = 0; i < q; ++i) {
        int season, series;
        std::cin >> series >> season;
        if (not seriess[season-1][series-1]) {
            cnt += 1;
        }
        seriess[season-1][series-1] = true;
    }

    std::cout << n * m - cnt << std::endl;
    for (int season = 0; season < n; ++season) {
        for (int series = 0; series < m; ++series) {
            if (not seriess[season][series]) std::cout << series + 1 << " " << season + 1 << '\n';
        }
    }
    return 0;
}
