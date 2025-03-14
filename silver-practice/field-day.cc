#include <bits/stdc++.h>
#include <utility>
using namespace std;
using ll = long long;
#define int long long
#define pb push_back
#define mp make_pair
#define endl '\n'
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define pout(v); for (auto i : v) {cout << i << " ";} cout << endl;
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)

int C, N;
vector<bool> t;

signed main() {
//int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> C >> N;
  vector<int> adj(1<<C, 1000);
  t.resize(N);
  
  queue<int> q;

  FOR(i, 0, N) {
    string s; cin >> s;
    int x = 0, nx = 0;
    for (auto i : s) {
      x = 2*x + (i == 'H');
      nx = 2*nx + (i == 'G');
    }

    t[i] = x;
    adj[nx] = 0;
    q.push(nx);
  }


  pout(t);
  pout(adj);

  cout << "\nafter\n";

  while (!q.empty()) {
    int x = q.front(); q.pop();

    FOR(c, 0, C) {
      int nx = x ^ (1<<c);
      if (adj[nx] == 1000) {
        q.push(nx);
        adj[nx] = adj[x] + 1;
      }
    }
  }


  pout(t);
  pout(adj);

  //cout << adj.size();
  FOR(i, 0, N) cout << C-adj[t[i]] << endl;

  return 0;
}
