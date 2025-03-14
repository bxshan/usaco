// CSES
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
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define pout(v); for (auto i : v) {cout << i << " ";} cout << endl;
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)

int N, X;
int t, pfx, ans;
map<int, int> m; // pfx, count

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N >> X;
  pfx = 0, ans = 0;

  m[0] = 1;

  FOR(i, 0, N) {
    cin >> t; pfx += t;
    ans += m[pfx - X];
    m[pfx]++; 
  }

  //for(auto& i : m) {
  //  cout << i.f << " " << i.s << endl;
  //}
  //cout << "\n\n" << ans;
  cout << ans;

  return 0;
}
