/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/search-suggestions-system/
 * Runtime: 46ms
 * Time Complexity: O(NlogN) where N is the total length of all products
 */

class Solution {
public:
  vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    sort(products.begin(), products.end());

    int l = 0;
    int r = (int)products.size() - 1;
    int n = (int)searchWord.length();

    vector<vector<string>> answer(n);
    for (int i = 0; i < n; ++i) {
      while (l <= r && products[l][i] != searchWord[i]) {
        ++l;
      }
      while (l <= r && products[r][i] != searchWord[i]) {
        --r;
      }

      for (int j = l; j <= r && j < l + 3; ++j) {
        answer[i].emplace_back(products[j]);
      }
    }

    return answer;
  }
};
