class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int curr_index = 0;
    while (curr_index < nums.size() - 1) {
      if (nums[curr_index] == 0) {
        return false;
      }
      int max_step = 0, step = 0;
      for (int i = 1; i <= nums[curr_index]; ++i) {
        if (nums[curr_index + i] + i >= nums.size() - 1) {
          return true;
        }
        if (max_step <= nums[curr_index + i] + i) {
          max_step = nums[curr_index + i] + i;
          step = i;
        }
      }
      curr_index += step;
    }
    return true;
  }
};