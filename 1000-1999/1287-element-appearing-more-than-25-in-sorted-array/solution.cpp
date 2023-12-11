/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/
 * Runtime: 3ms (98.94%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int findSpecialInteger(const vector<int>& arr) {
    int freq = 0;
    int target = -1;
    int maxFreq = 1;
    int answer = arr[0];
    for (int num : arr) {
      if (num != target) {
        target = num;
        freq = 1;
      } else if (++freq > maxFreq) {
        maxFreq = freq;
        answer = num;
      }
    }
    return answer;
  }
};
