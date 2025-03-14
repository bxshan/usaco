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

int Q;

void solve() {
  int a, b, at, bt;
  cin >> a >> b >> at >> bt;

  if (at < a || bt < b) {
    cout << "-1\n"; 
    return;
  }

  int ret = 0;
  int last_largest = -1;

  while (at != a || bt != b) {
    if (at > bt) {
      if (last_largest == 0) {
        cout << "-1\n";
        return;
      }
      last_largest = 0;

      int tmp = (at - a) / bt;
      ret += tmp;
      at -= tmp * bt;
    } else {
      if (last_largest == 1) {
        cout << "-1\n";
        return;
      }
      last_largest = 1;

      int tmp = (bt - b) / at;
      ret += tmp;
      bt -= tmp * at;
    }
  }

  if (!(at == a && bt == b)) {
    cout << "-1\n";
    return;
  }

  cout << ret << endl;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> Q;
  while(Q--) {
    solve();
  }

  return 0;
}
