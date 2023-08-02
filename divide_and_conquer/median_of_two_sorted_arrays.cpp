/**
 * 题目来源：https://leetcode.com/problems/median-of-two-sorted-arrays/
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return doFind(nums1, nums2, 0, nums1.size() - 1, 0, nums2.size() - 1);
    }

    double doFind(const vector<int>& nums1, const vector<int>& nums2, int start1, int end1, int start2, int end2) {
        if (start1 > end1) {
            return halfArrays(nums2, start2, end2);
        }
        if (start2 > end2) {
            return halfArrays(nums1, start1, end1);
        }

        // 考虑两个数组每个都只剩一条数据，此时可以直接得出结果
        if (start1 == end1 && start2 == end2) {
            return (nums1[start1] + nums2[start2]) / 2.0;
        }
        if (nums1[start1] > nums2[start2]) {
            if (nums1[end1] > nums2[end2]) {
                return doFind(nums1, nums2, start1, end1 - 1, start2 + 1, end2);
            }
            return doFind(nums1, nums2, start1, end1, start2 + 1, end2 - 1);
        }
        if (nums1[end1] > nums2[end2]) {
            return doFind(nums1, nums2, start1 + 1, end1 - 1, start2, end2);
        }
        return doFind(nums1, nums2, start1 + 1, end1, start2, end2 - 1);
    }

    double halfArrays(const vector<int>& nums, int start, int end) {
        int total = start + end;
        if (total & 1) {
            return (nums[total / 2] + nums[total / 2 + 1]) / 2.0;
        }
        return nums[total / 2];
    }
};