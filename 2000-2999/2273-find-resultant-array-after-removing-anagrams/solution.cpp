/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  bool anagram(string a, string b) {
    if (a.length() != b.length()) {
      return false;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < a.length(); ++i) {
      if (a[i] != b[i]) {
        return false;
      }
    }
    return true;
  }
public:
  vector<string> removeAnagrams(vector<string>& words) {
    int j = 1;
    for (int i = 1; i < words.size(); ++i) {
      if (!anagram(words[i], words[i - 1])) {
        words[j++] = words[i];
      }
    }
    words.resize(j);
    return words;
  }
};
