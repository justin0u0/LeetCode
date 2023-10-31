/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-original-array-of-prefix-xor/
 * Runtime: 61ms (99.65%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> findArray(vector<int>& pref) {
    int prev = pref[0];
    for (int i = 1; i < pref.size(); ++i) {
      int x = prev ^ pref[i];
      prev = pref[i];
      pref[i] = x;
    }
    return pref;
  }
};
