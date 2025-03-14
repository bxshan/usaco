#include <bits/stdc++.h>
using namespace std;

string s_temp, t_temp, q_temp;
int Q;
vector<char> s_fin;
vector<char> t_fin;
bool same = true;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s_temp >> t_temp;
    vector<char> s(s_temp.begin(), s_temp.end());
    vector<char> t(t_temp.begin(), t_temp.end());
    cin >> Q;
    set<char> L[Q];
    for (int i = 0; i < Q; i++) {
        cin >> q_temp;
        for (char x : q_temp) {
            L[i].insert(x);
        }
    }

    for (int i = 0; i < Q; i++) {
        int ps = 0, pt = 0;
        while (ps < s.size() && pt < t.size()) {
            while (ps < s.size() && L[i].find(s[ps]) == L[i].end()) ps++;
            while (pt < t.size() && L[i].find(t[pt]) == L[i].end()) pt++;

            if (s[ps] != t[pt]) same = false;
            ps++;
            pt++;
        }

        if (same) {
            cout << "Y";
        } else {
            cout << "N";
        }

        same = true;
    }

    return 0;
}
