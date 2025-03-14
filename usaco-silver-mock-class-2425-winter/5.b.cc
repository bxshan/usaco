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

int Q;

bool cmp1(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.f - a.s) > (b.f - b.s);
}

bool cmp2(const pair<int, int> &a, const pair<int, int> &b) {
  return a.s > b.s;
}

void solve() {
  int N, A, B;
  cin >> N >> A >> B;
  vector<pair<int, int>> d;

  FOR(i, 0, N) {
    int a, b;
    cin >> a >> b;
    d.pb(mp(a, b));
  }

  int maxval = 0;

  FOR(i, 0, N) {

  }

}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> Q;
  while(Q--) solve();

  return 0;
}
