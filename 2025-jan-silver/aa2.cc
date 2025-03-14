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

int N, S, ret;
vector<int> a, b;
vector<pair<int, int>> o;
vector<vector<int>> dp;

int p(int l, int r) {
  return (a[l] != b[l] ? 0 : -1) + 
         (a[r] != b[r] ? 0 : -1) + 
         (a[l] == b[r] ? 1 : 0) + 
         (a[r] == b[l] ? 1 : 0);

}

int rev(int l, int r) {
  if (l == r || r < l) {
    return S;
  } else if (r - l < 3) {
    return p(l, r) + S;
  } else {
    return p(l, r) + dp[l+1][r-1];
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N;
  a.resize(N); b.resize(N); dp.resize(N);
  FOR(i, 0, N) cin >> a[i];
  FOR(i, 0, N) cin >> b[i];
  FOR(i, 0, N) S += (a[i] == b[i]); 
  FOR(i, 0, N) {
    dp[i].resize(N); 
    fill(dp[i].begin(), dp[i].end(), 0);
  }
  FOR(i, 0, N) FOR(j, 0, N-i) o.pb(mp(j, j+i));

  //for(pair<int, int> &p:o) {
  //  cout << p.f << " " << p.s << endl;
  //}
  //cout << endl << endl;

  ret = 0;
  for(pair<int, int> &p : o) {
    int l = p.f; int r = p.s;

    dp[l][r] = rev(l, r);
    ret += dp[l][r];
  }

  //for(vector<int> &a : dp) {
  //  pout(a);
  //}
  cout << ret;

  return 0;
}
