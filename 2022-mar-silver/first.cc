#include <bits/stdc++.h>
using namespace std;

int N, ans;
vector<pair<int, int>> cows;

bool sortsecond(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.second < b.second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cows.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i].first >> cows[i].second;
    }

    sort(cows.begin(), cows.end(), sortsecond);

    for (int i = 1; i < N; i++) {
        ans += cows[i].second;
    }

    cout << ans;
}
