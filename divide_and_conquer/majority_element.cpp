class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major_num = INT_MAX;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
          if (!count) {
            major_num = nums[i];
            count++;
          } else if (major_num != nums[i]) {
            count--;
          } else {
            count++;
          }
        }
        return major_num;
    }
};