/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/can-place-flowers/
 * Runtime: 12ms
 */

class Solution {
public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int m = (int)flowerbed.size();
    flowerbed.emplace_back(0);

    int count = 0;
    for (int i = 0; i < m; ++i) {
      if (!flowerbed[i] && !flowerbed[i + 1] && (!i || !flowerbed[i - 1])) {
        ++count;
        flowerbed[i] = 1;
      }
    }

    return count >= n;
  }
};
