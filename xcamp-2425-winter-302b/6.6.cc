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
#define verysmall (LLONG_MIN - 110)
#define verybig (LLONG_MAX - 110)
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define pout(v); for (auto i : v) {cout << i << " ";} cout << endl;
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)

int N, M, S, T;
vector<vector<pair<int, int>>> adj;
vector<bool> v;
vector<int> dist;

void dijkstra() {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  dist[S] = 0;
  pq.push(mp(0, S));

  while (!pq.empty()) {
    int cn = pq.top().s;
    pq.pop();

    for (pair<int, int> p : adj[cn]) {
      int w = p.f;
      int n = p.s;

      if (dist[n] > dist[cn] + w) {
        dist[n] = dist[cn] + w;
        pq.push(mp(dist[n], n));
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N >> M >> S >> T;
  S--; T--;
  adj.resize(N);
  v.resize(N);
  dist.resize(N);
  fill(v.begin(), v.end(), 0);
  fill(dist.begin(), dist.end(), verybig);

  FOR(i, 0, M) {
    int w, a, b;
    cin >> a >> b >> w;
    adj[--a].pb(mp(w, --b));
    adj[b].pb(mp(w, a));
  }

  dijkstra();

  cout << dist[T];

  return 0;
}
