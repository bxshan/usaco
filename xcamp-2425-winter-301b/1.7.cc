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

int K, N;
int dp[1000009]; 
vector<int> c;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> K >> N;
  c.resize(K);
  FOR(i, 0, K) cin >> c[i];
  sort(c.begin(), c.end());
  fill(begin(dp), end(dp), verybig);

  dp[0] = 0;

  FOR(i, 1, N+1) for(auto&C:c) if (i > C - 1) dp[i] = min(dp[i], (dp[i-C] == verybig) ? verybig : dp[i-C]+1);

  if (dp[N] == verybig) cout << -1;
  else cout << dp[N];

  return 0;
}
