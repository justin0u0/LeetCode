/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-nice-pairs-in-an-array/
 * Runtime: 64ms (99.86%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  const int mod = 1e9 + 7;

  inline int rev(int x) {
    int res = 0;
    while (x != 0) {
      res = res * 10 + x % 10;
      x /= 10;
    }
    return res;
  }
public:
  int countNicePairs(const vector<int>& nums) {
    unordered_map<int, int> m;
    int answer = 0;
    for (int num : nums) {
      int x = num - rev(num);
      answer += m[x];
      if (answer >= mod) {
        answer -= mod;
      }
      ++m[x];
    }
    return answer;
  }
};
