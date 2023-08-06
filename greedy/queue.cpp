/**
 * 题目来源：https://www.luogu.com.cn/problem/P2123
 */

// hint: https://www.luogu.com.cn/problem/solution/P2123

#include <bits/stdc++.h>

using namespace std;

struct node {
  int x, y, d;
  bool operator<(node a) const {
    if (d != a.d) {
      return d < a.d;
    }
    if (d <= 0) {
      return x < a.x;
    }
    return y > a.y;
  }
} a[20005];

int t, n;
long long c[20005];

int main() {
  cin >> t;
  for (int k = 1; k <= t; ++k) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i].x >> a[i].y;
      if (a[i].x > a[i].y) {
        a[i].d = 1;
      } else if (a[i].x < a[i].y) {
        a[i].d = -1;
      } else {
        a[i].d = 0;
      }
    }
    sort(a + 1, a + n + 1);
    long long s = 0;
    for (int i = 1; i <= n; ++i) {
      s += a[i].x;
      c[i] = max(c[i - 1], s) + a[i].y;
    }
    cout << c[n] << "\n";
  }
}