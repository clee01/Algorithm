# 计数排序

## 简介
计数排序是一种线性时间的排序算法

## 稳定性
计数排序是一种稳定的排序算法

## 时间复杂度
计数排序的时间复杂度为$O(n+w)$，其中$w$代表待排序数据的值域大小

## 代码实现
```cpp
const int N = 100010;
const int W = 100010;

int n, w, a[N], cnt[W], b[N];

void counting_sort() {
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; ++i) {
    ++cnt[a[i]];
  }
  for (int i = 1; i <= w; ++i) {
    cnt[i] += cnt[i - 1];
  }
  for (int i = n; i >= 1; --i) {
    b[cnt[a[i]]--] = a[i];
  }
}
```