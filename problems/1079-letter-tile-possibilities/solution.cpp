/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/letter-tile-possibilities/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int numTilePossibilities(string& tiles) {
    const int n = tiles.size();
    sort(tiles.begin(), tiles.end());

    function<int()> dfs = [&]() {
      int sum = 0;
      for (int j = 0; j < tiles.size(); ++j) {
        if (tiles[j] == 0 || (j != 0 && tiles[j] == tiles[j - 1])) {
          continue;
        }
        char c = tiles[j];
        tiles[j] = 0;
        sum += 1 + dfs();
        tiles[j] = c;
      }
      return sum;
    };

    return dfs();
  }
};
