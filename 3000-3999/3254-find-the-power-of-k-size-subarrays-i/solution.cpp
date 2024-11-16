/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> resultsArray(const vector<int>& nums, int k) {
    const int n = nums.size();
    vector<int> res(n - k + 1);

    int count = 0;
    int pre = -1;
    for (int i = 0; i < n; ++i) {
      if (nums[i] == pre + 1) {
        ++count;
      } else {
        count = 1;
      }
      pre = nums[i];

      if (i >= k - 1) {
        if (count >= k) {
          res[i - k + 1] = pre;
        } else {
          res[i - k + 1] = -1;
        }
      }
    }

    return res;
  }
};
