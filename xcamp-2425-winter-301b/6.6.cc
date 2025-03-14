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
#define pout(v); for (auto i : v) {cout << i << "\t";} cout << endl;
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)

int N, M, K, L;
vector<vector<int>> dp;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N >> M >> K >> L;

  dp.resize(N+1);
  FOR(i, 0, N+1) {
    dp[i].resize(M+1);
    //if (i) fill(dp[i].begin()+1, dp[i].end(), -1);
    fill(dp[i].begin(), dp[i].end(), -1);
  }

  int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
  int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
  FOR(i, 0, 8) {
    if (dx[i] + K > -1 && dx[i] + K < N && 
        dy[i] + L > -1 && dy[i] + L < M) {
      dp[dx[i] + K][dy[i] + L] = 0;
    }
  }

  int alksdaslkdf = 1;
  FOR(i, 0, N+1) {
    if (dp[0][i] == 0) alksdaslkdf = 0;
    dp[0][i] = alksdaslkdf;
  }

  alksdaslkdf = 1;
  FOR(i, 0, N+1) {
    if (dp[i][0] == 0) alksdaslkdf = 0;
    dp[i][0] = alksdaslkdf;
  }

  for(auto&i:dp) {
    pout(i);
  }
  cout << endl;
  cout << endl;

  FOR(i, 1, N+1) {
    FOR(j, 1, M+1) {
      if(dp[i][j] != 0) {
        //cout << i << " " << j << " " << dp[i][j] << " " << dp[i-1][j] << " " << dp[i][j-1]; 
        dp[i][j] = dp[i-1][j] + dp[i][j-1]; 
        //cout << " " << dp[i][j] << endl;
      }
    }
  }

  for(auto&i:dp) {
    pout(i);
  }

  return 0;
}
