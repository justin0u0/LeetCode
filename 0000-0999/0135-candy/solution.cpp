/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/candy/
 * Runtime: 23ms
 * Time Complexity: O(N)
 */

class Solution {
public:
  int candy(vector<int>& ratings) {
    int n = (int)ratings.size();
    vector<int> box(n, 1);

    for (int i = 1; i < n; ++i) {
      if (ratings[i] > ratings[i - 1]) {
        box[i] = box[i - 1] + 1;
      }
    }
    for (int i = n - 2; i >= 0; --i) {
      if (ratings[i] > ratings[i + 1]) {
        box[i] = max(box[i], box[i + 1] + 1);
      }
    }

    return accumulate(box.begin(), box.end(), 0);
  }
};
