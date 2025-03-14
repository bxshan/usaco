#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;
  vector<int> flowers(n);
  for(int i = 0; i < n; i++){
    cin >> flowers[i];
  }
  vector<int> add(x);
  for(int i = 0; i < x - 1; i++){
    add[i] = flowers[i];
  }
  copy(add.begin(), add.end(), back_inserter(flowers));
  int dum = 0;
  int lum = 0;
  for(int i = 0; i < n + x - 1; i++){
    dum = 0;
    lum = 0;
    for(int j = 0; j < x; j++){
      dum += flowers[j];
      if(dum > lum){
        lum = dum;
      }
    }
  }
  cout << lum << endl;
}
