#include <bits/stdc++.h>
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

struct node {
  int v;
  node* l;
  node* r;
  node() : v(-1), l(nullptr), r(nullptr) {};
  node(int x) : v(x), l(nullptr), r(nullptr) {};
};

int N;
node tree[101];

void inorderTraversal(node *n) {
  if (n == nullptr) return; 
  inorderTraversal(n->l);  
  cout << n->v << " ";    
  inorderTraversal(n->r);
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> N;
  FOR(i, 1, N+1) {
    tree[i] = node(i);  
    int a, b; 
    cin >> a >> b; 
    if (a != -1) tree[i].l = &tree[a]; 
    if (b != -1) tree[i].r = &tree[b];
  }

  inorderTraversal(&tree[1]);  

  return 0;
}

