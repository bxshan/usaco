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
vector<int> a;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N;
  a.resize(N);
  FOR(i, 0, N) cin >> a[i];
  rotate(a.begin(), find_if(a.begin(), a.end(), [](int i){return !i;}), a.end());

  int max = INT_MIN, cnt = 0, maxsx = -1, sx = -1;
  FOR(i, 0, N) {
    if (a[i]) {
      if (sx == -1) sx = i;
      cnt++;
    } else {
      if (cnt > max && sx != -1) {
        max = cnt;
        maxsx = sx;
      }
      cnt = 0;
      sx = -1;
    }
  }
  if (cnt > max) maxsx = sx;


  //pout(a);
  cout << maxsx;




  return 0;
}
