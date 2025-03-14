#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

int N, W;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N >> W;

  int w[N], v[N];

  FOR(i, 0, N) {
    int m;
    cin >> w[i] >> v[i] >> m;
    w[i] *= m; 
    v[i] *= m;
  }

  vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

  FOR(idx, 1, N + 1) { 
    FOR(cap, 0, W + 1) {  
      dp[idx][cap] = dp[idx-1][cap];
      if (cap >= w[idx-1]) {
        dp[idx][cap] = max(dp[idx][cap], dp[idx-1][cap - w[idx-1]] + v[idx-1]); 
      }
    }
  }

  cout << dp[N][W] << endl;

  vector<int> chosen;
  int currw = W;

  ROF(itm, N, 0) {
    if (dp[itm][currw] != dp[itm - 1][currw]) { 
      chosen.pb(itm); 
      currw -= w[itm - 1]; 
    }
  }

  reverse(chosen.begin(), chosen.end());  
  pout(chosen);

  return 0;
}
