# 递归

## 简介
递归，在数学和计算机科学中是指在函数的定义中使用函数自身的方法，在计算机科学中还额外指一种通过重复将问题分解为同类的子问题而解决问题的方法

递归代码最重要的两个特征：结束条件和自我调用。自我调用是在解决子问题，而结束条件定义了最简子问题的答案
```cpp
int func(传入数值) {
    if (终止条件) {
        return 最小子问题解;
    }
    return func(缩小规模);
}
```

## 为什么要写递归
* 结构清晰，可读性强。例如，分别用不同的方法实现 归并排序：
```cpp
// 不使用递归的归并排序算法
template<typename T>
void merge_sort(vector<T> a) {
    int n = a.size();
    for (int seg = 1; seg < n; seg = seg + seg) {
        for (int start = 0; start < n - seg; start += seg + seg) {
            merge(a, start, start + seg - 1, std::min(start + seg + seg - 1, n - 1));
        }
    }
}

// 使用递归的归并排序算法
template<typename T>
void merge_sort(vector<T> a, int front, int end) {
    if (front >= end) {
        return;
    }
    int mid = front + (end - front) / 2;
    merge_sort(a, front, mid);
    merge_sort(a, mid + 1, end);
    merge(a, front, mid, end);
}
```
* 练习分析问题的结构。当发现问题可以被分解成相同结构的小问题时，递归写多了就能敏锐发现这个特点，进而高效解决问题