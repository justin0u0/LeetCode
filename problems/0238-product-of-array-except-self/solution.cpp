/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/product-of-array-except-self/
 * Runtime: 3ms (99.89%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  int pre[100001];
  int suf[100001];
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    const int n = nums.size();
    pre[0] = 1;
    suf[n] = 1;

    for (int i = 0; i < n; ++i) {
      pre[i + 1] = pre[i] * nums[i];
    }
    for (int i = n - 1; i >= 0; --i) {
      suf[i] = suf[i + 1] * nums[i];
    }
    for (int i = 0; i < nums.size(); ++i) {
      nums[i] = pre[i] * suf[i + 1];
    }
    return nums;
  }
};
