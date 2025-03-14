#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define pb push_back
#define mp make_pair
#define endl '\n'
#define f first
#define s second 
#define verysmall LLONG_MIN;
#define verybig LLONG_MAX;
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define pout(v); for (auto i : v) {cout << i << " ";} cout << endl;
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)

int N, width;
vector<vector<int>> adj;
vector<bool> v;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N;
  adj.resize(N);
  v.resize(N);
  fill(v.begin(), v.end(), 0);
  v[0] = 1;
  width = verysmall;
  FOR(i, 0, N) {
    string s; cin >> s;
    FOR(j, 0, N) {
      if (s[j]-'0') {
        adj[i].pb(j); 
      }
    }
  }

  // begin bfs
  queue<int> q;
  q.push(0);

  while (!q.empty()) {
    int s = q.size();
    width = max(width, s); 
    FOR(i, 0, s) {
      int current = q.front();
      q.pop();
      for (int& n : adj[current]) {
        if (!v[n]) {
          v[n] = true;
          q.push(n);
        }
      }
    }
  }

  cout << width;

  return 0;
}
