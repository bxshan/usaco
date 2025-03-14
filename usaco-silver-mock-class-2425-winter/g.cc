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

int N, M;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};

void ff(int x, int y, int l) {
  FOR(i, 0, 4) {
    if ()
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N >> M;
  vector<vector<int>> g(N+2, vector<int>(M+2));
  fill(g[0].begin(), g[0].end(), '#');
  fill(g[N+1].begin(), g[N+1].end(), '#');
  FOR(i, 0, N) {
    g[i][0] = '#';
    g[i][M+1] = '#';
  }

  int sx, sy;

  FOR(i, 1, N+1) {
    FOR(j, 1, M+1) {}
      cin >> g[i][j];
      if (g[i][j] = '*') {
        sx = i; sy = j;
      }
    }
  }

  for(auto&i:g) {
    pout(i);
  }

  //ff(sx, sy, 0);

  return 0;
}
