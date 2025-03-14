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
#define verysmall LLONG_MIN
#define verybig LLONG_MAX
#define rs(v, n) v.resize(n)
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define pout(v); for (auto i : v) {cout << i << " ";} cout << endl;
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)

int N;
vector<int> a, l, r;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N;
  a.resize(N);
  l.resize(N);
  r.resize(N);
  FOR(i, 0, N) cin >> a[i];

  FOR(i, 1, N+1) {
    l[i] = 1;
    FOR(j, 1, i) {
      if (a[j] < a[i]) l[i] = max(l[i], l[j] + 1);
    }
  }

  reverse(a.begin(), a.end());

  FOR(i, 1, N+1) {
    r[i] = 1;
    FOR(j, 1, i) {
      if (a[j] > a[i]) r[i] = max(r[i], r[j] + 1);
    }
  }

  reverse(r.begin(), r.end());

  //for(auto&i:a) cout << i << " ";
  //cout << endl
  //pout(l);
  //pout(r);

  int ret = 0;
  FOR(i, 0, N) {
    ret = max(ret, l[i] + r[i] - 1);
  } 

  cout << N - ret;

  return 0;
}
