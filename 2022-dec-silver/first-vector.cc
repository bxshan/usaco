#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> h;
    h.reserve(N);
    long long total_val = 0;
    long long tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        h[i] = tmp;
        total_val += tmp;
    }
    long long final_val = total_val / N;
    vector<set<int> > b;
    b.reserve(N);
    int n1, n2;
    for (int i = 0; i < N - 1; i++) {
        cin >> n1 >> n2;
        b[n2 - 1].insert(n1 - 1);
        b[n1 - 1].insert(n2 - 1);
    }

    int i = 0, cnt = 0, mv = 0;
    vector<long long> ans;

    while (cnt < N - 1) {
        if (b[i].size() == 1) {
            int target = *(b[i].begin());
            if (h[i] < final_val) {
                if (h[target] >= final_val - h[i]) {
                    ans.push_back(target + 1);
                    ans.push_back(i + 1);
                    ans.push_back(final_val - h[i]);

                    h[target] -= (final_val - h[i]);
                    h[i] = final_val;
                    // for (int j = 0; j < b[target].size(); j++) {
                    //     if (b[target][j] == i) {
                    //         b[target].erase(b[target].begin() + j);
                    //         break;
                    //     }
                    // }
                    // remove(b[target].begin(), b[target].end(), i);
                    b[target].erase(i);
                    b[i].clear();
                    cnt++;
                    mv++;
                }
            } else if (h[i] == final_val) {
                // for (int j = 0; j < b[target].size(); j++) {
                //     if (b[target][j] == i) {
                //         b[target].erase(b[target].begin() + j);
                //         break;
                //     }
                // }
                // remove(b[target].begin(), b[target].end(), i);
                b[target].erase(i);
                b[i].clear();
                cnt++;
            } else {
                ans.push_back(i + 1);
                ans.push_back(target + 1);
                ans.push_back(h[i] - final_val);

                h[target] += (h[i] - final_val);
                h[i] = final_val;
                // for (int j = 0; j < b[target].size(); j++) {
                //     if (b[target][j] == i) {
                //         b[target].erase(b[target].begin() + j);
                //         break;
                //     }
                // }
                // remove(b[target].begin(), b[target].end(), i);
                b[target].erase(i);
                b[i].clear();
                cnt++;
                mv++;
            }
        }
        i = (i + 1) % N;
    }

    /*for (int i = 0; i < N; i++) {
        for (int j = 0; j < b[i].size(); j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << mv << endl;

    for (int i = 0; i < ans.size(); i += 3) {
        cout << ans[i] << " " << ans[i + 1] << " " << ans[i + 2] << endl;
    }

    return 0;
}