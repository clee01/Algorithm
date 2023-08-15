# 基数排序

## 简介
基数排序是一种非比较型的排序算法，最早用于解决卡片排序的问题。基数排序将待排序的元素拆分为$k$个关键字，逐一对各个关键字排序后完成对所有元素的排序

如果是从第$1$关键字到第$k$关键字顺序进行比较，则该基数排序称为MSD（Most Significant Digit first）基数排序

如果是从第$k$关键字到第$1$关键字顺序进行比较，则该基数排序称为LSD（Least Significant Digit first）基数排序

## MSD基数排序
### 参考代码
* 对自然数排序
```cpp
// Buggy!
#include <algorithm>
#include <stack>
#include <tuple>
#include <vector>

using std::copy;
using std::make_tuple;
using std::stack;
using std::tie;
using std::tuple;
using std::vector;

typedef unsigned int u32;
typedef unsigned int* u32ptr;

void MSD_radix_sort(u32ptr first, u32ptr last) {
  // const size_t maxW = 0x100000000llu;
  const u32 maxlogW = 32;
  const u32 W = 256;  // 计数排序的值域
  const u32 logW = 8;
  const u32 mask = W - 1;  // 用位运算替代取模，详见下面的key函数

  u32ptr tmp = (u32ptr)calloc(last - first, sizeof(u32));  // 计数排序用的输出空间

  typedef tuple<u32ptr, u32ptr, u32> node;
  stack<node> s;
  s.push(make_tuple(first, last, maxlogW - logW));

  while (!s.empty()) {
    u32ptr begin, end;
    size_t shift, length;

    tie(begin, end, shift) = s.top();
    length = end - begin;
    s.pop();

    if (begin + 1 >= end) {
      continue;
    }

    // 计数排序
    u32 cnt[W] = {};
    auto key = [](const u32 x, const u32 shift) {
      return (x >> shift) & mask;
    };

    for (u32ptr it = begin; it != end; ++it) {
      ++cnt[key(*it, shift)];
    }
    for (u32 value = 1; value < W; ++value) {
      cnt[value] += cnt[value - 1];
    }

    // 求完前缀和后，计算相同关键字的元素范围
    if (shift >= logW) {
      s.push(make_tuple(begin, begin + cnt[0], shift - logW));
      for (u32 value = 1; value < W; ++value) {
        s.push(make_tuple(begin + cnt[value - 1], begin + cnt[value], shift - logW));
      }
    }

    u32ptr it = end;
    do {
      --it;
      --cnt[key(*it, shift)];
      tmp[cnt[key(*it, shift)]] = *it;
    } while (it != begin);

    copy(tmp, tmp + length, begin);
  }
}
```

* 对字符串排序