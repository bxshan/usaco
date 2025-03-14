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
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define pout(v); for (auto i : v) {cout << i << " ";} cout << endl;
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)

int N, e;
vector<vector<int>> tree;
vector<int> sub;

void fill(int begin) {
  if (tree[begin].size() == 0) return;
  for(auto& i : tree[begin]) {
    fill(i);
    sub[begin] += sub[i]+1;
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N;
  tree.resize(N);
  sub.resize(N);
  fill(sub.begin(), sub.end(), 0);

  FOR(i, 1, N) {
    cin >> e;
    tree[--e].pb(i);
  }

  fill(0);

  for(auto&i:sub) cout << i << " ";

  return 0;
}

