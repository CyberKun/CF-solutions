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

    ll n;
    cin >> n;
    vector<pair<ll,ll>>vec(n);
    for(int i = 0 ; i < n ; i++) cin >> vec[i].first >> vec[i].second;
    bool psbl = true;
    sort(vec.begin(), vec.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b){
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second; });

    ll a = -1 , b = -1;
    for(int i = 0 ; i < n ; i++) {
        if(vec[i].first > a) {
            a = vec[i].second;
        }
        else if(vec[i].first > b) {
            b = vec[i].second;
        }
        else {
            psbl = false;
            break;
        }
    }  
    if(psbl) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    return 0;
}
