/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/product-of-the-last-k-numbers/
 * Runtime: 11ms (94.59%)
 */

class ProductOfNumbers {
private:
  vector<int> prod{1};
  vector<int> zero{0};
public:
  ProductOfNumbers() {}
  
  void add(int num) {
    if (num == 0) {
      prod.emplace_back(1);
      zero.emplace_back(zero.back() + 1);
    } else {
      prod.emplace_back(prod.back() * num);
      zero.emplace_back(zero.back());
    }
  }

  int getProduct(int k) {
    const int n = prod.size();

    if (zero[n - 1] != zero[n - k - 1]) {
      return 0;
    }

    return prod[n - 1] / prod[n - k - 1];
  }
};
