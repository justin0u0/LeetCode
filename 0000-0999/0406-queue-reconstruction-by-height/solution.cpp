/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/queue-reconstruction-by-height/
 * Runtime: 25ms
 * Time Complexity: O(N * logN * logN)
 * Description:
 * 	Naive:
 * 		- Sort by descending order, then the insert index can be easily calculated.
 *		- However, to random access + insert at random possition, O(N^2) is needed.
 *
 * 	Improved:
 * 		- Sort by ascending order, maintain the number of emtpy indices, then the insert position can
 * 			be calculated by the number of empty indices.
 *
 * 	Simulation:
 * 		- Sorted input: [[4,4], [5,2], [5,0], [6,1], [7,1], [7,0]]
 *		- Steps (1 represents the empty index, 1 represents the occupied index):
 *			1. arr = [1, 1, 1, 1, 1, 1], insert [4,4] so there are exactly 4 empty indices before the
 *				insert position.
 *			2. arr = [1, 1, 1, 1, X, 1], insert [5,2] so there are exactly 2 emtpy indices before the
 *				insert postion.
 *			3. arr = [1, 1, X, 1, X, 1], insert [5,0] so there are exactly 0 empty indices before the
 *				insert position.
 *			4. arr = [X, 1, X, 1, X, 1], insert [6,1] so there are exactly 1 empty indices before the
 *				insert position.
 *			5. arr = [X, 1, X, X, X, 1], insert [7,1] so there are exactly 1 empty indices before the
 *				insert position.
 *			6. arr = [X, 1, X, X, X, X], insert [7,0] so there are exactly 0 empty indices before the
 *				insert position.
 *
 *	Implementation:
 *		- Use binary search to find the index.
 *		- We need to maintain a data structure that can tell how many empty indices before the target
 *			index. Also the data structure need to remove a empty index.
 *		- A binary index tree (BIT) can solve the problem. The BIT can support O(logN) operations for
 *			both "single index value update" and "range sum query".
 *		- Initially, each index stores 1 because it represents an empty index. The "range sum query"
 *			operation tells the number of empty indices before the target index (prefix sum those 1s).
 *			After each step, update an index to 0 since the index is occupied.
 */

class Solution {
private:
  class BIT {
  private:
    int n;
    int* arr;
  public:
    BIT(int n) : n(n) {
      arr = new int[n + 1]();
    }

    ~BIT() {
      delete[] arr;
    }

    void add(int x, int val) {
      for (int i = x; i <= n; i += (i & -i)) {
        arr[i] += val;
      }
    }

    int sum(int x) {
      int s = 0;
      for (int i = x; i > 0; i -= (i & -i)) {
        s += arr[i];
      }

      return s;
    }
  };
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](vector<int>& lhs, vector<int>& rhs) -> bool {
      return (lhs[0] == rhs[0]) ? lhs[1] > rhs[1] : lhs[0] < rhs[0];
    });

    int n = (int)people.size();
    vector<vector<int>> answer(n);
    BIT b(n);

    for (int i = 1; i <= n; ++i) {
      b.add(i, 1);
    }

    for (const vector<int>& v : people) {
      int l = 1;
      int r = n;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (b.sum(mid) > v[1]) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }

      b.add(r + 1, -1);
      answer[r] = v;
    }

    return answer;
  }
};
