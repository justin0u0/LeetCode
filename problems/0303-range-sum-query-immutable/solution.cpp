/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/range-sum-query-immutable/
 * Runtime: 12ms (96.01%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class NumArray {
private:
  int sum[10001];
public:
  NumArray(vector<int>& nums) {
    sum[0] = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum[i + 1] = sum[i] + nums[i];
    }
  }
  
  int sumRange(int left, int right) {
    return sum[right + 1] - sum[left];
  }
};
