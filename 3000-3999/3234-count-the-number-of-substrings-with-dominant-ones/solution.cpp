/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones/
 * Runtime: 130ms (93.96%)
 */

class Solution {
public:
  int numberOfSubstrings(const string& s) {
    const int n = s.length();

    vector<int> box; // number of consecutive ones before each zero
    int cnt = 0; // current number of consecutive ones
    int total = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        ++cnt;
      } else {
        box.push_back(cnt);
        cnt = 0;
      }

      int o = cnt; // `o` is number of ones
      total += o; // 0 zeros

      // `z` is number of zeros
      for (int z = 1; z <= box.size() && z * z <= n; ++z) {
        const int o2 = box[box.size() - z];
        o += o2;
        if (o >= z * z) {
          total += min(o2 + 1, o - z * z + 1);
        }
      }
    }

    return total;
  }
};
