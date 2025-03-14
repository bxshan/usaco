#include <bits/stdc++.h>
#include <utility>
using namespace std;
#define ll long long;
#define int long long
#define pb push_back
#define mp make_pair
#define endl '\n'
#define f first
#define s second 
#define verysmall -1e18
#define verybig 1e18
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define pout(v); for (auto i : v) {cout << i << " ";} cout << endl;
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)

int V, N, T;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> V >> N >> T;
  vector<vector<pair<int, int> > > g(T);

  FOR(i, 0, N) {
    int w, v, t;
    cin >> w >> v >> t;
    g[--t].pb(mp(w, v));
  }

  vector<int> dp(V + 1, verysmall);  
  dp[0] = 0;  

  for (vector<pair<int, int> > &group : g) {
    vector<int> tmp(dp);  
    for (pair<int, int> &item : group) {
      int weight = item.f;
      int value = item.s;
      ROF(w, V, weight - 1) {
        tmp[w] = max(tmp[w], dp[w - weight] + value);
      }
    }
    //cout << "after: \n";
    //pout(tmp);
    dp = tmp; 
  }

  cout << *max_element(dp.begin(), dp.end());

  return 0;
}
