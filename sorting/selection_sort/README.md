# 选择排序

## 简介
选择排序是一种简单直观的排序算法。它的工作原理是每次找出第$i$小的元素（也就是$A_{i..n}$中最小的元素），然后将这个元素与数组第$i$个位置上的元素交换

## 稳定性
由于swap（交换两个元素）操作的存在，选择排序是一种不稳定的排序算法

## 时间复杂度
选择排序的最优时间复杂度、平均时间复杂度和最坏时间复杂度均为$O(n^2)$

## 代码实现
```cpp
void selection_sort(int* a, int n) {
  for (int i = 1; i < n; ++i) {
    int ith = i;
    for (int j = i + 1; j <= n; ++j) {
      if (a[j] < a[ith]) {
        ith = j;
      }
    }
    std::swap(a[i], a[ith]);
  }
}
```