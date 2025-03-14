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
vector<int> a, b;

int check(int l, int r) {
  int cnt = 0;
  FOR(i, 0, l) cnt += (a[i] == b[i]);
  ROF(i, r, l-1) cnt += (a[i] == b[r+l-i]);
  FOR(i, r+1, N) cnt += (a[i] == b[i]);
  return cnt;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N;
  a.resize(N); b.resize(N);
  FOR(i, 0, N) cin >> a[i];
  FOR(i, 0, N) cin >> b[i];

  int ret = 0;

  FOR(l, 0, N) {
    FOR(r, l, N) {
      int c = check(l, r);
      //cout << l << " " << r << " " << c << endl;
      ret += c;
    }
  }

  cout << ret;

  return 0;
}
