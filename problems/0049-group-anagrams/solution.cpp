/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/group-anagrams/
 * Runtime: 42ms (88.96%)
 */

class Solution {
private:
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> box;
    for (const string& s : strs) {
      string ss = s;
      sort(ss.begin(), ss.end());
      box[ss].emplace_back(s);
    }

    vector<vector<string>> answer;
    answer.reserve(box.size());
    for (const auto& it : box) {
      answer.emplace_back(it.second);
    }
    return answer;
  }
};
