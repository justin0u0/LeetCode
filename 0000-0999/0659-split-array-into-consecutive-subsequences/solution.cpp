/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/split-array-into-consecutive-subsequences/
 * Runtime: 178ms
 */

class Solution {
typedef priority_queue<int, vector<int>, greater<int>> pqint;

private:
  const int base = 1001;
public:
  bool isPossible(vector<int>& nums) {
    pqint* pqs = new pqint[2002];
    for (const int& num : nums) {
      int val = num + base;
      pqint& cur = pqs[val - 1];
      pqint& next = pqs[val];

      if (cur.empty()) {
        next.push(1);
      } else {
        int len = cur.top();
        cur.pop();

        next.push(len + 1);
      }
    }

    for (int i = 0; i < 2002; ++i) {
      if (!pqs[i].empty() && pqs[i].top() < 3) {
        return false;
      }
    }

    return true;
  }
};
