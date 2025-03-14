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

int N, pfx, ans;
vector<int> v;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N;
  v.resize(N); fill(v.begin(), v.end(), 0); v[0] = 1;
  pfx = 0, ans = 0;
  FOR(i, 1, N+1) {
    int t; cin >> t; 
    pfx += t;
    //v[pfx%N]++;
    v[(pfx % N + N) % N]++;
  }

  //pout(v);

  for(auto& i : v) {
    ans += ((i-1) * i)/2;
  }

  cout << ans;

  return 0;
}
