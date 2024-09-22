/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/repeated-dna-sequences/
 * Runtime: 16ms (98.17%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  vector<int> freq;
public:
  vector<string> findRepeatedDnaSequences(const string& s) {
    if (s.length() < 10) {
      return {};
    }

    // Each character uses 2 bits, so there are 10*2 = 20 bits in total.
    int h = 0;
    for (int i = 0; i < 10; ++i) {
      switch (s[i]) {
        case 'A':
          h = (h << 2);
          break;
        case 'C':
          h = (h << 2) | 1;
          break;
        case 'G':
          h = (h << 2) | 2;
          break;
        case 'T':
          h = (h << 2) | 3;
          break;
      }
    }

    freq.resize(1 << 20);
    fill(freq.begin(), freq.end(), 0);
    ++freq[h];
    vector<string> res;

    for (int i = 10; i < s.length(); ++i) {
      switch (s[i]) {
        case 'A':
          h = (h << 2);
          break;
        case 'C':
          h = (h << 2) | 1;
          break;
        case 'G':
          h = (h << 2) | 2;
          break;
        case 'T':
          h = (h << 2) | 3;
          break;
      }
      h &= 0xFFFFF;
      if (++freq[h] == 2) {
        res.emplace_back(s.substr(i - 10 + 1, 10));
      }
    }
    return res;
  }
};
