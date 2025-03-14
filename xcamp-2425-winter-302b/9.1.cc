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

struct DSU {
  vector<int> parent, rank, size;

  DSU(int N) {
    parent.resize(N);
    rank.resize(N, 0);
    size.resize(N, 1);
    iota(parent.begin(), parent.end(), 0); 
  }

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
      if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
        size[rootX] += size[rootY];
      } else if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
        size[rootY] += size[rootX];
      } else {
        parent[rootY] = rootX;
        rank[rootX]++;
        size[rootX] += size[rootY];
      }
    }
  }
};

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;

  vector<pair<int, pair<int, int>>> e; 
  DSU dsu(N);

  FOR(i, 0, M) {
    int a, b;
    cin >> a >> b;
    e.pb({1, {--a, --b}}); 
  }

  int connections = 0, mcs = 0;

  for (auto& E : e) {
    int u = E.s.f, v = E.s.s;

    if (dsu.find(u) != dsu.find(v)) {
      dsu.unite(u, v);
      connections++;
    }

    FOR(i, 0, N) mcs = max(mcs, dsu.size[dsu.find(i)]);

    cout << N - connections << " " << mcs << endl;
  }

  return 0;
}

