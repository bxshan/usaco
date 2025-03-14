#include <bits/stdc++.h>
using namespace std;

int N, cnt;
bool winner;

bool isprime(int n) {
    if (n == 0) return false;

    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> cnt;
        vector<int> b(cnt);

        for (int j = 0; j < cnt; j++) {
            cin >> b[j];
        }

        // for (int j = 0; j < b.size(); j++) {
        //     cout << b[j] << " ";
        // }
        // cout << endl;

        bool found = false;
        int j = 0;
        while (!found) {
            if (isprime(b[j])) {
                winner = true;
                found = true;
            } else if (b[j] == 0) {
                winner = false;
                found = true;
            } else if (b[j] % 4 == 0) {
                b[j] = 0;
            } else {
                b[j] = 2;
            }
            j = (j + 1) % b.size();
        }

        if (winner) {
            cout << "Farmer John\n";
        } else {
            cout << "Farmer Nhoj\n";
        }
    }

    return 0;
}