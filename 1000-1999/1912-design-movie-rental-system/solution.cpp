/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/design-movie-rental-system/
 * Runtime: 286ms (76.64%)
 */

class MovieRentingSystem {
  struct Movie {
    int id;
    int p;
    int s;

    bool operator<(const Movie& rhs) const {
      return p < rhs.p || (p == rhs.p && s < rhs.s) || (p == rhs.p && s == rhs.s && id < rhs.id);
    }
  };

  set<Movie> s[10001];
  set<Movie> rented;
  unordered_map<long long, int> m;
public:
  MovieRentingSystem(int n, vector<vector<int>>& entries) {
    for (const auto& entry : entries) {
      s[entry[1]].insert({entry[1], entry[2], entry[0]});
      m.emplace(((long long)entry[1] << 32) | entry[0], entry[2]);
    }
  }
  
  vector<int> search(int movie) {
    const auto& l = s[movie];

    auto it = l.begin();
    vector<int> res;
    for (int i = 0; i < 5; ++i) {
      if (it == l.end()) {
        break;
      }
      res.emplace_back(it->s);
      ++it;
    }
    return res;
  }
  
  void rent(int shop, int movie) {
    const int price = m[((long long)movie << 32) | shop];
    s[movie].erase({movie, price, shop});
    rented.insert({movie, price, shop});
  }

  void drop(int shop, int movie) {
    const int price = m[((long long)movie << 32) | shop];
    s[movie].insert({movie, price, shop});
    rented.erase({movie, price, shop});
  }

  vector<vector<int>> report() {
    auto it = rented.begin();
    vector<vector<int>> res;
    for (int i = 0; i < 5; ++i) {
      if (it == rented.end()) {
        break;
      }
      res.push_back({it->s, it->id});
      ++it;
    }
    return res;
  }
};
