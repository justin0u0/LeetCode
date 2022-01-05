/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/palindrome-partitioning/
 * Runtime: 72ms
 */

class Solution {
private:
  void dfs(string& s, unsigned int i, vector<vector<string>>& answer, vector<string>& box, vector<vector<bool>>& isPalindrome) {
    if (i == s.length()) {
      answer.emplace_back(box);
      return;
    }

    for (unsigned int j = i; j < s.length(); ++j) {
      if (isPalindrome[i][j]) {
        box.emplace_back(s.substr(i, j - i + 1));
        dfs(s, j + 1, answer, box, isPalindrome);
        box.pop_back();
      }
    }
  }
public:
  vector<vector<string>> partition(string s) {
    unsigned int n = s.length();

    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
   
    isPalindrome[n - 1][n - 1] = true;
    for (int i = n - 2; i >= 0; --i) {
      isPalindrome[i][i] = true;
      isPalindrome[i + 1][i] = true;

      for (int j = i + 1; j < n; ++j) {
        isPalindrome[i][j] = (isPalindrome[i][j] || (isPalindrome[i + 1][j - 1] && (s[i] == s[j])));
      }
    }

    vector<vector<string>> answer;
    vector<string> box;
    dfs(s, 0, answer, box, isPalindrome);
    return answer;
  }
};

