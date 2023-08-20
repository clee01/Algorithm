// 极端case会有TLE
class Solution {
 public:
  int findKthLargest(std::vector<int>& nums, int k) {
    int left = 0, right = nums.size() - 1;
    while (true) {
      int pivot_index = rand() % (right - left + 1) + left;
      int new_pivot_index = partition(nums, left, right, pivot_index);
      if (new_pivot_index == nums.size() - k) {
        return nums[new_pivot_index];
      } else if (new_pivot_index > nums.size() - k) {
        right = new_pivot_index - 1;
      } else {
        left = new_pivot_index + 1;
      }
    }
  }

 private:
  int partition(std::vector<int>& nums, int left, int right, int pivot_index) {
    int pivot = nums[pivot_index];
    std::swap(nums[pivot_index], nums[right]);
    int stored_index = left;
    for (int i = left; i < right; i++) {
      if (nums[i] < pivot) {
        std::swap(nums[i], nums[stored_index]);
        stored_index++;
      }
    }
    std::swap(nums[right], nums[stored_index]);
    return stored_index;
  }
};