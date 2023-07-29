/**
 * 题目来源：https://leetcode.com/explore/learn/card/recursion-i/253/conclusion/1675/
 */

class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) {
            return 0;
        }
        if ((1 << (n - 2)) >= k) {
            return kthGrammar(n - 1, k);
        }
        return 1 - kthGrammar(n - 1, k - (1 << (n - 2)));
    }
};