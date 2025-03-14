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
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define pout(v); for (auto i : v) {cout << i << "\t";} cout << endl << endl;
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)

int N, M;
vector<vector<int>> g, dp;
vector<tuple<int, int, int>> o;

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
  return get<2>(a) < get<2>(b);
}

bool in_range(int x, int y) {
  return x > -1 && x < N && y > -1 && y < M;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N >> M;
  g.resize(N);
  dp.resize(N);
  FOR(i, 0, N) {
    g[i].resize(M);
    dp[i].resize(M);
    FOR(j, 0, M) {
      dp[i][j] = 1;
      cin >> g[i][j];
      o.pb(make_tuple(i, j, g[i][j]));
    }
  }

  sort(o.begin(), o.end(), cmp);

  int ret = verysmall;

  for(tuple<int, int, int> &t : o) {
    int n = get<0>(t);
    int m = get<1>(t);

    if (in_range(n-1, m)) dp[n][m] = max(dp[n][m], dp[n-1][m]);
    if (in_range(n+1, m)) dp[n][m] = max(dp[n][m], dp[n+1][m]);
    if (in_range(n, m-1)) dp[n][m] = max(dp[n][m], dp[n][m-1]);
    if (in_range(n, m+1)) dp[n][m] = max(dp[n][m], dp[n][m+1]);
    dp[n][m]++;
    ret = max(ret, dp[n][m]);
  }

  for(auto&i:dp) {
    pout(i);
  }

  if (ret == 1) cout << 1;
  else cout << ret-1;

  return 0;
}

