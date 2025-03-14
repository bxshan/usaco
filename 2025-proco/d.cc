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

int N, K, M;
vector<vector<int>> e;

int eggs(vector<int> &a) {
  int prod = 0;
  FOR(i, 0, a.size()-1) {
    prod += e[a[i]][a[i+1]];
  }
  return prod;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N >> K >> M;

  vector<int> a(M);
  vector<int> dp(K+1, verysmall);
  e.resize(N);

  FOR(i, 0, M) {
    cin >> a[i];
    a[i]--; // 0 index
  }

  FOR(i, 0, N) {
    e[i].resize(N);
    FOR(j, 0, N) {
      cin >> e[i][j];
    }
  }

  dp[0] = eggs(a);

  FOR(i, 1, K+1) {
    FOR(j, 0, M) {
      vector<int> atmp = a;
      atmp.erase(atmp.begin()+j);
      dp[i] = max(dp[i], eggs(atmp));
    }
  }

  cout << *max_element(a.begin(), a.end()) << endl;

  //pout(a);
  //cout << endl;
  //for(auto&i:e) {
  //  pout(i);
  //}

  return 0;
}
