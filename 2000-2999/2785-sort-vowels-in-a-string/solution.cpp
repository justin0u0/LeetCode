/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sort-vowels-in-a-string/
 * Runtime: 17ms (99.69%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  constexpr static array<char, 10> vowels = {
    'A', 'E', 'I', 'O', 'U',
    'a', 'e', 'i', 'o', 'u'
  };

  const static bitset<128> isVowel;
public:
  string sortVowels(string& s) {
    int cnt[128] = {0};
    for (char c : s) {
      if (isVowel[c]) {
        ++cnt[c];
      }
    }

    auto it = vowels.begin();
    for (char& c : s) {
      if (isVowel[c]) {
        while (cnt[*it] == 0) {
          ++it;
        }
        c = *it;
        --cnt[*it];
      }
    }

    return s;
  }
};

const bitset<128> Solution::isVowel = []() {
  bitset<128> b;
  for (char v : Solution::vowels) {
    b.set(v);
  }
  return b;
}();
