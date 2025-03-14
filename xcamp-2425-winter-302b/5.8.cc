#include <bits/stdc++.h>
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

int Q;

void solve() {
  int N, M;
  vector<tuple<int, int, int>> e;
  vector<int> dist;

  cin >> N >> M;
  e.resize(M);
  dist.resize(N, verybig);  

  FOR(i, 0, M) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;  
    e[i] = {a, b, c}; 
  }

  dist[0] = 0;  

  FOR(i, 0, N - 1) { 
    for (auto& edge : e) {
      int a, b, c;
      tie(a, b, c) = edge; 

      if (dist[a] != verybig && dist[b] > dist[a] + c) {
        dist[b] = dist[a] + c;
      }
    }
  }

  for (auto& edge : e) {
    int a, b, c;
    tie(a, b, c) = edge;
    if (dist[a] != verybig && dist[b] > dist[a] + c) {
      cout << "YES\n"; 
      return;
    }
  }

  cout << "NO\n";  
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> Q; 
  while (Q--) {
    solve();
  }

  return 0;
}

