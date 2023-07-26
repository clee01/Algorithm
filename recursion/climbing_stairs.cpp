/**
 * 题目来源：https://leetcode.com/explore/learn/card/recursion-i/255/recursion-memoization/1662/
 */

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        std::vector<int> res{1, 2};
        for (int i = 2; i < n; ++i) {
            int tmp = res[0] + res[1];
            res[0] = res[1];
            res[1] = tmp;
        }
        return res[1];
    }
};