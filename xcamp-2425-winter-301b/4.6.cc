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

string a, b, res;
vector<vector<int>> dp;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  rs(dp, 101);
  for(auto &i : dp) rs(i, 101);
  cin >> a >> b >> res;
  if (a.length() + b.length() != res.length()) {
    cout << "no";
    return 0;
  }
  a = "!" + a;
  b = "!" + b;
  res = "!" + res;
  for(auto& i : dp) fill(i.begin(), i.end(), 0);

  FOR(i, 0, a.length()) {
    dp[i][0] = 1;
  }
  FOR(i, 0, b.length()) {
    dp[0][i] = 1;
  }

  FOR(i, 1, a.length()) {
    FOR(j, 1, b.length()) {
      dp[i][j] = dp[i-1][j] && a[i] == res[i+j] ||
                 dp[i][j-1] && b[j] == res[i+j];
    }
  }

  cout << (dp[a.length()-1][b.length()-1] ? "yes" : "no");
  
  return 0;
}
