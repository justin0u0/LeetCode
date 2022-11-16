/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/guess-number-higher-or-lower/
 * Runtime: 0ms (100.00%)
 */

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
  int guessNumber(int n) {
    int l = 1;
    int r = n;
    while (true) {
      int mid = l + (r - l) / 2;
      int g = guess(mid);

      if (g == 0) {
        return mid;
      }

      if (g == 1) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    return -1;
  }
};
