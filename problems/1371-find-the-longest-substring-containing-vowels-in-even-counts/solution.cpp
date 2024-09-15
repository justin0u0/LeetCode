/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
 * Runtime: 21ms (87.91%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int findTheLongestSubstring(const string& s) {
    vector<int> vis(1<<5, INT_MAX);
    vis[0] = -1;

    bitset<26> count;
    int answer = 0;
    for (int i = 0; i < s.length(); ++i) {
      count.flip(s[i] - 'a');

      unsigned x = count['a' - 'a']
        | count['e' - 'a'] << 1
        | count['i' - 'a'] << 2
        | count['o' - 'a'] << 3
        | count['u' - 'a'] << 4;
      if (vis[x] == INT_MAX) {
        vis[x] = i;
      } else {
        answer = max(answer, i - vis[x]);
      }
    }

    return answer;
  }
};
