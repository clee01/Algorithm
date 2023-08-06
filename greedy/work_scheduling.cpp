/**
 * 题目来源：https://www.luogu.com.cn/problem/P2949
 */

#include <bits/stdc++.h>

using namespace std;

struct f {
  long long d;
  long long p;
} a[100005];

bool cmp(f A, f B) {
  return A.d < B.d;
}

priority_queue<long long, vector<long long>, greater<long long>>
    q;  // 小跟堆维护最小值

int main() {
  long long n, i;
  cin >> n;
  for (i = 1; i <= n; ++i) {
    scanf("%lld%lld", &a[i].d, &a[i].p);
  }
  sort(a + 1, a + n + 1, cmp);
  long long ans = 0;
  for (i = 1; i <= n; ++i) {
    if (a[i].d <= (int)q.size()) {  // 超过截止时间
      if (q.top() < a[i].p) {       // 后悔了
        ans += a[i].p - q.top();
        q.pop();
        q.push(a[i].p);
      }
    } else {
      ans += a[i].p;
      q.push(a[i].p);
    }
  }
  cout << ans << endl;
  return 0;
}