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
vector<int> a, pfx;
vector<vector<int>> dp;

int fill(int l, int r) {
  cout << l << " " << r << endl;
  if (dp[l][r] != verybig) return dp[l][r];

  int ret = verybig;
  FOR(i, l, r) {
    ret = min(ret, min(fill(l, i), fill(i+1, r)));
  }

  return ret + pfx[r+1] - pfx[l];

  //dp[l][r] = ret + pfx[r+1] - pfx[l];
  //return dp[l][r];
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N;
  rs(a, N); rs(pfx, N+1); rs(dp, N);
  pfx[0] = 0;
  FOR(i, 0, N) {
    cin >> a[i];
    pfx[i+1] = pfx[i] + a[i];
    rs(dp[i], N);
    fill(dp[i].begin(), dp[i].end(), verybig);
    dp[i][i] = 0;
  }

  //FOR(i, 0, N) {
  //  FOR(j, 0, N-1) {
  //    int l = j; int r = i+j;
  //    cout << "calling " << l << " " << r << endl;
  //    dp[l][r] = fill(l, r);
  //  }
  //}

  FOR(diff, 2, N+1) {
    for(int l = 0, r = diff-1; r < N; l++, r++) {
      //cout << l << " " << r << endl;
      FOR(k, l, r) {
        dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r] + pfx[r+1] - pfx[l]);
      }
    }
  }

  //for(vector<int> & i : dp) {
  //  pout(i);
  //}
  cout << dp[0][N-1];

  return 0;
}
