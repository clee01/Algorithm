// My answer
class Solution {
 public:
  int maxArea(vector<int>& height) {
    vector<int> left_to_right(height.size(), 0);
    vector<int> right_to_left(height.size(), 0);
    int tmp = height[0];
    left_to_right[0] = tmp;
    for (int i = 1; i < height.size(); ++i) {
      if (height[i] > tmp) {
        tmp = height[i];
        left_to_right[i] = tmp;
      }
    }

    tmp = height[height.size() - 1];
    right_to_left[height.size() - 1] = tmp;
    for (int i = height.size() - 2; i >= 0; --i) {
      if (height[i] > tmp) {
        tmp = height[i];
        right_to_left[i] = tmp;
      }
    }

    int res = 0;
    for (int i = height.size() - 1; i >= 0; --i) {
      if (right_to_left[i] == 0) {
        break;
      }
      for (int j = 0; j < i; ++j) {
        if (left_to_right[j] == 0) {
          break;
        }
        int curr = std::min(right_to_left[i], left_to_right[j]) * (i - j);
        res = res < curr ? curr : res;
      }
    }
    return res;
  }
};

// Better answer
class Solution {
 public:
  int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int maxArea = 0;

    while (left < right) {
      int currentArea = min(height[left], height[right]) * (right - left);
      maxArea = max(maxArea, currentArea);

      if (height[left] < height[right]) {
        left++;
      } else {
        right--;
      }
    }

    return maxArea;
  }
};