/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-ii/
 * Runtime: 39ms (93.59%)
 */

class Solution {
private:
  #define INF 30001
public:
  int maxDifference(const string& s, const int k) {
    // Consider all possible `a` and `b` indepently.

    // Consider finding maximum difference with prefix sum:
    // max(freq[a] - freq[b]) of s(j:i] equals to
    // max(freq[a] - freq[b]) of s[0:i] - min(freq[a] - freq[b]) of s[0:j].

    // Consider the correct odd/even:
    // The substring should have odd number of `a` and even number of `b`.
    // {e, e} - {o, e} = {o, e}
    // {e, o} - {o, o} = {o, e}
    // {o, e} - {e, e} = {o, e}
    // {o, o} - {e, o} = {o, e}

    // const int mappings[] = {2, 3, 0, 1};

    int maxd = INT_MIN;
    for (int a = '0'; a < '5'; ++a) {
      for (int b = '0'; b < '5'; ++b) {
        if (a == b) {
          continue;
        }

        // Keep minimum prefix sum
        int mn[4] = {INF, INF, INF, INF};

        // sum s[0:i]
        int sumia = 0;
        int sumib = 0;
        // sum s[0:j]
        int sumja = 0;
        int sumjb = 0;

        int j = -1;

        // To prevent `b` being from zero, we can only pop prefix if there are
        // at least 2 `b`s.
        int lastb = INT_MIN;
        int lastlastb = INT_MIN;
        for (int i = 0; i < s.length(); ++i) {
          if (s[i] == a) {
            ++sumia;
          } else if (s[i] == b) {
            ++sumib;
            lastlastb = lastb;
            lastb = i;
          }

          while (j <= min(i - k, lastlastb)) {
            const int x = ((sumja & 1) << 1) | (sumjb & 1);
            mn[x] = min(mn[x], sumja - sumjb);
            ++j;
            sumja += (s[j] == a);
            sumjb += (s[j] == b);
          }

          const int x = ((sumia & 1) << 1) | (sumib & 1);
          // (x + 2) & 3 equals to mappings[x]
          maxd = max(maxd, (sumia - sumib) - mn[(x + 2) & 3]);
        }
      }
    }

    return maxd;
  }
};
