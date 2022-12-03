/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sort-characters-by-frequency/submissions/
 * Runtime: 6ms (99.32%)
 * Time Complexity: O(N)
 */

class Solution {
public:
  string frequencySort(const string& s) {
    int count[128] = {0};
    for (const char& c : s) {
      ++count[c];
    }

    int maxFreq = *max_element(count, count + 128);
    vector<string> freq(maxFreq + 1);
    for (int i = 0; i < 128; ++i) {
      if (count[i] != 0) {
        freq[count[i]].append(1, char(i));
      }
    }

    string answer;
    answer.reserve(s.size());
    for (int i = maxFreq; i >= 0; --i) {
      for (const char& c : freq[i]) {
        answer.append(i, c);
      }
    }

    return answer;
  }
};
