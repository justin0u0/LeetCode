/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/reduce-array-size-to-the-half/
 * Runtime: 252ms
 * Time Complexity: O(NlogN)
 */

class Solution {
public:
  int minSetSize(vector<int>& arr) {
    unordered_map<int, int> m;
    for (const int& val : arr) {
      ++m[val];
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    int sum = 0;
    int target = arr.size() / 2;
    for (const auto& it : m) {
      sum += it.second;
      pq.push(it.second);
      while (!pq.empty() && sum - pq.top() >= target) {
        sum -= pq.top();
        pq.pop();
      }
    }

    return pq.size();
  }
};
