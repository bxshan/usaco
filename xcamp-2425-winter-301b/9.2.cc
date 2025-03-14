#include <bits/stdc++.h>
using namespace std;
#define ll = long long;
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

int V, N;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> V >> N;

  vector<int> w(N), v(N), q(N);

  FOR(i, 0, N) cin >> w[i] >> v[i] >> q[i];

  vector<int> dp(V+1, verysmall);
  dp[0] = 0;

  FOR(idx, 0, N) {
    if (q[idx] == 0) {
      FOR(W, w[idx], V+1) {
        dp[W] = max(dp[W], dp[W - w[idx]] + v[idx]);
      }
    } else {
      FOR(Q, 1, q[idx]+1) {
        ROF(W, V, w[idx]-1) {
          dp[W] = max(dp[W], dp[W - w[idx]] + v[idx]);
        }
      }
    }
  }

  cout << dp[V];

  return 0;
}
