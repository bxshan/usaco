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

int N, X;
vector<int> f;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N >> X;
  X++;
  f.resize(N);
  FOR(i, 0, N) {
    cin >> f[i];
  }

  int ans = 0;

  FOR(i, 0, N) {
    vector<int> v;
    if (i + X > N) {
      copy(f.begin()+i, f.end(), back_inserter(v));
      copy(f.begin(), f.begin() + (i + X) % N, back_inserter(v));
    } else {
      copy(f.begin()+i, f.begin()+i+X, back_inserter(v));
    }
    //pout(v);
    ans = max(ans, (int) accumulate(v.begin(), v.end(), 0));
    //cout << ans << endl;
  }

  cout << ans << endl;

  return 0;

}
