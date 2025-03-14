//BeginCodeSnip{C++ Short Template}
#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
//EndCodeSnip

const int MX = 1e5 + 5;

int dp[MX][25][3];  // dp[i][j][k] is the largest number of games she wins at

int main() {
	//setIO("hps");

	int N, K;

	cin >> N >> K;

                      // games i with switches j with current item k
  vector<int> moves;
  moves.resize(N);

	for (int i = 0; i < N; i++) {
		char a;
		cin >> a;
		if (a == 'H') moves[i] = 0;
		if (a == 'P') moves[i] = 1;
		if (a == 'S') moves[i] = 2;
  }

  cout << N << " " << K << endl;
  for(auto&i:moves) {
    cout << i << " ";
  }
  cout << endl;

  //
  //for(auto&i:moves) {
  //  cout << i << " ";
  //}
  //cout << endl << N;


  // either she switches to h or p or s or stays

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= K; j++) {
			for (int k = 0; k < 3; k++) {

        // If current strategy matches opponent's move, increment win count
        if (k == moves[i]) dp[i][j][k]++;

        dp[i+1][j+1][0] = max(dp[i+1][j+1][0], dp[i][j][k]);  // switch to hoof
        dp[i+1][j+1][1] = max(dp[i+1][j+1][1], dp[i][j][k]);  // switch to paper
        dp[i+1][j+1][2] = max(dp[i+1][j+1][2], dp[i][j][k]);  // switch to scissors
        dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);  // stay
			}
		}
	}

	int ret = 0;

	for (int i = 0; i < 3; i++) { ret = max(ret, dp[N - 1][K][i]); }

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
}
