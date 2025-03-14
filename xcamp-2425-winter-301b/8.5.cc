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
#define verysmall -1e18
#define verybig 1e18
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define pout(v); for (auto i : v) {cout << i << " ";} cout << endl;
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)

int n;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n;

  int w[n], v[n];
  iota(w, w + n, 1); 

  FOR(i, 0, n) {
    v[i] = 0;
    FOR(j, 1, i + 2) {
      if ((i + 1) % j == 0) v[i]++;
    }
  }

  int dp[n + 1];
  fill_n(dp, n + 1, 0); 

  FOR(maxidx, 0, n) {
    ROF(cap, n, w[maxidx]-1) {
      dp[cap] = max(dp[cap], dp[cap- w[maxidx]] + v[maxidx]);
    }
  }

  cout << dp[n]; 

  return 0;
}
