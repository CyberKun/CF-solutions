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
        vector<char> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        stack<ll> st;
        for(int i = 0 ; i < n ; i++) {
            if(vec[i] == '*') continue;
            if(st.empty()) st.push(vec[i]);
            else if(st.top() == vec[i]) st.pop();
            else st.push(vec[i]);
        }

        if(st.empty()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
