/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 * Runtime: 0ms
 */

class Solution {
public:
  vector<string> letterCombinations(string& digits) {
    int mapping[][2] = {{'a', 3}, {'d', 3}, {'g', 3}, {'j', 3}, {'m', 3}, {'p', 4}, {'t', 3}, {'w', 4}};

    vector<string> answer;
    if (digits.empty()) {
      return answer;
    }
    
    queue<string> box;
    box.push("");

    for (const char& digit : digits) {
      char base = mapping[digit - '2'][0];
      int limit = mapping[digit - '2'][1];
      int sz = (int)box.size();
      for (int i = 0; i < sz; ++i) {
        string s = box.front();
        box.pop();

        for (char c = base; c < base + limit; ++c) {
          box.push(s + c);
        }
      }
    }

    while (!box.empty()) {
      answer.emplace_back(box.front());
      box.pop();
    }

    return answer;
  }
};
