/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/concatenated-words/
 * Runtime: 174ms (95.16%)
 */

class Solution {
private:
  class Solver {
  private:
    unordered_set<string> words;
    unordered_map<string, bool> dp;
  public:
    Solver(const vector<string>& words) {
      for (const string& word : words) {
        this->words.emplace(word);
      }
    }

    bool solve(const string& s, int depth = 0) {
      if (s.size() == 0) {
        return depth > 1;
      }

      if (depth > 1) {
        auto it = dp.find(s);
        if (it != dp.end()) {
          return it->second;
        }
      }

      string temp;
      temp.reserve(s.size());
      for (int i = 0; i < s.size(); ++i) {
        temp += s[i];
        if (words.find(temp) == words.end()) {
          continue;
        }

        string next = s.substr(i + 1);
        if (solve(next, depth + 1)) {
          dp.emplace(s, true);
          return true;
        }
      }

      if (depth > 1) {
        dp.emplace(s, false);
      }
      return false;
    }
  };
public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    Solver s(words);
    vector<string> answer;
    for (const string& word : words) {
      if (s.solve(word)) {
        answer.emplace_back(word);
      }
    }
    return answer;
  }
};

