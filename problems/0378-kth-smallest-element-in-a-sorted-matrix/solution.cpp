/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
 * Runtime: 51ms
 * Time Complexity: O(N^2 * log(N^2))
 * Space Complexity: O(k)
 */

class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<int> pq;
    for (const vector<int>& row : matrix) {
      for (const int& val : row) {
        pq.push(val);
        if (pq.size() > k) {
          pq.pop();
        }
      }
    }
    return pq.top();
  }
};
