#include <bits/stdc++.h>
#include <utility>
using namespace std;
using ll = long long;
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)

int N, Q;
vector<int> h, g, j;

void solve() {
  int l, r; cin >> l >> r;
  cout << h[r] - h[--l] << " " 
    << g[r] - g[l] << " " 
    << j[r] - j[l] << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  fileio("bcount");

  cin >> N >> Q;
  h.resize(N+1);
  g.resize(N+1);
  j.resize(N+1);
  fill(h.begin(), h.end(), 0);
  fill(g.begin(), g.end(), 0);
  fill(j.begin(), j.end(), 0);

  FOR(i, 1, N+1) {
    int t; cin >> t;
    h[i] = h[i-1];
    g[i] = g[i-1];
    j[i] = j[i-1];

    if (t == 1) h[i]++;
    else if (t == 2) g[i]++;
    else if (t == 3) j[i]++;
  }

  while (Q--) {
    solve();
  }

  return 0;
}
