/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/
 * Runtime: 4ms (99.70%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maximumBeauty(const vector<int>& nums, const int k) {
    vector<int> sweepline(*max_element(nums.begin(), nums.end()) + (k << 1) + 2);

    for (int num : nums) {
      ++sweepline[num];
      --sweepline[num + (k << 1) + 1];
    }

    int sum = 0;
    int mx = 0;
    for (int v : sweepline) {
      sum += v;
      mx = max(mx, sum);
    }
    return mx;
  }
};
