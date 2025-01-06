/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<int> minOperations(const string& boxes) {
    const int n = boxes.size();
    vector<int> ops(n, 0);

    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; ++i) {
      sum += count;
      ops[i] += sum;
      count += boxes[i] - '0';
    }

    sum = 0;
    count = 0;
    for (int i = n - 1; i >= 0; --i) {
      sum += count;
      ops[i] += sum;
      count += boxes[i] - '0';
    }

    return ops;
  }
};
