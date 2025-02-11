/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  const unsigned B = 31;
  const unsigned M = 1e8 + 7;
public:
  string removeOccurrences(const string& s, const string& part) {
    const int len = part.length();

    vector<unsigned> base{1};

    unsigned phash = 0;
    for (char c : part) {
      phash = (phash * B + c - 'a') % M;
      base.emplace_back(base.back() * B % M);
    }

    vector<char> stk{0};
    vector<unsigned> hash{0};

    for (char c : s) {
      stk.emplace_back(c);
      c -= 'a';

      hash.emplace_back((hash.back() * B + c) % M);
      const int hlen = hash.size();
      if (hlen > len) {
        const unsigned h = (hash[hlen - 1] + M - (1ULL * hash[hlen - len - 1] * base[len]) % M) % M;
        if (h == phash) {
          hash.resize(hlen - len);
          stk.resize(hlen - len);
        }
      }
    }

    return string(stk.begin() + 1, stk.end());
  }
};
