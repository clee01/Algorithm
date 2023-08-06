/**
 * 题目来源：https://www.luogu.com.cn/problem/P1209
 */

#include <bits/stdc++.h>

#define MAXN 205

using namespace std;

int m, s, c, ans;
int a[MAXN], C[MAXN];
bool cmp(int x, int y) {
  return x > y;
}

int main() {
  scanf("%d %d %d", &m, &s, &c);
  for (int i = 1; i <= c; ++i) {
    scanf("%d", &a[i]);
  }
  if (m > c) {  // 特殊判断，如果木板数大于牛数，那么每头牛可以有一块木板
    printf("%d\n", c);
    return 0;
  }
  sort(a + 1, a + c + 1);
  ans = a[c] - a[1] + 1;  // 假设只有一块木板连续的铺着
  for (int i = 2; i <= c; ++i) {
    C[i - 1] = a[i] - a[i - 1];
  }
  sort(C + 1, C + c, cmp);
  for (int i = 1; i <= m - 1; ++i) {
    ans = ans - C[i] + 1;
  }
  printf("%d\n", ans);
}