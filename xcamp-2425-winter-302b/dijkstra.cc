// ALSO 6.8.cc
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
#define pout(v); for (auto i : v) {cout << ii << " ";} cout << endl;
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)

struct Node {
  int n, d;
};

bool operator>(Node a, Node b) {
  return a.d > b.d;
}

int N, M;
vector<vector<Node>> adj;
vector<int> dist;

void dijkstra() {
  priority_queue<Node, vector<Node>, greater<Node>> pq;
  dist[0] = 0;
  pq.push({0, 0});

  while(!pq.empty()) {
    int cn = pq.top().n;
    int cd = pq.top().d;
    pq.pop();

    if (cd != dist[cn]) {
      continue;
    }

    for (auto i : adj[cn]) {
      int nn = i.n;
      int nd = i.d;

      if (dist[cn] + nd < dist[nn]) {
        dist[nn] = dist[cn] + nd;
        pq.push({nn, dist[nn]});
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N >> M;

  dist.resize(N, verybig);
  adj.resize(N);

  FOR(i, 0, M) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[--a].pb({--b, c});
  }

  dijkstra();


  for(int &i : dist) {
    if (i > 1e17) cout << "inf " << endl;
    else cout << i << " ";
  }

  return 0;
}
