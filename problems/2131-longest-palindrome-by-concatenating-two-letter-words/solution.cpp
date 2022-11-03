/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/
 * Runtime: 359ms (94.62%)
 */

class Solution {
private:
  const int MAXN = (int)('z') + 1;
public:
  int longestPalindrome(vector<string>& words) {
    vector<vector<int>> box(MAXN, vector<int>(MAXN, 0));

    int answer = 0;
    for (const string& word : words) {
      int& count = box[word[1]][word[0]];
      if (count != 0) {
        --count;
        answer += 4;
      } else {
        ++box[word[0]][word[1]];
      }
    }

    for (int i = 0; i < MAXN; ++i) {
      if (box[i][i] != 0) {
        answer += 2;
        break;
      }
    }

    return answer;
  }
};
