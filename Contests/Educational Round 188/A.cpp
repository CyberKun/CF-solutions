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
        vector<bool> rcv(n , false);
        ll curr = 0;
        rcv[0] = true;
        for(int i = 0 ; i < n ; i++) {
            if(vec[curr] == 'R') {
                curr += 1;
            }
            else curr -= 1;
            rcv[curr] = true;
        }
        ll ct = 0;
        for(int i = 0 ; i < n ; i++) {
            if(rcv[i] == true) ct++;
        }
        cout << ct << '\n';
    }
    return 0;
}
