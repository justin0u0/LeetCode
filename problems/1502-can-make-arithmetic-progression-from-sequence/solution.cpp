/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  bool canMakeArithmeticProgression(vector<int>& arr) {
    int n = arr.size();
    if (n <= 2) {
      return true;
    }

    sort(arr.begin(), arr.end());
    int d = arr[1] - arr[0];
    for (int i = 1; i < n - 1; ++i) {
      if (arr[i + 1] - arr[i] != d) {
        return false;
      }
    }
    return true;
  }
};
