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

int N;
int dp[1009]; 

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N;
  fill(begin(dp), end(dp), verybig);

  dp[0] = 0;
  FOR(i, 1, N+1) {
    dp[i] = min(dp[i], dp[i-1]+1);
    if(i > 4) dp[i] = min(dp[i], dp[i-5]+1);
    if(i > 6) dp[i] = min(dp[i], dp[i-7]+1);
  }

  cout << dp[N];

  return 0;
}
