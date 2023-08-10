# 快速排序

## 简介
快速排序，又称分区交换排序，简称「快排」，是一种被广泛运用的排序算法

## 稳定性
快速排序是一种不稳定的排序算法

## 时间复杂度
快速排序的最优时间复杂度和平均时间复杂度为$O(n\log{n})$，最坏时间复杂度为$O(n^2)$
  
## 代码实现
```cpp
struct Range {
  int start, end;

  Range(int s = 0, int e = 0) {
    start = s, end = e;
  }
};

template<typename T>
void quick_sort(T arr[], const int len) {
  if (len <= 0) {
    return;
  }

  Range r[len];
  int p = 0;
  r[p++] = Range(0, len - 1);
  while (p) {
    Range range = r[--p];
    if (range.start >= range.end) {
      continue;
    }
    T mid = arr[range.end];
    int left = range.start, right = range.end - 1;
    while (left < right) {
      while (arr[left] < mid && left < right) {
        left++;
      }
      while (arr[right] >= mid && left < right) {
        right--;
      }
      std::swap(arr[left], arr[right]);
    }
    if (arr[left] >= arr[range.end]) {
      std::swap(arr[left], arr[range.end]);
    } else {
      left++;
    }
    r[p++] = Range(range.start, left - 1);
    r[p++] = Range(left + 1, range.end);
  }
}
```