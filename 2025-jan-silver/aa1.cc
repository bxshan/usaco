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
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define pout(v); for (auto i : v) {cout << i << " ";} cout << endl;
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)

int N, S;
vector<int> a, b, cpfx;
vector<vector<int>> dp;

int check(int l, int r) {
  int cnt = 0;
  FOR(i, 0, l) cnt += (a[i] == b[i]);
  ROF(i, r, l-1) cnt += (a[i] == b[r+l-i]);
  FOR(i, r+1, N) cnt += (a[i] == b[i]);
  return cnt;
}

int p(int l, int r) {
  return ((a[l] == b[r])-(cpfx[r]-cpfx[r-1])) + ((a[r] == b[l])-(cpfx[l]-cpfx[l-1]));
}

int p1(int l, int r) {
  return (a[l] == b[r]) + (a[r] == b[l]);
}

int c(int l, int r) {
  return (cpfx[l] + cpfx[N] - cpfx[r+1]);
}

int rev(int l, int r) {
  if (l == r || r < l) {
    return S;
  } else if (r-l==1) {
    return p1(l, r) + c(l, r);
  } else {
    int cnt = 0;
    cout << "!!!" << l << " " << r << endl;
    FOR(i, 1, (r-l)/2+1) {
      cout << l+i << " " << r-i << endl;
      cnt += dp[l+i][r-i];
    }
    return cnt + p(l, r) + c(l, r);
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N;
  a.resize(N); b.resize(N); cpfx.resize(N+1); dp.resize(N);
  cpfx[0] = 0;
  FOR(i, 0, N) cin >> a[i];
  FOR(i, 0, N) cin >> b[i];
  FOR(i, 1, N+1) cpfx[i] += cpfx[i-1] + (a[i-1] == b[i-1]);
  S = cpfx[N];
  FOR(i, 0, N) {
    dp[i].resize(N);
    fill(dp[i].begin(), dp[i].end(), -1);
    dp[i][i] = S;
  }

  vector<pair<int, int>> order;
  FOR(i, 0, N) {
    FOR(j, 0, N-i) {
      order.pb(mp(j, j+i));
    }
  }

  //for(pair<int, int> &p : order) {
  //  cout << p.f << " " << p.s << endl;
  //}

  int ret = 0;
  for(pair<int, int> &p : order) {
    int l = p.f; int r = p.s;
    dp[l][r] = rev(l, r);
    ret += dp[l][r];
  }

  pout(cpfx);

  for(vector<int> &n : dp) {
    pout(n);
  }

  cout << endl << ret;

  return 0;
}
