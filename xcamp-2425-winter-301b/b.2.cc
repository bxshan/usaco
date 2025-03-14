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

int N;
vector<string> a;
vector<int> dp;

// is a prefix of b
bool is_prefix(const string &a, const string &b) {
  if (a.length() >= b.length()) return 0;

  int i = 0; int j = 0;
  while (i < a.length() && j < b.length()) {
    if (a[i] != b[j]) {
      return 0;
    }
    i++; j++;
  }
  return 1;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N;
  a.resize(N); 
  dp.resize(N);
  fill(dp.begin(), dp.end(), verysmall);
  dp[0] = 1;
  FOR(i, 0, N) {
    cin >> a[i];
  }

  int ret = verysmall;
  FOR(i, 0, N) {
    FOR(j, 0, N) {
      if (i == j) continue;
      if (is_prefix(a[j], a[i])) {
        dp[i] = max(dp[i], dp[j]) + 1;
      }
    }
    ret = max(ret, dp[i]);
  }

  cout << ret;

  return 0;
}
