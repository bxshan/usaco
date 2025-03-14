#include <bits/stdc++.h>
#include <utility>
using namespace std;
using ll = long long;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define pout(v); for (auto i : v) {cout << i << " ";} cout << endl;
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)


int ans;
int sx, ex, sy, ey;
string dir;
vector<vector<bool>> f(4001, vector<bool>(4001));
vector<vector<bool>> v(4001, vector<bool>(4001));

void ff(int x, int y) {
  if (v[x][y] || f[x][y] || x < sx || y < sy || x > ex || y > ey) return;

  f[x][y] = 1;
  v[x][y] = 1;

  ff(x, y+1);
  ff(x, y-1);
  ff(x+1, y);
  ff(x-1, y);
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  fileio("gates");

  cin.ignore(256, '\n');
  cin >> dir;
  ans = 0;
  f[2000][2000] = 1;
  int x = 2000, y = 2000;
  sx = 4001; ex = -1; sy = 4001; ey = -1;

  for (auto&i:dir) {
    if (i == 'N') {
      f[x][++y] = 1; 
      f[x][++y] = 1;
    } else if (i == 'E') {
      f[++x][y] = 1; 
      f[++x][y] = 1;
    } else if (i == 'S') {
      f[x][--y] = 1;
      f[x][--y] = 1;
    } else if (i == 'W') {
      f[--x][y] = 1;
      f[--x][y] = 1;
    }
    sx = min(sx, x);
    ex = max(ex, x);
    sy = min(sy, y);
    ey = max(ey, y);
  }
  sx--; sy--; ex++; ey++;

  //FOR(i, sx, ex) {
  //  FOR(j, sy, ey) {
  //    //if (i == 1996 && j == 2005) {
  //    //  cout << "x ";
  //    //  continue;
  //    //}
  //    cout << f[i][j] << " ";
  //  }
  //  cout << endl;
  //}

  //cout << sx << " " << ex << " " << sy << " " << ey << endl;

  //cout << "\nbegin\n";
  FOR(i, sx, ex) {
    FOR(j, sy, ey) {
      if (!v[i][j] && !f[i][j]) {
        //cout << i << " " << j << endl;
        ans++;
        ff(i, j);

        //FOR(j, sy, ey) {
        //  FOR(i, sx, ex) {
        //    //if (i == 1996 && j == 2005) {
        //    //  cout << "x ";
        //    //  continue;
        //    //}
        //    cout << f[i][j] << " ";
        //  }
        //  cout << endl;
        //}
        //cout << "\n\n--------------\n\n";
      }
    }
  }

  cout << --ans;

  return 0;
}
