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

int N;
vector<vector<int>> t;

void preorder(int n) {
  if (n == -1) return;
  cout << n << " ";
  n--;

  preorder(t[n][0]);
  preorder(t[n][1]);
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N;
  t.resize(N);
  FOR(i, 0, N) {
    t[i].resize(2);
    cin >> t[i][0] >> t[i][1];
  }

  preorder(1);

  return 0;
}
