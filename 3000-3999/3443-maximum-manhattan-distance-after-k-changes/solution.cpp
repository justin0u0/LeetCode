/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/
 * Runtime: 76ms (77.27%)
 */

class Solution {
public:
  int maxDistance(const string& s, const int k) {
    int cnt[128] = {0};
    int maxd = 0;
    for (int i = 0; i < s.length(); ++i) {
      ++cnt[s[i]];
      maxd = max(maxd, 
        max(cnt['N'], cnt['S']) - min(cnt['N'], cnt['S'])
        + max(cnt['E'], cnt['W']) - min(cnt['E'], cnt['W'])
        + min(k, min(cnt['N'], cnt['S']) + min(cnt['E'], cnt['W'])) * 2
      );
    }
    return maxd;
  }
};
