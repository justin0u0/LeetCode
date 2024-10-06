/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sentence-similarity-iii/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  bool areSentencesSimilar(const string& sentence1, const string& sentence2) {
    vector<string> w1;
    vector<string> w2;

    string s;
    stringstream ss1(sentence1);
    while (ss1 >> s) {
      w1.emplace_back(s);
    }
    stringstream ss2(sentence2);
    while (ss2 >> s) {
      w2.emplace_back(s);
    }

    if (w1.size() < w2.size()) {
      swap(w1, w2);
    }

    int i = 0;
    while (i < w2.size() && w1[i] == w2[i]) {
      ++i;
    }

    int j = w2.size() - 1;
    int k = w1.size() - 1;
    while (j >= i && w1[k] == w2[j]) {
      --k;
      --j;
    }
    return j < i;
  }
};
