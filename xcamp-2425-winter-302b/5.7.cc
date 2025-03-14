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

int N, M, s, t;
vector<vector<int>> adj;
vector<int> dist;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N >> M;
  adj.resize(N);
  dist.resize(N);
  FOR(i, 0, M) {
    int a, b;
    cin >> a >> b;
    adj[--a].pb(--b);
    adj[b].pb(a);
  }
  cin >> s >> t;
  s--; t--;

  // start bfs

  fill(dist.begin(), dist.end(), -1);
  dist[s] = 0;
  queue<int> q;
  q.push(s);

  while(!q.empty()) {
    int n = q.front();
    q.pop();

    for(int i : adj[n]) {
      if (dist[i] == -1) {
        dist[i] = dist[n] + 1;
        q.push(i);
      }
    }
  }

  cout << dist[t];

  return 0;
}
