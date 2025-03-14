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

int N, K;
vector<int> c, diff;

bool check(int r, vector<int> diff) {
  int k = 1;
  r *= 2;
  int range = r;

  FOR(i, 0, N) {
    if (range < diff[i]) {
      //cout << "breakpoint @ " << i << ", " << diff[i] << endl;
      k++;
      range = r;
    } else {
      //cout << "including @ " << i << ", " << diff[i] << endl;
      range -= diff[i];
    }
  }
  //cout << "ends w/ " << range << " " << k << endl;

  return k <= K;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  fileio("angry");

  cin >> N >> K;
  diff.resize(N);
  FOR(i, 0, N) {
    int x; cin >> x;
    c.pb(x);
  }
  sort(c.begin(), c.end());

  FOR(i, 1, N) diff[i] = c[i] - c[i-1];

  int l = 0, r = N, m, ans = r;
  while (l <= r) {
    m = (l+r) / 2;
    //cout << l << " " << m << " " << r << endl;

    //if (c(mid)) {
    //  ans = mid; 
    //  r = mid-1;
    //} else {
    //  l = mid+1;
    //}

    if (check(m, diff)) {
      ans = m;
      r = m-1;
    } else {
      l = m+1;
    }
  }

  cout << ans;

  //cout << "!!!";

  //cout << check(1, diff);
  //cout << "\n\n-------------------\n\n";
  //cout << check(5, diff);

  return 0;
}
