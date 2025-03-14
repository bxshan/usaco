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
#define pout(v); for (auto i : v) {cout << i << " ";} cout << endl;
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)

int x, y, z;
string a, b;
vector<vector<int>> dp;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> x >> y >> z;
  cin >> a >> b;
  dp.resize(a.length() + 1); 
  for(auto &i : dp) i.resize(b.length() + 1);
  iota(dp[0].begin(), dp[0].end(), 0);
  FOR(i, 0, b.length() + 1) dp[0][i] = x*i;
  FOR(i, 0, a.length() + 1) dp[i][0] = y*i;

  FOR(i, 1, a.length()+1) {
    FOR(j, 1, b.length()+1) {
      if (a[i-1] == b[j-1]) { 
        dp[i][j] = dp[i-1][j-1];
      } else {
        dp[i][j] = min(dp[i-1][j-1]*z, min(dp[i][j-1]*x, dp[i-1][j]*y))+1;
      }
    }
  }

  for(auto i : dp) {
    pout(i);
  }

  cout << dp[a.length()][b.length()];

  return 0;
}

