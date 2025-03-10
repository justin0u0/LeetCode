/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/
 * Runtime: 175ms (68.49%)
 */

class Solution {
private:
  inline bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

  long long atLeastK(const string& word, const int k) {
    const int n = word.length();

    unordered_map<char, int> vowels;
    int consonants = 0;
    long long sum = 0;

    int j = 0;
    for (int i = 0; i < n; ++i) {
      if (isVowel(word[i])) {
        ++vowels[word[i]];
      } else {
        ++consonants;
      }

      while (vowels.size() == 5 && consonants >= k) {
        sum += n - i;

        if (isVowel(word[j])) {
          if (--vowels[word[j]] == 0) {
            vowels.erase(word[j]);
          }
        } else {
          --consonants;
        }
        ++j;
      }
    }

    return sum;
  }
public:
  long long countOfSubstrings(const string& word, const int k) {
    // exactly k = (at least k) - (at least k + 1)
    return atLeastK(word, k) - atLeastK(word, k + 1);
  }
};
