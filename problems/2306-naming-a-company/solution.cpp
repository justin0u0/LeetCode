/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/naming-a-company/
 * Runtime: 1354ms (24.39%)
 */

class Solution {
public:
  long long distinctNames(vector<string>& ideas) {
    unordered_set<string> box;
    vector<vector<int>> count(128, vector<int>(128, 0));
    for (const string& s : ideas) {
      box.emplace(s);
      ++count[0][s[0]];
    }

    for (string& s : ideas) {
      char orig = s[0];
      for (char c = 'a'; c <= 'z'; ++c) {
        s[0] = c;
        if (box.find(s) != box.end()) {
          ++count[orig][c];
        }
      }
      s[0] = orig;
    }

    long long answer = 0;
    for (string& s : ideas) {
      char orig = s[0];
      for (char c = 'a'; c <= 'z'; ++c) {
        s[0] = c;
        if (box.find(s) == box.end()) {
          answer += count[0][c] - count[c][orig];
        }
      }
    }
    return answer;
  }
};
