// IMPLEMENTATION OF FLOYD WARSHALL ALGORITHM
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
#define rs(v, n) v.resize(n)
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define pout(v); for (auto i : v) {cout << i << " ";} cout << endl;
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)

int N, M, Q;

void fw(vector<vector<int>> &adj) {
  FOR(k, 0, N) {
    FOR(i, 0, N) {
      FOR(j, 0, N) {
        if (adj[i][k] + adj[k][j] < adj[i][j]) {
          adj[i][j] = adj[i][k] + adj[k][j];
        }
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N >> M >> Q;
  vector<vector<int>> adj(N, vector<int>(N, verybig));

  FOR(i, 0, N) {
    adj[i][i] = 0;
  }

  FOR(i, 0, M) {
    int a, b, c;
    cin >> a >> b >> c; a--; b--;
    adj[a][b] = min(adj[a][b], c);
    adj[b][a] = min(adj[b][a], c);
  }

  fw(adj);

  FOR(i, 0, Q) {
    int a, b;
    cin >> a >> b;
    if (adj[--a][--b] > 1e17) {
      cout << -1 << endl;
    } else {
      cout << adj[a][b] << endl;
    }
  }

  return 0;
}
