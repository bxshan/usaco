// Hoof, Paper, Scissors 694
#include <bits/stdc++.h>
#include <utility>
using namespace std;
using ll = long long;
//#define int long long
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

const int whydoihavetodothis = 1e5+5;
int dp[whydoihavetodothis][25][3];
int N, K;
vector<int> moves;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  fileio("hps");

  cin >> N >> K;
  moves.resize(N);

  FOR(i, 0, N) {
    char in;
    cin >> in;
    if (in == 'H') moves[i] = 0;
    else if (in == 'P') moves[i] = 1;
    else moves[i] = 2;
  }

  //cout << N << " " << K << endl;
  //pout(moves);


  // 3d dp of [curr # of games][# switches][curr item]
  


  FOR(g, 0, N) {
    FOR(s, 0, K+1) {
      FOR(i, 0, 3) {
        //if (win(i, moves[g])) dp[g][s][i]++;
        if (i == (moves[g]+1)%3) dp[g][s][i]++;

        dp[g+1][s+1][0] = max(dp[g][s][i], dp[g+1][s+1][0]);
        dp[g+1][s+1][1] = max(dp[g][s][i], dp[g+1][s+1][1]);
        dp[g+1][s+1][2] = max(dp[g][s][i], dp[g+1][s+1][2]);
        dp[g+1][s][i] = max(dp[g][s][i], dp[g+1][s][i]);
        
        //dp[g+1][s+1][i] = max(dp[g][s][i], dp[g+1][s+1][0]);
        //dp[g+1][s+1][i] = max(dp[g][s][i], dp[g+1][s+1][1]);
        //dp[g+1][s+1][i] = max(dp[g][s][i], dp[g+1][s+1][2]);
        //dp[g+1][s][i] = max(dp[g][s][i], dp[g+1][s][i]);
      }
    }
  }

  
  //pout(moves);
  //cout << N;
  
  int ret = -1;

  FOR(i, 0, 3) {
    ret = max(ret, dp[N-1][K][i]);
  }

  cout << ret << endl;

  //for(auto&i:dp){
  //  for(auto&j:i) {
  //    for(auto&k:j){
  //      cout << k;
  //    }
  //    cout << endl;
  //  }
  //  cout << endl;
  //}

  return 0;
}
