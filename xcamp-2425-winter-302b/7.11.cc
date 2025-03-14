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

int s1, t1, s2, t2;
int N, M;
vector<vector<int>> nn;


void fw(vector<vector<int>> &adj) {
  FOR(k, 0, N) {
    FOR(i, 0, N) {
      FOR(j, 0, N) {
        if (adj[i][j] > adj[i][k] + adj[k][j]) {
          adj[i][j] = adj[i][k] + adj[k][j];
          nn[i][j] = nn[i][k];
        } else if (adj[i][j] == adj[i][k] + adj[k][j]) {
          if (nn[i][j] > nn[i][k]) {
            nn[i][j] = nn[i][k];
          }
        }
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> s1 >> t1 >> s2 >> t2 >> N >> M;
  s1--; t1--; s2--; t2--;
  nn.resize(N, vector<int>(N, verybig));
  vector<vector<int>> adj(N, vector<int>(N, verybig));

  FOR(i, 0, N) {
    adj[i][i] = 0;
  }

  FOR(i, 0, M) {
    int a, b, c;
    cin >> a >> b >> c; a--; b--;
    adj[a][b] = min(adj[a][b], c);
    adj[b][a] = min(adj[b][a], c);
    nn[a][b] = min(adj[a][b], c);
    nn[b][a] = min(adj[b][a], c);
  }

  fw(adj);

  for(auto&i:nn) {
    pout(i);
  }

  return 0;
}
