/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-index-of-a-valid-split/
 * Runtime: 3ms (80.74%)
 */

class Solution {
public:
  int minimumIndex(const vector<int>& nums) {
    int dom = -1;
    int count = 1;
    for (int num : nums) {
      if (num == dom) {
        ++count;
      } else {
        --count;
      }
      if (count == 0) {
        dom = num;
        count = 1;
      }
    }

    int r = 0;
    for (int num : nums) {
      if (num == dom) {
        ++r;
      }
    }

    int l = 0;
    const int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
      if (nums[i] == dom) {
        ++l;
        --r;
      }

      if ((l << 1) > i + 1 && (r << 1) > (n - i - 1)) {
        return i;
      }
    }
    return -1;
  }
};
