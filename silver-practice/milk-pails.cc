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

int A, B, K, M, ans;
bool v[101][101][101];

void ff(int a, int b, int k) {
  if (v[a][b][k] || k > K || a > A || b > B) return;
  v[a][b][k] = 1;

  ans = min(ans, abs(M-(a+b)));

  // case 1
  ff(A, b, k+1);
  ff(a, B, k+1);

  // case 2
  ff(0, b, k+1);
  ff(a, 0, k+1);

  // case 3

  // wrong logic
//  int aa = A-a<b ? A : b;
//  int ab = A-a<b ? b-A+a : 0;
//
//  int ba = B-b<a ? B : a;
//  int bb = B-b<a ? a-B+b : 0;
//
//  ff(aa, ab, k+1);
//  ff(ba, bb, k+1);

  // correct logic from USACO guide internal solution
  int leftoverX = (a + b > B ? a + b - B : 0);
	int leftoverY = (b + a > A ? b + a - A : 0);

	ff(leftoverX, min(B, b + a), k + 1);
	ff(min(A, a + b), leftoverY, k + 1);
} 

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  fileio("pails");

  cin >> A >> B >> K >> M;
  ans = INT_MAX;

  ff(0, 0, 0);

  cout << ans;

  return 0;
}
