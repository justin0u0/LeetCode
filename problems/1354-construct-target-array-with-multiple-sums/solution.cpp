/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/construct-target-array-with-multiple-sums/
 * Runtime: 46ms
 */

class Solution {
public:
  bool isPossible(vector<int>& target) {
    if (target.size() == 1) {
      return target[0] == 1;
    }
    
    priority_queue<int> pq;
    long long sum = 0;
    for (const int val : target) {
      pq.push(val);
      sum += val;
    }

    for (int v = pq.top(); v != 1; v = pq.top()) {
      long long d = sum - v;
      pq.pop();
      long long sub = (((v - pq.top() - 1) / d) + 1) * d;

      if (v - sub < 1) {
        return false;
      }
      sum -= sub;
      pq.push(v - sub);
    }

    return true;
  }
};
