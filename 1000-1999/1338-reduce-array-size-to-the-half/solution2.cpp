/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/reduce-array-size-to-the-half/
 * Runtime: 219ms
 * Time Complexity: O(N)
 */

class Solution {
public:
  int minSetSize(vector<int>& arr) {
    unordered_map<int, int> m;
    for (const int& val : arr) {
      ++m[val];
    }

    unordered_map<int, int> freq;
    int maxFreq = 0;
    for (const auto& it : m) {
      ++freq[it.second];
      maxFreq = max(maxFreq, it.second);
    }

    int target = arr.size() / 2;
    int answer = 0;
    for (int i = maxFreq; target > 0; --i) {
      int f = freq[i];
      for (int j = 0; j < f && target > 0; ++j) {
        target -= i;
        ++answer;
      }
    }

    return answer;
  }
};
