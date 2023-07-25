/**
 * 题目来源：https://leetcode.com/explore/learn/card/recursion-i/250/principle-of-recursion/1440/
 */

class Solution {
public:
    void reverseString(vector<char>& s) {
        doReverse(s, 0, s.size());
    }

    void doReverse(vector<char>& s, int index, int length) {
        if (index >= length) {
            return;
        }
        char tmp = s[index];
        doReverse(s, index + 1, length);
        s[length - index - 1] = tmp;
    }
};