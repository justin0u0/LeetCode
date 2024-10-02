/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/rank-transform-of-an-array/
 * Runtime: 37ms (97.45%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> sorted(arr.begin(), arr.end());
    sort(sorted.begin(), sorted.end());
    sorted.resize(unique(sorted.begin(), sorted.end()) - sorted.begin());
    for (int& num : arr) {
      num = lower_bound(sorted.begin(), sorted.end(), num) - sorted.begin() + 1;
    }
    return arr;
  }
};
