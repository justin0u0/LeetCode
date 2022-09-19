/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-duplicate-file-in-system/
 * Runtime: 86ms (99.62%)
 */

class Solution {
public:
  vector<vector<string>> findDuplicate(vector<string>& paths) {
    unordered_map<string, vector<string>> m;
    for (const string& path : paths) {
      size_t pos1 = path.find(' ');
      size_t pos2 = path.find('(', pos1);
      size_t pos3 = path.find(')', pos2);
      string dir = path.substr(0, pos1);
      while (pos3 != string::npos) {
        string file = path.substr(pos1 + 1, pos2 - pos1 - 1);
        string content = path.substr(pos2 + 1, pos3 - pos2 - 1);
        m[content].emplace_back(dir + '/' + file);
        pos1 = pos3 + 1;
        pos2 = path.find('(', pos3 + 1);
        pos3 = path.find(')', pos3 + 1);
      }
    }

    vector<vector<string>> answer;
    answer.reserve(m.size());
    for (const auto& it : m) {
      if (it.second.size() > 1) {
        answer.emplace_back(it.second);
      }
    }
    return answer;
  }
};
