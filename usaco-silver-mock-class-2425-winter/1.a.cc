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

int Q;

void solve() {
  int N;
  vector<int> a;
  cin >> N;
  a.resize(N);
  FOR(i, 0, N) cin >> a[i];

  cout << N << endl;
  pout(a); 
 
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> Q;
  while (Q--) {
    solve();
  }

  return 0;
}
