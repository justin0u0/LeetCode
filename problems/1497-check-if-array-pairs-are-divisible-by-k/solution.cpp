/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/
 * Runtime: 36ms (99.34%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  int cnt[100001];
public:
  bool canArrange(vector<int>& arr, int k) {
    memset(cnt, 0, k * sizeof(int));
    for (int num : arr) {
      ++cnt[(num % k + k) % k];
    }
    for (int i = 1; i <= k / 2; ++i) {
      if (cnt[i] != cnt[k - i]) {
        return false;
      }
    }
    return !(cnt[0] & 1);
  }
};
