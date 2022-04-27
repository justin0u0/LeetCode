/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/smallest-string-with-swaps/
 * Runtime: 177ms
 * Time Complexity: O(NlogN)
 */

class Solution {
private:
  class DJS {
  private:
    int n;
    int* pa;
  public:
    DJS(int n) : n(n) {
      pa = new int[n];
      for (int i = 0; i < n; ++i) {
        pa[i] = i;
      }
    }

    ~DJS() {
      delete[] pa;
    }

    int find(int x) {
      return (pa[x] == x) ? (x) : (pa[x] = find(pa[x]));
    }

    void merge(int x, int y) {
      x = find(x);
      y = find(y);

      if (x == y) {
        return;
      }

      pa[x] = y;
    }
  };
public:
  string smallestStringWithSwaps(string& s, vector<vector<int>>& pairs) {
    int n = (int)s.length();

    DJS djs(n);

    for (vector<int>& pair : pairs) {
      djs.merge(pair[0], pair[1]);
    }

    unordered_map<int, priority_queue<char, vector<char>, greater<char>>> pqs;
    for (int i = 0; i < n; ++i) {
      pqs[djs.find(i)].push(s[i]);
    }

    string answer;
    answer.reserve(n);
    for (int i = 0; i < n; ++i) {
      priority_queue<char, vector<char>, greater<char>>& pq = pqs[djs.find(i)];
      char c = pq.top();
      pq.pop();

      answer.append(&c, 1);
    }

    return answer;
  }
};
