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

int N;
vector<vector<int>> adj;
vector<bool> v;
vector<int> d;

void dfs(int n, int dist) {
  v[n] = 1;
  d[n] = max(d[n], dist);

  for (auto& i : adj[n]) {
    if (!v[i]) {
      dfs(i, dist + 1);
    }
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N;
  adj.resize(N); v.resize(N); d.resize(N);
  fill(v.begin(), v.end(), 0); fill(d.begin(), d.end(), verysmall);
  FOR(i, 0, N-1) {
    int a, b; cin >> a >> b;
    adj[--a].pb(--b);
    adj[b].pb(a);
  }

  dfs(0, 0);
  int a = distance(d.begin(), max_element(d.begin(), d.end()));
  fill(v.begin(), v.end(), 0); fill(d.begin(), d.end(), verysmall);
  dfs(a, 0);
  a = distance(d.begin(), max_element(d.begin(), d.end()));
  fill(v.begin(), v.end(), 0);
  dfs(a, 0);
  pout(d);

  return 0;
}
