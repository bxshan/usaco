#include <bits/stdc++.h>
#include <utility>
using namespace std;
using ll = long long;
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)


int N, M, ans;
pair<bool, bool> l[101][101];
// l[lit?][visited?]
vector<pair<int, int>> adj[101][101];

void ff(int x, int y) {
  //cout << x << " " << y << endl;
  if (!l[x][y].first || l[x][y].second || x < 1 || y < 1 || x > N || y > N) return;

  l[x][y].second = 1;

  for(auto& i : adj[x][y]) {
    int a = i.first, b = i.second;
    if (!l[a][b].first) ans++;
    l[a][b].first = 1;

    if (l[a+1][b].second || 
        l[a-1][b].second || 
        l[a][b+1].second || 
        l[a][b-1].second) {
      ff(a, b);
    }
  }

  ff(x+1, y);
  ff(x-1, y);
  ff(x, y+1);
  ff(x, y+1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  fileio("lightson");

  cin >> N >> M;
  ans = 1;

  FOR(i, 0, M) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    adj[x][y].push_back(make_pair(a, b));
  }

  FOR(i, 0, 102) {
    FOR(j, 0, 102) {
      l[i][j] = make_pair(0, 0);
    }
  }
  l[1][1] = make_pair(1, 0);

  ff(1, 1);


  //FOR(i, 1, N+1) {
  //  FOR(j, 1, N+1) {
  //    cout << l[i][j].first << l[i][j].second << " ";
  //  }
  //  cout << endl;
  //}

  cout << ans; 

  return 0;
}
