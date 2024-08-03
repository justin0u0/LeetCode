/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/
 * Runtime: 7ms (84.20%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  int cnt[1001];
public:
  bool canBeEqual(vector<int>& target, vector<int>& arr) {
    memset(cnt, 0, sizeof(cnt));
    for (int x : target) {
      ++cnt[x];
    }
    for (int x : arr) {
      --cnt[x];
    }
    for (int i = 0; i <= 1000; ++i) {
      if (cnt[i] != 0) {
        return false;
      }
    }
    return true;
  }
};
