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

void solve() {
  int N, C;
  vector<tuple<int, int, int>> a;
  vector<int> dist;

  // cin
  cin >> N >> C;
  a.resize(N);
  dist.resize(N);
  FOR(i, 0, N) {
    cin >> get<0>(a[i]) >> get<1>(a[i]);
    get<2>(a[i]) = min(get<0>(a[i]), C-get<0>(a[i]));
    dist[i] = get<1>(a[i])-get<2>(a[i]);
  }

  // solve
  int cpos = 0;
  while(1) {
    if (!cpos && (dist[cpos] < 0 && dist[N-1] < 0) || cpos && (dist[cpos] < 0 && dist[cpos-1] < 0)) {
      break;
    }

    if (!cpos) {
      if (dist[N-1] > dist[cpos]) {
        cpos = N-1;

      } else {
        cpos = 
      }
    }
  }
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
