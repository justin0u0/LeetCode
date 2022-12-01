/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/determine-if-string-halves-are-alike/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  vector<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
public:
  bool halvesAreAlike(string s) {
    int n = s.length();
    int count[128] = {0};

    for (int i = 0; i < n / 2; ++i) {
      ++count[s[i]];
    }
    for (int i = n / 2; i < n; ++i) {
      --count[s[i]];
    }

    int sum = 0;
    for (const char& c : vowels) {
      sum += count[c];
    }

    return (sum == 0);
  }
};
