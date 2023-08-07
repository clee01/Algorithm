# 插入排序

## 简介
插入排序是一种简单直观的排序算法。它的工作原理为将待排序元素划分为「已排序」和「未排序」两部分，每次从「未排序的」元素中选择一个插入到「已排序的」元素中的正确位置

## 稳定性
插入排序是一种稳定的排序算法

## 时间复杂度
插入排序的最优时间复杂度为$O(n)$，在数列几乎有序时效率很高

插入排序最坏时间复杂度和平均时间复杂度都为$O(n^2)$

## 代码实现
```cpp
void insertion_sort(int arr[], int len) {
  for (int i = 1; i < len; ++i) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}
```

# 折半插入排序

## 简介
插入排序还可以通过二分算法优化性能，在排序元素较多时优化的效果比较明显

## 时间复杂度
折半插入排序与直接插入排序的基本思想是一致的，折半插入排序仅对插入排序时间复杂度中的常数进行了优化，所以优化后的时间复杂度仍然不变

## 代码实现
```cpp
void insertion_sort(int arr[], int len) {
  if (len < 2) {
    return;
  }
  for (int i = 1; i != len; ++i) {
    int key = arr[i];
    auto index = upper_bound(arr, arr + i, key) - arr;
    // 使用memmove移动元素，比使用for循环速度快，时间复杂度仍为O(n)
    memmove(arr + index + 1, arr + index, (i - index) * sizeof(int));
    arr[index] = key;
  }
}
```