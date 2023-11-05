/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-winner-of-an-array-game/
 * Runtime: 51ms (99.07%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int getWinner(vector<int>& arr, int k) {
    int w = -1;
    int prev = arr[0];
    for (int num : arr) {
      if (num > prev) {
        w = 1;
        prev = num;
      } else {
        ++w;
      }
      if (w >= k) {
        return prev;
      }
    }
    return *max_element(arr.begin(), arr.end());
  }
};
