/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/pascals-triangle-ii/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  vector<int> pre;
  vector<int> cur;
public:
  vector<int> getRow(int rowIndex) {
    pre.resize(rowIndex + 1);
    cur.resize(rowIndex + 1);
    
    pre[0] = 1;
    for (int i = 0; i < rowIndex; ++i) {
      cur[0] = 1;
      cur[i + 1] = 1;
      for (int j = 1; j <= i; ++j) {
        cur[j] = pre[j - 1] + pre[j];
      }
      swap(cur, pre);
    }
    return pre;
  }
};
