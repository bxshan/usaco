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

int N, M;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N >> M;
  vector<pair<int, pair<int, int>>> e;

  FOR(i, 0, M) {
    int w, a, b;
    cin >> a >> b >> w;
    e.pb(mp(w, mp(--a, --b)));
  }

  sort(e.begin(), e.end());

  DSU dsu(N);
  int cnt = 0, size = 0;

  for (auto &E : e) {
    int w = E.f, a = E.s.f, b = E.s.s;

    if (dsu.find(a) != dsu.find(b)) {
      dsu.unite(a, b);
      size += w;
    }
  }

  cout << size;

  return 0;
}
