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
  int N, E, tot;
  vector<int> pfx;
  cin >> N;
  E = verybig;
  pfx.resize(N+1);
  pfx[0] = 0;

  FOR(i, 1, N+1) {
    cin >> pfx[i];
    pfx[i] += pfx[i-1];
  }
  tot = pfx[N];

  //for i in range(N - N // 2):
  //      min_bessie = min(min_bessie, cum[i + N // 2 + 1] - cum[i])  
  FOR(i, 0, N-N/2) {
    E = min(E, pfx[i+N/2+1]-pfx[i]);
    cout << E << " " << pfx[i+N/2+1] - pfx[i] << endl;
  }

  cout << endl << E << " " << tot - E <<  endl;

  /*
   * 40 30 20 10
   * 0  40 70 90 100
   */
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> Q;

  while (Q--) solve();

  return 0;
}
