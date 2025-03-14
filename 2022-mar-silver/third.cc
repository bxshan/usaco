#include <bits/stdc++.h>
using namespace std;

string input;
int N;
vector<int> ps, pe;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> input >> N;
    ps.resize(N);
    pe.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> ps[i] >> pe[i];

        int c = 0, o = 0, w = 0;
        for (int j = ps[i] - 1; j <= pe[i] - 1; j++) {
            if (input[j] == 'C') c++;
            if (input[j] == 'O') o++;
            if (input[j] == 'W') w++;
        }
        c %= 2;
        o %= 2;
        w %= 2;
        if (c == 0 && o == 0 && w == 0) cout << "N";
        if (c == 0 && o == 0 && w == 1) cout << "N";
        if (c == 0 && o == 1 && w == 0) cout << "N";
        if (c == 0 && o == 1 && w == 1) cout << "Y";
        if (c == 1 && o == 0 && w == 0) cout << "Y";
        if (c == 1 && o == 0 && w == 1) cout << "N";
        if (c == 1 && o == 1 && w == 0) cout << "N";
        if (c == 1 && o == 1 && w == 1) cout << "N";
    }

    return 0;
}
