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
#define fileio(file) freopen(file ".in", "r", stdin); freopen(file ".out", "w", stdout)
#define pout(v); for (auto i : v) {cout << i << " ";} cout << endl;
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
#define ROF(i, n, m) for (int i = (n); i > (m); i--)

struct node {
  int value;
  node* left;
  node* right;
  node(int d): value(d) {};
} 

node tree[501];

node* insert(node* root, int target){
  // if the tree is empty
  if (!root) return new node(target);

  // where does target go?
  if (target <= root->value){
    root->left = insert(root->left, target);
  } else {
    //insert on the right
    root->right = insert(root->right, target);
  }

  return root;
}

void traverse(int root) {
  if (root == -1) {
    return;
  }
  traverse(tree[root].left);
  cout << tree[root].value << " ";
  traverse(tree[root].right);
}

node* find(node* root, int target) {
  if (root->value == target) return root;
  if (root->value == nullptr) return nullptr;
  if (target < root->value) find(root->left, target);
  else find(root->right, target);
}

node* findMax(node* t) {
  if (t->value == nullptr) return nullptr;
  return max(t->value, findMax(t->right));
}

node* delete(node* t, int x) {
  if (t.value == nullptr) {
    return t;
  } else if (x < t->value) {
    t->left = delete(t->left, x); 
  } else if (x > t->value) {
    t->right= delete(t->right, x); 
  } else { // found node to remove
    if (t->left != nullptr && t->right != nullptr) { // case 0: 2 child nodes
      node* tmp = find(root, findMax(root->left));
      t->value = tmp->value;
      t->left = delete(t->left, tmp->value);
    } else if (t.getLeft() == null) { // case 1: 1 child to right
      return t->right;
    } else if (t.getRight() == null) { // case 2: 1 child to left
      return t->left;
    } else { // case 3: leaf node
      return nullptr;
    }
  }
  return t;
}





signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  int stuff;
  cin >> stuff;
  tree[1] = {1, -1, -1};
  for (int a = 1; a < stuff+1; ++a) {
    int x, y;
    cin >> x >> y;
    tree[a].value = a;
    tree[a].left = x;
    tree[a].right = y;
  }
  traverse(1);

  return 0;
}
