class Solution {
 public:
  uint32_t reverseBits(uint32_t n) { return doReverse(n, 31); }

  uint32_t doReverse(uint32_t n, int num) {
    if (!n) {
      return 0;
    }
    return ((n & 1) << num) + doReverse(n >> 1, num - 1);
  }
};