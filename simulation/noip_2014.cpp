/**
 * 题目来源: https://uoj.ac/problem/15
 */

#include <bits/stdc++.h>

const int MAXN = 200 + 10;
int n, na, nb, a[MAXN], b[MAXN], cnta, cntb;
int vs[5][5] = {
    {0, 0, 1, 1, 0},
    {1, 0, 0, 1, 0},
    {0, 1, 0, 0, 1},
    {0, 0, 1, 0, 1},
    {1, 1, 0, 0, 0}
};  // 得分表的处理

int main() {
    std::cin >> n >> na >> nb;
    for (int i = 0; i < na; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < nb; ++i) {
        std::cin >> b[i];
    }

    for (int i = 0; i < n; ++i) {
        cnta += vs[a[i % na]][b[i % nb]];
        cntb += vs[b[i % nb]][a[i % na]];
    }

    std::cout << cnta << " " << cntb << std::endl;
    return 0;
}