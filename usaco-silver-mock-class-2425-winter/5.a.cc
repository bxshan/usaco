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
#define rs(v, n) v.resize(n)
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define pout(v); for (auto i : v) {cout << i << " ";} cout << endl;
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)

struct DSU {
  vector<int> parent, rank, size;

  DSU (int N) {
    parent.resize(N);
    rank.resize(N);
    size.resize(N, 1);
    fill(rank.begin(), rank.end(), 0);
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

int Q;

void solve() {
  int N;
  string a, b;

  cin >> N >> a >> b;

  DSU dsu(26);  

  FOR(i, 0, N) {
    //cout << "uniting: " << a[i] << b[i] << endl;
    dsu.unite(a[i] - 'a', b[i] - 'a');
    //pout(dsu.parent);
    //pout(dsu.rank);
    //pout(dsu.size);
  }

  int count = 0;

  FOR(i, 0, 26) {
    if (dsu.find(i) == i && dsu.size[i] > 1) {  
      count += dsu.size[i] - 1;
    }
  }

  cout << count << " "; 
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> Q;

  while(Q--) {
    solve();
  }

  return 0;
}

