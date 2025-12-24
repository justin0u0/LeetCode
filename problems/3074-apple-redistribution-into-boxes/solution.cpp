/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/apple-redistribution-into-boxes/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minimumBoxes(const vector<int>& apple, vector<int>& capacity) {
    int total = accumulate(apple.begin(), apple.end(), 0);
    sort(capacity.begin(), capacity.end(), greater<int>());
    int i;
    for (i = 0; i < capacity.size(); ++i) {
      total -= capacity[i];
      if (total <= 0) {
        break;
      }
    }
    return i + 1;
  }
};
