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
vector<vector<int>> g;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};

bool is_valid(int x, int y) {
  return x >= 0 && x < N && y >= 0 && y < M;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N >> M;
  g.resize(N);

  for(auto& row : g) {
    row.resize(M, verybig);
  }

  int sx, sy, ex, ey;

  FOR(i, 0, N) {
    FOR(j, 0, M) {
      char c; cin >> c;
      if (c == '*') {
        ex = i; ey = j;
        //g[i][j] = 0; 
      } else if (c == '#') {
        g[i][j] = -1;
      } else if (c == '$') {
        sx = i; sy = j;
        g[i][j] = 0;  
      }
    }
  }

  queue<tuple<int, int, int>> q;
  q.push(make_tuple(sx, sy, 0)); 

  while(!q.empty()) {
    tuple<int, int, int> t = q.front();
    q.pop();

    int x = get<0>(t);
    int y = get<1>(t);
    int w = get<2>(t);

    //cout << x << " " << y << " " << w << endl;

    if (x == ex && y == ey) {
      cout << 10 * w << endl;
      return 0;
    }

    FOR(i, 0, 4) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (is_valid(nx, ny) && g[nx][ny] == verybig) {
        g[nx][ny] = w + 1; 
        q.push(make_tuple(nx, ny, w + 1));
      }
    }
  }

  cout << "Cannot collect money\n"; 

  return 0;
}
