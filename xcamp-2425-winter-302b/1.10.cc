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
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define pout(v); for (auto i : v) {cout << i << " ";} cout << endl;
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)

int C, R;
vector<vector<int>> adj;
vector<bool> v;
vector<int> n;

void dfs(int cn) {
  for (auto& n : adj[cn]) {
    if (!v[n]) {
      v[n] = 1;
      dfs(n);
    }
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> C >> R; 
  adj.resize(C);
  v.resize(C);
  fill(v.begin(), v.end(), 0);
  FOR(i, 0, R) {
    int a, b;
    cin >> a >> b;
    adj[--a].pb(--b);
    adj[b].pb(a);
  }


  FOR(i, 0, C) {
    if (!v[i]) {
      n.pb(i+1);
      dfs(i);
    }
  }

  if (n.size()-1 == 0) {
    cout << n.size()-1 << endl;
  } else {
    cout << n.size()-1 << endl;
    FOR(i, 0, n.size()-1) cout << n[i] << " " << n[i+1] << "\n";
  }

  return 0;
}

