/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/unique-morse-code-words/
 * Runtime: 0ms
 */

class Solution {
public:
  int uniqueMorseRepresentations(vector<string>& words) {
    string codes[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

    unordered_set<string> transformations;
    for (const string& word : words) {
      string s;
      for (const char& c : word) {
        s.append(codes[c - 'a']);
      }
      transformations.emplace(s);
    }

    return transformations.size();
  }
};
