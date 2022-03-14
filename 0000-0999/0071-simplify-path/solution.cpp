/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/simplify-path/
 * Runtime: 3ms
 */

class Solution {
public:
  string simplifyPath(string path) {
    vector<string> box;

    int n = (int)path.length();
    int i = 0;
    while (i < n) {
      while (i < n && path[i] == '/') {
        ++i;
      }

      if (i >= n) {
        break;
      }

      int j = i;
      bool allDots = true;
      while (i < n && path[i] != '/') {
        if (path[i] != '.') {
          allDots = false;
        }
        ++i;
      }

      if (allDots && i - j == 2) {
        if (!box.empty()) {
          box.pop_back();
        }
      } else if (!allDots || i - j != 1) {
        box.emplace_back(path.substr(j - 1, i - j + 1));
      }
    }

    if (box.empty()) {
      return "/";
    }

    string answer;
    for (string& s : box) {
      answer += s;
    }

    return answer;
  }
};
