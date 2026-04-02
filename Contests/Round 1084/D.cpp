/****************************************************
██████╗ ██████╗ ██╗   ██╗████████╗███████╗███╗   ██╗
██╔══██╗██╔══██╗██║   ██║╚══██╔══╝██╔════╝████╗  ██║
██████╔╝██████╔╝██║   ██║   ██║   █████╗  ██╔██╗ ██║
██╔══██╗██╔══██╗██║   ██║   ██║   ██╔══╝  ██║╚██╗██║
██████╔╝██║  ██║╚██████╔╝   ██║   ███████╗██║ ╚████║
╚═════╝ ╚═╝  ╚═╝ ╚═════╝    ╚═╝   ╚══════╝╚═╝  ╚═══╝
***************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int leastRotation(const vector<ll> &v) {
    int n = v.size();
    vector<ll> s(2 * n);
    for (int i = 0; i < n; i++) s[i] = s[i + n] = v[i];
    int i = 0, j = 1, k = 0;
    while (i < n && j < n && k < n) {
        if (s[i + k] == s[j + k]) k++;
        else if (s[i + k] > s[j + k]) {
            i = i + k + 1;
            if (i <= j) i = j + 1;
            k = 0;
        }
        else {
            j = j + k + 1;
            if (j <= i) j = i + 1;
            k = 0;
        }
    }
    return min(i, j);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        ll n , x , y;
        cin >> n >> x >> y;
        vector<ll> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        vector<ll> vec1 , vec2;
        for(int i = x ; i < y ; i++) vec1.push_back(vec[i]);
        for(int i = 0 ; i < x ; i++) vec2.push_back(vec[i]);
        for(int i = y ; i < n ; i++) vec2.push_back(vec[i]);

        int idx = leastRotation(vec1);
        vector<ll> ans(vec1.size());
        for (int i = 0; i < vec1.size(); i++) ans[i] = vec1[(idx + i) % vec1.size()];
        vector<ll> fin;
        int i = 0;
        if(ans.empty()) {
            for (int i = 0; i < n; i++) cout << vec[i] << ' ';
            cout << '\n';
            continue;
        }
        while(i < vec2.size()) {
            while(i < vec2.size() && vec2[i] <= ans[0]) {
                fin.push_back(vec2[i]);
                i++;
            }
            fin.insert(fin.end(), ans.begin(), ans.end());
            while(i < vec2.size()) {
                fin.push_back(vec2[i]);
                i++;
            }
        }

        if(fin.empty()) fin.insert(fin.end(), ans.begin(), ans.end());

        for(int i = 0 ; i < n ; i++) cout << fin[i] << ' ';
        cout << '\n';
    }
    return 0;
}
