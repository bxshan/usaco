// Silver
#include <bits/stdc++.h>
#include <utility>
using namespace std;
using ll = long long;
#define int long long
#define pb push_back
#define mp make_pair
#define endl '\n'
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define pout(v); for (auto i : v) {cout << i << " ";} cout << endl;
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)

int N, m;
char t;
vector<int> rpfx, ppfx, spfx;

int ffm(vector<int> v, int si, int ei) {
  if (si < 0) return 0;

  int maxi = 0, m = INT_MIN;

  FOR(i, si, ei) {
  //FOR(i, 0, v.size()) {
    if (v[i] > m) {
      maxi = i;
      m = v[i];
    }
  }

  return maxi;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  fileio("hps");

  cin >> N;
  m = INT_MIN;
  rpfx.resize(N+1); rpfx[0] = 0;
  ppfx.resize(N+1); ppfx[0] = 0;
  spfx.resize(N+1); spfx[0] = 0;
  FOR(i, 1, N+1) {
    cin >> t; 
    rpfx[i] = rpfx[i-1] + (t == 'H');
    ppfx[i] = ppfx[i-1] + (t == 'P');
    spfx[i] = spfx[i-1] + (t == 'S');
  }

  FOR(i, 1, N+1) {
    int before_wins = max(rpfx[i], max(ppfx[i], spfx[i]));
    int after_wins = max(
        {rpfx[N] - rpfx[i], ppfx[N] - ppfx[i], spfx[N] - spfx[i]});
    m = max(m, before_wins + after_wins);
  }

  //FOR(i, 0, 3) {
  //  // i == 0 r, 1 p, 2 s
  //  vector<int> curr = (i == 0) ? rpfx : (i == 1) ? ppfx : spfx;
  //  int maxi = ffm(curr, 0, curr.size());

  //  int othermax; 
  //  if (i == 0) {
  //    othermax = max(
  //        ppfx[N] - ppfx[maxi], 
  //        spfx[N] - spfx[maxi]
  //        );
  //  } else if (i == 1) {
  //    othermax = max(
  //        rpfx[N] - rpfx[maxi], 
  //        spfx[N] - spfx[maxi]
  //        );
  //  } else {
  //    othermax = max(
  //        rpfx[N] - rpfx[maxi], 
  //        ppfx[N] - ppfx[maxi]
  //        );
  //  }

  //  m = max(m, curr[maxi] + othermax);
  //}


  cout << m;

  return 0;
}
