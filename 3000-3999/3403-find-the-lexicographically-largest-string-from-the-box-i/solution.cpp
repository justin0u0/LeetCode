/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  string answerString(const string& word, const int numFriends) {
    if (numFriends == 1) {
      return word;
    }

    const int n = word.size();

    int largest = 0; // largest substring
    int cand = -1; // candidate of the largest substring
    for (int i = 1; i < n; ++i) {
      if (word[i] > word[largest]) {
        largest = i;
        cand = -1;
      } else if (cand == -1 && word[i] == word[largest]) {
        cand = i;
      }

      if (cand != -1) {
        const int j = largest + i - cand;
        if (j >= n || word[i] < word[j]) {
          cand = -1;
        } else if (word[i] > word[j]) {
          largest = cand;
          cand = -1;
        }
      }
    }

    return word.substr(largest, n - numFriends + 1);
  }
};
