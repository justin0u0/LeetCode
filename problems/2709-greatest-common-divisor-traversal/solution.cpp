/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/greatest-common-divisor-traversal/
 * Runtime: 435ms (69.46%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  const static int MAXN = 1e5;
  const static vector<int> primes;

  int pa[MAXN + 1];
  // id maps the prime number to the first number index with the prime factor
  int id[MAXN + 1];

  int find(int x) {
    if (x == pa[x]) {
      return x;
    }
    return (pa[x] = find(pa[x]));
  }

  const vector<int> factorize(int num) {
    vector<int> pfs;
    for (int p : primes) {
      if (num % p == 0) {
        pfs.emplace_back(p);
      }
      while (num % p == 0) {
        num /= p;
      }
    }
    if (num != 1) {
      pfs.emplace_back(num);
    }
    return pfs;
  }
public:
  bool canTraverseAllPairs(vector<int>& nums) {
    const int n = nums.size();
    for (int i = 0; i < n; ++i) {
      pa[i] = i;
    }
    memset(id, -1, sizeof(id));

    int left = n;
    for (int i = 0; i < n; ++i) {
      for (int p : factorize(nums[i])) {
        if (id[p] == -1) {
          id[p] = i;
        } else {
          int f1 = find(i);
          int f2 = find(id[p]);
          if (f1 != f2) {
            if (f1 > f2) {
              swap(f1, f2);
            }
            pa[f2] = pa[f1];
            --left;
          }
        }
      }
    }

    return left == 1;
  }
};

const vector<int> Solution::primes = []() {
  const int n = sqrt(MAXN);
  vector<bool> p(n, true);
  p[0] = p[1] = false;
  vector<int> primes;
  for (int i = 2; i < n; ++i) {
    if (p[i]) {
      primes.emplace_back(i);
    }
    for (int j = 0; j < primes.size(); ++j) {
      if (i * primes[j] >= n) {
        break;
      }
      p[i * primes[j]] = false;
    }
  }
  return primes;
}();

// Each number is an individual group at first. It can be merged with any other
// number with the same prime factor. But since there are multiple options, we
// choose the first number that has the prime factor to merge.
//
// That is, suppose we have 15, 18, 9, 12. They all have the prime factor 3,
// but we can choose the first number that has the prime factor 3, which is 15,
// and 18, 9, 12 can all be grouped with 15.

