#include <bits/stdc++.h>
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

int N, M;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N >> M;
  int adj[N][N];

  FOR(i, 0, N) {
    FOR(j, 0, N) {
      adj[i][j] = -1; 
    }
  }

  FOR(i, 0, M) {
    int a, b, w;
    cin >> a >> b >> w;
    adj[--a][--b] = w;
    adj[b][a] = w;
  }

  vector<int> dist(N, verybig);
  vector<bool> v(N, false);   
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  pq.push(mp(0, 0));
  dist[0] = 0;  

  int mst_weight = 0; 

  while(!pq.empty()) {
    int a = pq.top().s;
    int weight = pq.top().f;
    pq.pop();

    if (v[a]) continue; 
    v[a] = true;         
    mst_weight += weight;  

    FOR(i, 0, N) {
      int b = i, w = adj[a][i];
      if (w != -1 && !v[b] && w < dist[b]) {
        dist[b] = w;  
        pq.push(mp(w, b));  
      }
    }
  }

  cout << mst_weight;

  return 0;
}
