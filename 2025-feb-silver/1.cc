#include <bits/stdc++.h>
#include <utility>
#include <algorithm>
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

int Q;

//void preprocess(vector<int> &a, int strt, int end) {
//  //cout << strt << " " << end << endl;
//  if (strt == end) return;
//
//  int loc = distance(a.begin(), max_element(a.begin() + strt, a.begin() + end));
//  if (loc == strt) {
//    preprocess(a, loc+1, end);
//  } else {
//    int move = a[loc];
//    a.erase(a.begin() + loc);
//    a.insert(a.begin() + strt, move);
//  }
//}

void solve() {
  int N;
  vector<int> a, b, pfx;
  vector<vector<int>> v;
  cin >> N;
  v.resize(N+1);
  a.resize(N);
  pfx.resize(N);

  FOR(i, 0, N) {
    cin >> a[i];
    v[a[i]].pb(i);
  }

  FOR(i, 0, N) {
    ROF(j, i-1, -1) {
      if (a[j] >= a[i]) {
        pfx[i] = j;
        break;
      }
      pfx[i] = -1;
    }
  }
  pfx[0] = -1;

  //cout << "!!!!!!!!!!!!\n";
  //pout(pfx);
  //cout << "!!!!!!!!!!!!\n";

  //for(auto&i:v) {
  //  pout(i);
  //}

  bool moved = 0;
  ROF(k, N, 0) {
    if (v[k].empty()) continue;
    //cout << "---\n";
    //cout << k << "\n";
    //cout << "!!!\n";
    //pout(v[k]);
    //cout << "---\n";

    if (moved) break;
    for(int i : v[k]) {
      //cout << "=-=-=-=\n";
      //cout << i << endl;
      ////pout(v[k]);
      //cout << "=-=-=-=\n";

      int ll = pfx[i] + 1;
      int lr = i;
      int rl = i + 1;
      int rr = N;

      if (ll == lr) {
        continue;
      } 

      int lmax = *max_element(a.begin() + ll, a.begin() + lr);
      int rmax;
      if (rl == rr) {
        rmax = 0;
      } else {
        rmax = *max_element(a.begin() + rl, a.begin() + rr);
      }

      //cout << "+++++++++++++++++++++++\n";
      //cout << ll << " " << lr << " | " << rl << " " << rr << endl; 
      //cout << lmax << " " << rmax << endl;
      //cout << "+++++++++++++++++++++++\n";

      if(lmax >= rmax) {
        //cout << i << endl;
        int move = a[i];
        a.erase(a.begin() + i);
        a.insert(a.begin() + ll, move);
        moved = 1;
        break;
      }
    }
  }
  
  //preprocess(a, 0, N);

  int loc = distance(a.begin(), max_element(a.begin(), a.end()));
  while(loc != N) {
    //cout << "````````````````````\n";
    //cout << loc << " " << a[loc] << endl;
    //cout << "````````````````````\n";
    b.pb(a[loc]);
    loc = distance(a.begin(), max_element(a.begin() + loc + 1, a.end()));
  }
  //b.pb(a[loc]);

  FOR(i, 0, b.size()) {
    if (i == b.size()-1) {
      cout << b[i];
    } else {
      cout << b[i] << " ";
    }
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> Q;
  while(Q--) {
    solve();
  }

  return 0;
}
