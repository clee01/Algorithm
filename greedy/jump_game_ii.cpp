class Solution {
 public:
  int jump(vector<int>& nums) {
    int res = 0;
    int curr_index = 0;
    while (curr_index < nums.size() - 1) {
      int max_step = 0;
      int step = 0;
      for (int i = 1; i <= nums[curr_index]; ++i) {
        if (curr_index + i >= nums.size() - 1) {
          return res + 1;
        }
        if (max_step < nums[curr_index + i] + i) {
          max_step = nums[curr_index + i] + i;
          step = i;
        }
      }
      curr_index += step;
      res++;
    }
    return res;
  }
};