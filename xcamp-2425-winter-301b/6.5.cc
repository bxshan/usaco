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
#define verysmall LLONG_MIN
#define verybig LLONG_MAX
#define rs(v, n) v.resize(n)
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define pout(v); for (auto i : v) {cout << i << "\t";} cout << endl;
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)

int N;
vector<vector<int>> g, dp;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N;
  g.resize(N);
  dp.resize(N);
  FOR(i, 0, N) {
    g[i].resize(N);
    dp[i].resize(N);
    fill(g[i].begin(), g[i].end(), 0);
    fill(dp[i].begin(), dp[i].end(), 0);
  }

  while(1) {
    int a, b, c;
    cin >> a >> b >> c;
    if (!a && !b && !c) break;
    g[--a][--b] = c;
   

  dp[0][0] = g[0][0];

  FOR(i, 1, N) dp[0][i] += dp[0][i-1] + g[0][i];
  FOR(i, 1, N) dp[i][0] += dp[i-1][0] + g[i-1][0];
  FOR(i, 1, N) FOR(j, 0, N) dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + g[i][j];

  cout << dp[N-1][N-1];

  return 0;
}
