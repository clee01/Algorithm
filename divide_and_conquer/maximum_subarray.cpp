/**
 * 题目来源：https://leetcode.com/problems/maximum-subarray/
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return doMax(nums, 0, nums.size() - 1);
    }

    int doMax(vector<int>& nums, int start, int end) {
        if (start == end) {
            return nums[start];
        }
        if (nums[start] > 0) {
            nums[start + 1] += nums[start];
        }
        return std::max(nums[start], doMax(nums, start + 1, end));
    }
};