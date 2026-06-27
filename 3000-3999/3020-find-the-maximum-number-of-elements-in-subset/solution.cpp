/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/
 * Runtime: 65ms (80.57%)
 */

class Solution {
public:
  int maximumLength(const vector<int>& nums) {
    unordered_map<int, int> cnt;
    for (int num : nums) {
      ++cnt[num];
    }

    int res = cnt[1];
    if (cnt[1] > 1 && !(cnt[1] & 1)) {
      res = cnt[1] - 1;
    }
    cnt.erase(1);
    
    for (const auto& [k, v] : cnt) {
      int seq = 0;
      for (long long i = k; i <= 1e9; i *= i) {
        if (!cnt.count(i)) {
          seq = 0;
        } else {
          if (cnt[i] > 0) {
            ++seq;
            res = max(res, seq);
          }
          if (cnt[i] >= 2) {
            ++seq;
          } else {
            seq = 0;
          }
        }
      }
    }

    return res;
  }
};
