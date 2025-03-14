#include <bits/stdc++.h>
#include <utility>
using namespace std;
using ll = long long;
#define int ll 
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
vector<vector<char>> g;
vector<vector<bool>> v;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool ff(int x, int y, int l) {
  if (g[x][y] == '#') return 0;
  else if (g[x][y] == '$') return 1;
  //cout << x << " " << y << " " << l << endl;

  v[x][y] = 1;

  bool ret = 0;

  FOR(i, 0, 4) {
    if (!v[x+dx[i]][y+dy[i]]) {
      ret |= ff(x+dx[i], y+dy[i], l+1);
    } 
  }

  return ret;
}

int fff(int x, int y, int l) {
  if (g[x][y] == '#' || v[x][y]) return verybig;
  else if (g[x][y] == '$') return l;
  cout << x << " " << y << " " << l << endl;

  v[x][y] = 1;

  int ret = verybig;

  FOR(i, 0, 4) {
    ret = min(ret, fff(x+dx[i], y+dy[i], l+1));
  }

  cout << "---" << ret << endl;

  return ret;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N >> M;

  g.resize(N+2);
  for(auto&i:g) {
    i.resize(M+2);
  }

  v.resize(N+2);
  for(auto&i:v) {
    i.resize(M+2);
    fill(i.begin(), i.end(), 0);
  }

  FOR(i, 0, N+2) fill(g[i].begin(), g[i].end(), '#');

  int sx, sy;

  bool can = 0;

  FOR(i, 0, N) {
    FOR(j, 0, M) {
      cin >> g[i+1][j+1];
      if (g[i+1][j+1] == '*') {
        can = 1;
        sx = i+1;
        sy = j+1;
      }
    }
  }


  if (!can) {
    cout << "Cannot collect money" << endl;
    return 0;
  }

  can = ff(sx, sy, 0);

  if(!can) {
    cout << "Cannot collect money" << endl;
    return 0;
  }

  for(auto&i:v) {
    fill(i.begin(), i.end(), 0);
  }
  cout << 10*fff(sx, sy, 0) << endl;


  return 0;
}
