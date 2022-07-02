/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
 * Runtime: 83ms
 */

class Solution {
public:
  int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());

    horizontalCuts.emplace_back(h);
    verticalCuts.emplace_back(w);

    int maxH = horizontalCuts[0];
    for (int i = 1; i < horizontalCuts.size(); ++i) {
      maxH = max(maxH, horizontalCuts[i] - horizontalCuts[i - 1]);
    }
    int maxW = verticalCuts[0];
    for (int i = 1; i < verticalCuts.size(); ++i) {
      maxW = max(maxW, verticalCuts[i] - verticalCuts[i - 1]);
    }

    const int mod = 1e9 + 7;
    return (1LL * maxH * maxW) % mod;
  }
};
