/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/
 * Runtime: 27ms (96.10%)
 */

class Solution {
public:
  string clearStars(string& s) {
    vector<vector<int>> box(26);
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '*') {
        for (int j = 0; j < 26; ++j) {
          if (!box[j].empty()) {
            s[box[j].back()] = '*';
            box[j].pop_back();
            break;
          }
        }
      } else {
        box[s[i] - 'a'].emplace_back(i);
      }
    }
    
    int j = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] != '*') {
        s[j++] = s[i];
      }
    }
    return s.substr(0, j);
  }
};
