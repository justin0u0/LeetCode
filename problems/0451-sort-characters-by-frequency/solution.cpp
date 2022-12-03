/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sort-characters-by-frequency/submissions/
 * Runtime: 8ms (97.51%)
 * Time Complexity: O(NlogN)
 */

class Solution {
public:
  string frequencySort(string& s) {
    int count[128] = {0};
    for (const char& c : s) {
      ++count[c];
    }

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < 128; ++i) {
      if (count[i] != 0) {
        pq.push({count[i], i});
      }
    }

    int idx = 0;
    while (!pq.empty()) {
      const auto& [count, c] = pq.top();
      for (int i = 0; i < count; ++i) {
        s[idx++] = c;
      }
      pq.pop();
    }
    return s;
  }
};
