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

int N, M;
vector<int> a, b;
vector<vector<int>> dp;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N >> M;
  a.resize(N); b.resize(M);
  FOR(i, 0, N) cin >> a[i];
  FOR(i, 0, M) cin >> b[i];
  dp.resize(N+1);
  for(vector<int> &i : dp) {
    i.resize(M+1);
    fill(i.begin(), i.end(), 0);
  }

  FOR(i, 1, N+1) {
    FOR(j, 1, M+1) {
      if (a[i-1] == b[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      }
    }
  }

  int ret = verysmall;
  for(auto&i:dp) {
    //pout(i);
    for(int j:i) {
      ret = max(ret, j);
    }
  }

  cout << ret;

  return 0;
}
