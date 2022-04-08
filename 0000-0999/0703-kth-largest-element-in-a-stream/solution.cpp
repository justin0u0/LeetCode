/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/kth-largest-element-in-a-stream/
 * Runtime: 24ms
 */

class KthLargest {
private:
  int k;
  priority_queue<int, vector<int>, greater<int>> pq;
public:
  KthLargest(int k, vector<int>& nums) : k(k) {
    for (const int& val : nums) {
      add(val);
    }
  }

  int add(int val) {
    if (pq.size() < k) {
      pq.push(val);
    } else if (val > pq.top()) {
      pq.pop();
      pq.push(val);
    }

    return pq.top();
  }
};
