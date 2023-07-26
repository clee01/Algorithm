/**
 * 题目来源：https://leetcode.com/explore/learn/card/recursion-i/251/scenario-i-recurrence-relation/3234/
 */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) {
            return vector<int>{1};
        }
        std::vector<int> res = getRow(rowIndex - 1);
        res.insert(res.begin(), 1);
        for (int i = 1; i < res.size() - 1; ++i) {
            res[i] += res[i + 1];
        }
        return res;
    }
};