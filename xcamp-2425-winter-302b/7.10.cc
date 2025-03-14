// FLOYD WARSHALL FOR NEGATIVE CYCLES
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
#define pout(v); for (auto i : v) {cout << i << " ";} cout << endl;
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)

int N;

bool fwnw(vector<vector<int>> &adj) {
  FOR(k, 0, N) {
    FOR(i, 0, N) {
      FOR(j, 0, N) {
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
      }
    }
  }
  

  FOR(k, 0, N) {
    FOR(i, 0, N) {
      FOR(j, 0, N) {
        if (adj[i][k] + adj[k][j] < adj[i][j]) {
          return false;
        }
      }
    }
  }

  return true;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N;
  vector<vector<int>> adj(N, vector<int>(N));

  FOR(i, 0, N) {
    FOR(j, 0, N) {
      int a; cin >> a;
      //if (i != j && a == 0) {
      //  a = verybig;
      //}
      adj[i][j] = a;
    }
  }

  fwnw(adj);
  
  //for(vector<int> i : adj) {
  //  pout(i);
  //}
  
  if (!fwnw(adj)) {
    cout << "No Solution";
  } else {
    for(vector<int> i : adj) {
      pout(i);
    }
  }

  return 0;
}
