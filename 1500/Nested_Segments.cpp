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
    for(int i = 0 ; i < n ; i++) {
        ll u , v;
        cin >> u >> v;
        vec[i] = {u,v};
    }
    vector<pair<ll,ll>>num = vec;
    sort(vec.begin(), vec.end(), [](const pair<int, int> &a, const pair<int, int> &b){
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    });
    struct cmp{
        bool operator()(const pair<ll, ll> &a, const pair<ll, ll> &b) const{
            if (a.second == b.second) return a.first < b.first; 
            return a.second > b.second;   
        }
    };

    for(int i = 0 ; i < n-1 ; i++) {
        if(vec[i] == vec[i+1]) {
            ll a = -1, b;
            for(int j = 0 ; j < n ; j++) {
                if(num[j] == vec[i] && a == -1) a = j+1;
                else if(num[j] == vec[i]) {
                    b = j+1;
                    break;
                }
            }
            cout << a << ' ' << b << '\n';
            return 0;
        }
    }

    set<pair<ll, ll>, cmp> st;
    st.insert(vec[0]);
    // cout << vec[0].first << ' ' << vec[0].second << '\n';
    bool found = false;
    pair<ll,ll> p1 = {-1,-1} , p2 = p1;
    for(int i = 1 ; i < n ; i++) {
        auto it = st.begin();
        if(it->second >= vec[i].second) {
            found = true;
            p1 = *it;
            p2 = vec[i];
            break;
        }
        st.insert(vec[i]);
    }
    if(found) {
        int a =-1, b = -1;
        for(int i = 0 ; i < n ; i++) {
            if(num[i] == p2) b = i+1;
            if (num[i] == p1) a = i + 1;
        }
        cout << b << ' ' << a << '\n';
    }
    else cout << -1 << ' ' << -1 << '\n';
    return 0;
}
