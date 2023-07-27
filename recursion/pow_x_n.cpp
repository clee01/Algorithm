/**
 * 题目描述：https://leetcode.com/explore/learn/card/recursion-i/256/complexity-analysis/2380/
 */

class Solution {
public:
    double myPow(double x, int n) {
        double res = doPow(x, std::abs(n));
        if (n < 0) {
            return 1 / res;
        }
        return res;
    }

    double doPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        double res = doPow(x, n / 2);
        res *= res;
        if (n & 1) {
            return res * x;
        }
        return res;
    }
};