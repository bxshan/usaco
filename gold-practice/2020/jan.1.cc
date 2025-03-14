// Time Is Mooney 993
#include <bits/stdc++.h>
#include <utility>
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
#define pout(v); for (auto i : v) {cout << i << "\t";} cout << endl << endl;
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)

int N, M, C;
vector<int> mooney;
vector<vector<int>> adj;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  
  //fileio("time");

  cin >> N >> M >> C;
  mooney.resize(N);
  adj.resize(N);
  FOR(i, 0, N) cin >> mooney[i];
  FOR(i, 0, M) {
    int a, b;
    cin >> a >> b;
    adj[--a].pb(--b);
  }

  vector<vector<int>> dp(1000, vector<int>(N, -1));

  dp[0][0] = 0;

  int ret = 0;

  FOR(t, 0, 1000) {
    FOR(i, 0, N) {

      if(dp[t][i] == -1) continue;

      for(int c : adj[i]) {
        if (t+1 < 1000) {
          //dp[t+1][c] = max(dp[t+1][c], dp[t][i] + mooney[c] - (C * (t) * (t)));
          dp[t+1][c] = max(dp[t+1][c], dp[t][i] + mooney[c]);
        }
      }
      //ret = max(ret, dp[t][0]);
      ret = max(ret, dp[t][0] - C * t * t);
    }
  }

  cout << ret;

  //cout << endl;

  //for(auto& i : adj) {
  //  for(auto& j : i) {
  //    cout << j << "\t";
  //  }
  //  cout << endl;
  //}

  //int cnt = 0;
  //for(auto&i:dp) {
  //  if (cnt>10) break;
  //  pout(i);
  //  cnt++;
  //}

  return 0;
}
