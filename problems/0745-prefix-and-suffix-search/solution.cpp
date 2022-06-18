/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/prefix-and-suffix-search/
 * Runtime: 1088ms
 * Time Complexity:
 * 	- Initialize: O(N*M^2), where N is the maximum word length and M is the number of words.
 * 	- Each query: O(1)
 */

class WordFilter {
private:
  unordered_map<unsigned long long, int> hashes;

  static const unsigned P = 257;
  static const unsigned M = 1e9 + 7;
public:
  WordFilter(vector<string>& words) {
    int n = (int)words.size();
    for (int i = n - 1; i >= 0; --i) {
      string& s = words[i];
      int m = (int)s.size();

      vector<unsigned> pHashes{0};
      pHashes.reserve(m + 1);
      vector<unsigned> sHashes{0};
      sHashes.reserve(m + 1);

      for (int j = 0; j < m; ++j) {
        pHashes.emplace_back((1ULL * pHashes.back() * P + s[j]) % M);
      }

      for (int j = m - 1; j >= 0; --j) {
        sHashes.emplace_back((1ULL * sHashes.back() * P + s[j]) % M);
      }

      for (int j = 0; j < m; ++j) {
        for (int k = 0; k < m; ++k) {
          hashes.emplace(1ULL * pHashes[j + 1] * M + sHashes[k + 1], i);
        }
      }
    }
  }

  int f(string prefix, string suffix) {
    int n = (int)prefix.size();
    unsigned pHash = 0;
    for (int i = 0; i < n; ++i) {
      pHash = (1ULL * pHash * P + prefix[i]) % M;
    }

    int m = (int)suffix.size();
    unsigned sHash = 0;
    for (int i = m - 1; i >= 0; --i) {
      sHash = (1ULL * sHash * P + suffix[i]) % M;
    }

    unsigned long long hash = 1ULL * pHash * M + sHash;

    unordered_map<unsigned long long, int>::iterator it = hashes.find(hash);
    if (it == hashes.end()) {
      return -1;
    }

    return it->second;
  }
};

