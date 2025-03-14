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
#define pout(v); for (auto i : v) {cout << i << " ";} cout << endl;
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)

int Q, hs;
vector<int> h;

void swp(int a, int b) {
  int tmp = h[a];
  h[a] = h[b];
  h[b] = tmp;
}


void heapifyUp(int n) {
  int p = (n-1)/2;

  if (h[n] < h[p]) {
    swp(n, p);
    heapifyUp(p);
  }
}

void heapifyDown(int n) {
  int l = (2*n+1 < hs && h[2*n+1] != verybig) ? h[2*n+1] : verybig;
  int r = (2*n+2 < hs && h[2*n+2] != verybig) ? h[2*n+2] : verybig;

  if (h[n] == verybig || l > h[n] && r > h[n]) {
    return; 
  }

  if (l < r) {
    h[2*n+1] = h[n];
    h[n] = l;
    heapifyDown(2*n+1);
  } else {
    h[2*n+2] = h[n];
    h[n] = r;
    heapifyDown(2*n+2);
  }
}

void insert(int x) {
  hs++;
  h.pb(x);
  heapifyUp(hs-1);
}

int remove() {
  int ret = h[0];
  hs--;
  h[0] = h[hs];
  //h[hs] = verybig;
  h.erase(h.begin()+hs);
  heapifyDown(0);
  return ret;
}

void solve() {
  int op; cin >> op;
  switch (op) {
    case 1:
      int x; cin >> x;
      insert(x);
      break;
    case 2:
      cout << h[0] << endl;
      break;
    case 3:
      remove();
      break;
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> Q;
  while (Q--) {
    solve();
  }

  return 0;
}
