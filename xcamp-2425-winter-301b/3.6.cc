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
vector<int> a;
vector<vector<int>> dp;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N;
  rs(a, N); rs(dp, N);
  FOR(i, 0, N) {
    cin >> a[i];
    rs(dp[i], N);
    fill(dp[i].begin(), dp[i].end(), verybig);
    dp[i][i] = 0;
  }

  FOR(diff, 3, N+1) {
    for(int l = 0, r = diff-1; r < N; l++, r++) {
      cout << l << " " << r << endl;
      for(int k = l+1; k < r; k++) {
        dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r] + a[l]*a[k]*a[r]);
      }
    }
  }

  //cout << dp[0][N-1];
  for(auto i : dp) {
    pout(i);
  }

  return 0;
}
