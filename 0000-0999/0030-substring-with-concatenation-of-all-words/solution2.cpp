/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
 * Runtime: 24ms
 */

class RollingHash {
private:
  static const unsigned M = 1e8 + 7;
  static const unsigned P = 31;

  vector<unsigned> hashes;
  static vector<unsigned> base;
public:
  RollingHash(const string& s) {
    hashes = vector<unsigned>(s.size() + 1, 0);
    for (size_t i = 1; i <= s.length(); ++i) {
      hashes[i] = (hashes[i - 1] * P + (s[i - 1] - 'a')) % M;
    }
    while (base.size() < hashes.size()) {
      base.emplace_back(base.back() * P % M);
    }
  }

  unsigned getHash() {
    return hashes.back();
  }

  unsigned getHash(int l, int r) {
    return (hashes[r] + M - (1ULL * hashes[l] * base[r - l]) % M) % M;
  }

  static unsigned getHash(const string& s) {
    unsigned h = 0;
    for (const char& c : s) {
      h = (h * P + (c - 'a')) % M;
    }
    return h;
  }
};

vector<unsigned> RollingHash::base = vector<unsigned>(1, 1);

class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    RollingHash srh(s);

    unordered_multiset<unsigned> box;
    for (const string& word : words) {
      box.emplace(RollingHash::getHash(word));
    }

    int n = words.size();
    int m = words[0].size();
    vector<int> answer;
    queue<unsigned> q;
    for (int i = 0; i < m; ++i) {
      for (int j = i; j + m <= s.size(); j += m) {
        unsigned h = srh.getHash(j, j + m);
        unordered_multiset<unsigned>::iterator it = box.find(h);
        while (it == box.end() && !q.empty()) {
          box.emplace(q.front());
          q.pop();
          it = box.find(h);
        }

        if (it != box.end()) {
          box.erase(it);
          q.push(h);
        }

        if (box.empty()) {
          answer.emplace_back(j - (n * m - m));
        }
      }
      while (!q.empty()) {
        box.emplace(q.front());
        q.pop();
      }
    }
    return answer;
  }
};
