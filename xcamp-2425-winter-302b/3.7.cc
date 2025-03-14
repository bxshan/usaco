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

node* newNode(int v) {
    node* n = new node();
    n->v = v;
    n->l = n->r = nullptr;
    return n;
}

int Q;
node* root = nullptr;
vector<pair<int, int>> q;

void inorderTraversal(node *n) {
  if (n == nullptr) return; 
  inorderTraversal(n->l);  
  cout << n->v << " ";    
  inorderTraversal(n->r);
}

node* insert(node* root, int x){
  if (root == nullptr) return newNode(x);

  if (x < root->v){
    root->l = insert(root->l, x);
  } else {
    root->r = insert(root->r, x);
  }

  return root;
}

node* leftmost(node* root) {
  if (root == nullptr) return nullptr;
  else if (root->l == nullptr) return root;
  else return leftmost(root->l);
}

node* rightmost(node* root) {
  if (root == nullptr) return nullptr;
  else if (root->r == nullptr) return root;
  else return rightmost(root->r);
}

node* predSucc(node *root, int x, bool which) {
  node *curr = root;
  node *ret = nullptr;

  while (curr != nullptr) {
    if (curr->v < x) {
      if (!which) ret = curr;
      curr = curr->r;
    } else if (curr->v > x) {
      if (which) ret = curr;
      curr = curr->l;
    } else {
      if (!which) {
        if (curr->l != nullptr) ret = rightmost(curr->l);
      } else {
        if (curr->r != nullptr) ret = leftmost(curr->r);
      }
      break;
    }
  }

  return ret;
}

void solve() {
  int opt, x; cin >> opt >> x;

  switch (opt) {
    case 1:
      root = insert(root, x);
      break;
    case 5: 
      cout << predSucc(root, x, 0)->v << endl;
      break;
    case 6:
      cout << predSucc(root, x, 1)->v << endl;
      break;
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> Q;
  //while (Q--) solve();

  root=insert(root, 15);
  root=insert(root, 13);
  root=insert(root, 17);
  root=insert(root, 11);
  root=insert(root, 14);
  root=insert(root, 16);
  root=insert(root, 18);

  cout << predSucc(root, 11, 1)->v;

  return 0;
}

