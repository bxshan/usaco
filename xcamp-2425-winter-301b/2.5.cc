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
const int MOD = 1e9 + 7;

int N, K;
vector<int> c, dp;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N >> K;
  c.resize(N); dp.resize(K+1);
  fill(dp.begin(), dp.end(), 0);
  dp[0] = 1;
  FOR(i, 0, N) cin >> c[i];

  FOR(i, 1, K+1) for(auto&C:c) if (i > C - 1) dp[i] = (dp[i] + dp[i-C]) % MOD;
  
  cout << dp[K] % MOD;

  return 0;
}
