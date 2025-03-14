#include <bits/stdc++.h>
#include <utility>
using namespace std;
using ll = long long;
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)


int N, w;
vector<bool> c;
// 0 is elsie, 1 is bessie

void solve() {
  cin >> N;
  w = 0;
  c.resize(2*N);
  fill(c.begin(), c.end(), 1);
  FOR(i, 0, N) {
    int x; cin >> x;
    c[--x] = 0;
  }

  int p = 0;
  FOR(i, 0, 2*N) {
    if (!c[i]) {
      p++;
    } else {
      if (p > 0) {
        p--;
        w++;
      }
    }
  }

  cout << w;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  fileio("highcard");

  solve();

  return 0;
}
