/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/container-with-most-water/
 * Runtime: 111ms
 */

class Solution {
public:
  int maxArea(vector<int>& height) {
    int h = 1;
    int l = 0;
    int r = (int)height.size() - 1;
    int answer = 0;
    for (int h = 0; l < r; ++h) {
      while (l < r && height[l] < h) {
        ++l;
      }
      while (l < r && height[r] < h) {
        --r;
      }

      answer = max(answer, h * (r - l));
    }

    return answer;
  }
};
