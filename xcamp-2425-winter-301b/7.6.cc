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

int W, N;
vector<int> w, v, dp;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N >> W;
  w.resize(N); v.resize(N);
  dp.resize(W+1);
  fill(dp.begin(), dp.end(), 0);

  FOR(i, 0, N) cin >> w[i];
  FOR(i, 0, N) cin >> v[i];

  FOR(pfxidx, 0, N) {
    ROF(capacity, W, w[pfxidx] - 1) {
      dp[capacity] = max(dp[capacity], dp[capacity - w[pfxidx]] + v[pfxidx]);
    }
  }

  cout << dp[W];

  return 0;
}
