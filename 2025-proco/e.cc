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
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define pout(v); for (auto i : v) {cout << i << " ";} cout << endl;
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)

string s;
int N, M;
vector<vector<char>> e;

bool bfs(int i, int j, int idx) {
  if (i < 0 || i > N-1 || j < 0 || j > M-1 || e[i][j] != s[idx]) {
    return 0;
  }
  if (idx == s.length()-1) {
    return 1;
  }
  //cout << i << " " << j << " " << idx << endl;

  bool f = 0;
  int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
  FOR(k, 0, 8) {
    if (f) break;
    f |= bfs(i+dx[k], j+dy[k], idx+1);
  }
  return f;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> s >> N >> M;
  e.resize(N);
  FOR(i, 0, N) {
    e[i].resize(M);
    string stmp;
    cin >> stmp;
    FOR(j, 0, M) {
      e[i][j] = stmp[j];
    }
  }

  bool fnd = 0;
  FOR(i, 0, N) {
    FOR(j, 0, M) {
      if (!fnd) {
        fnd = bfs(i, j, 0);
      }
    }
  }

  if (fnd) cout << "yes\n";
  else cout << "no\n";

  return 0;
}

