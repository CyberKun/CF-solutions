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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        vector<pair<ll,ll>> vec(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i].first;
            vec[i].second = i + 1;        
        }
        sort(vec.begin() , vec.end());
        bool psbl = true;
        for(int i = 0 ; i < n ; i++) {
            if(vec[i].second > i + 1) {
                while(vec[i].second > i + 1 && vec[i].second % 2 == 0) vec[i].second = vec[i].second / 2;
            }
            else if (vec[i].second < i + 1) {
                while (vec[i].second < i + 1) vec[i].second = vec[i].second * 2;
            }
            if(vec[i].second != i + 1) {
                psbl = false;
                break;
            }
        }
        if (psbl)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}
