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
#define pout(v); for (auto i : v) {cout << i << " ";} cout << endl;
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)

string a, b;
vector<vector<int>> dp;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> a >> b;
  rs(dp, a.length()+1);
  for(vector<int> &a : dp) rs(a, b.length()+1);
  for(vector<int> &a : dp) fill(a.begin(), a.end(), 0);

  FOR(i, 0, a.length()) {
    FOR(j, 0, b.length()) {
      if (a[i] == b[j]) {
        dp[i+1][j+1] = dp[i][j] + 1;
      } else {
        dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
      }
    }
  }

  cout << dp[a.length()][b.length()];

  return 0;
}
