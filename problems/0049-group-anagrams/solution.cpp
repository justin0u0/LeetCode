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

/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/group-anagrams/description/
 * Runtime: 16ms (98.78%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, int> anagrams;
    int id = 0;

    vector<vector<string>> answer;
    for (const string& s : strs) {
      string copy = s;
      sort(copy.begin(), copy.end());
      auto it = anagrams.find(copy);
      if (it == anagrams.end()) {
        anagrams.emplace(copy, id);
        answer.emplace_back(vector<string>{s});
        ++id;
      } else {
        answer[it->second].emplace_back(s);
      }
    }
    return answer;
  }
};
