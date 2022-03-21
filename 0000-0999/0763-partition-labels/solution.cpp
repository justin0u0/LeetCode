/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/partition-labels/
 * Runtime: 0ms
 */

class Solution {
public:
  vector<int> partitionLabels(string& s) {
    vector<int> last(26);

    int n = (int)s.length();
    for (int i = 0; i < n; ++i) {
      last[s[i] - 'a'] = i;
    }

    vector<int> answer;
    int start = 0;
    int end = 0;
    for (int i = 0; i < n; ++i) {
      end = max(end, last[s[i] - 'a']);

      if (i >= end) {
        answer.emplace_back(i - start + 1);
        start = i + 1;
        end = i + 1;
      }
    }

    return answer;
  }
};
