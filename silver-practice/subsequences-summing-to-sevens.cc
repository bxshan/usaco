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

int N;
vector<ll> pfx;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  fileio("div7");

  cin >> N;
  pfx.resize(N+1);
  pfx[0] = 0;
  FOR(i, 1, N) {
    cin >> pfx[i];
    pfx[i] = (pfx[i-1] + pfx[i]) % 7;
  }

  vector<int> b, e;
  b.resize(7); 
  fill(b.begin(), b.end(), 0);
  e.resize(7); 
  fill(e.begin(), e.end(), 0);

  FOR(i, 1, N+1) {
    if (b[pfx[i]] == 0) {
      b[pfx[i]] = i;
    }
    e[pfx[i]] = i;
  }

  FOR(i, 1, N+1) {
    e[pfx[i]] = i;
  }

  ROF(i, N, -1) {
    b[pfx[i]] = i;
  }

  int ans = 0;
  FOR(i, 0, 7) {
    if (b[i] != 0 && e[i] != 0) {
      ans = max(ans, e[i]-b[i]);
    }
  }

  cout << ans;

  return 0;
}
