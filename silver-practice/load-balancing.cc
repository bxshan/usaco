#include <bits/stdc++.h>
#include <utility>
using namespace std;
using ll = long long;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define pout(v); for (auto i : v) {cout << i << " ";} cout << endl;
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)

int N;
vector<pair<int, int>> c;

bool cmpx = [] (pair<int, int> a, pair<int, int> b) {
  return a.first < b.first;
};

bool cmpy = [] (pair<int, int> a, pair<int, int> b) {
  return a.second < b.second;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N;
  FOR(i, 0, N) {
    cin >> c[i].first >> c[i].second;
  }

  int x, y;
  sort(c.begin(), c.end(), cmpx);
  x = 
  
  return 0;
}
