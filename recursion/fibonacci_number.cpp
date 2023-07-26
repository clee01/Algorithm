/**
 * 题目来源：https://leetcode.com/explore/learn/card/recursion-i/255/recursion-memoization/1661/
 */

class Solution {
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        }

        if (n == 1) {
            return 1;
        }

        return fib(n - 1) + fib(n - 2);
    }
};