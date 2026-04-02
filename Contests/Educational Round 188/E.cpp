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

    ll t = 1;
    // cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        vector<ll> vec(n) , num(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        for (int i = 0; i < n; i++) cin >> num[i];
        vector<bool> done(n , false);
        int j = 0;
        ll ct = 0;
        for(int i = 0 ; i < n ; i++) {
            if(num[i] == vec[j]) {
                done[vec[j]] = true;
                while(j < n && done[vec[j]] == true) j++;
            }
            else {
                ct++;
                done[num[i]] = true;
            }
        }
        cout << ct << '\n';
    }
    return 0;
}
