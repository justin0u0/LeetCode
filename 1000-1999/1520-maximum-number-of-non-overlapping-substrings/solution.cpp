/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/
 * Runtime: 48ms (33.51%)
 */

class Solution {
public:
  vector<string> maxNumOfSubstrings(const string& s) {
    vector<pair<int, int>> intervals(26, {-1, 0});
    for (int i = 0; i < s.length(); ++i) {
      auto& [l, r] = intervals[s[i] - 'a'];
      if (l < 0) {
        l = i;
      }
      r = i;
    }

    for (int i = 0; i < 26; ++i) {
      auto& [l, r] = intervals[i];
      if (l < 0) {
        continue;
      }

      for (int j = l; j <= r; ++j) {
        const auto [l2, r2] = intervals[s[j] - 'a'];
        if (s[j] == i + 'a') {
          continue;
        }
        if (l2 < l) {
          l = l2;
          j = l;
        }
        r = max(r, r2);
      }
    }

    ranges::sort(intervals, {}, [&](const auto& intv) {
      return intv.second;
    });

    int rightmost = -1;
    vector<string> ans;
    for (const auto& [l, r] : intervals) {
      if (l < 0) {
        continue;
      }
      if (l > rightmost) {
        rightmost = l;
        ans.emplace_back(s.substr(l, r - l + 1));
      }
    }
    return ans;
  }
};
