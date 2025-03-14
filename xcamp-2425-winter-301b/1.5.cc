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
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define pout(v); for (auto i : v) {cout << i << " ";} cout << endl;
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)

int N;
vector<vector<int>> dp;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N;
  dp.resize(N);
  FOR(i, 0, N) {
    dp[i].resize(i+1);
    FOR(j, 0, i+1) cin >> dp[i][j];
  }

  FOR(i, 1, N) {
    FOR(j, 0, i+1) {
      if (j == 0) dp[i][j] += dp[i-1][j];
      else if (i == j) dp[i][j] += dp[i-1][j-1];
      else dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
    }
  }

  cout << *max_element(dp[N-1].begin(), dp[N-1].end());

  return 0;
}
