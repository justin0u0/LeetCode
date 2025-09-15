/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/vowel-spellchecker/
 * Runtime: 2599ms (5.55%)
 */

class Solution {
private:
  inline bool isVowel(char c) {
    c |= 32;
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

  inline bool matchCaseInsensitive(const string& a, const string& b) {
    if (a.length() != b.length()) {
      return false;
    }
    for (int i = 0; i < a.length(); ++i) {
      if ((a[i] | 32) != (b[i] | 32)) {
        return false;
      }
    }
    return true;
  }

  inline bool matchVowelErrors(const string& a, const string& b) {
    if (a.length() != b.length()) {
      return false;
    }
    for (int i = 0; i < a.length(); ++i) {
      if ((!isVowel(a[i]) || !isVowel(b[i])) && (a[i] | 32) != (b[i] | 32)) {
        return false;
      }
    }
    return true;
  }
public:
  vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    vector<string> res;
    res.reserve(queries.size());
    for (auto& q : queries) {
      bool ok = false;
      for (const auto& w : wordlist) {
        if (q == w) {
          res.emplace_back(w);
          ok = true;
          break;
        }
      }
      if (ok) {
        continue;
      }
      for (const auto& w : wordlist) {
        if (matchCaseInsensitive(q, w)) {
          res.emplace_back(w);
          ok = true;
          break;
        }
      }
      if (ok) {
        continue;
      }
      for (const auto& w : wordlist) {
        if (matchVowelErrors(q, w)) {
          res.emplace_back(w);
          ok = true;
          break;
        }
      }
      if (!ok) {
        res.emplace_back("");
      }
    }
    return res;
  }
};
