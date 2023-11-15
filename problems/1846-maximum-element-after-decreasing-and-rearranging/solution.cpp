/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/
 * Runtime: 51ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int x = 1;
    for (int num : arr) {
      if (num >= x) {
        ++x;
      }
    }
    return x - 1;
  }
};
