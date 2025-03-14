#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (auto&i:v) cin >> i;
    int maxn = *max_element(v.begin(), v.end()), minn = *min_element(v.begin(), v.end());
    cout << min(abs(maxn - x) + abs(maxn - minn), abs(x - minn) + abs(maxn - minn)) << '\n';
}
