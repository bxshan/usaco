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

struct Node {
  int id, depth, children, parent;

  Node() {
    id = 0;
    depth = 0;
    children = 0;
    parent = -1;
  }

  Node(int i, int d, int c, int p) {
    id = i;
    depth = d;
    children = c;
    parent = p;
  }
};

int N;
vector<Node> w;

int solve(int curr) {
  Node n = w[curr];
  Node p = n;

  while (p.children == 0 && p.id != 0) {
    w[p.parent].children--;
    p = w[p.parent];
  } 

  int ans = p.depth;

  if (p.children > 0) ans++;

  return ans;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N;
  w.resize(N+1);
  w[0] = Node();

  int tmp;
  FOR(i, 1, N+1) {
    int pfx;
    cin >> pfx;
    w[i] = Node(i, w[pfx].depth + 1, 0, pfx);
    w[pfx].children++;
  }

  //-------------------------------------
  //for(Node&n:w) {
  //  cout << n.id << " " << n.depth << " " << n.children << " " << n.parent << endl;
  //}

  int M = 0;
  for(Node n : w) {
    if (n.children == 0) M++;
  }

  FOR(i, 0, M-1) {
    int curr;
    cin >> curr;

    cout << solve(curr) << endl;
  }

  cout << "0\n";

  return 0;
}
