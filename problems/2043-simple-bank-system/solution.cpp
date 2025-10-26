/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/simple-bank-system/
 * Runtime: 8ms (80.94%)
 */

class Bank {
private:
  int n;
  vector<long long>& balance;
public:
  Bank(vector<long long>& balance) : n(balance.size()), balance(balance) {}
  
  bool transfer(int a, int b, long long money) {
    if (a < 1 || a > n || balance[a - 1] < money || b < 1 || b > n) {
      return false;
    }
    balance[a - 1] -= money;
    balance[b - 1] += money;
    return true;
  }
  
  bool deposit(int a, long long money) {
    if (a < 1 || a > n) {
      return false;
    }
    balance[a - 1] += money;
    return true;
  }
  
  bool withdraw(int a, long long money) {
    if (a < 1 || a > n || balance[a - 1] < money) {
      return false;
    }
    balance[a - 1] -= money;
    return true;
  }
};
