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
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    vector<ll>cnts;
    ll ct = 0,act = 0;
    for(int i = 0 ; i < s.size() ; i++) {
        if(s[i] == 'a') {
            act++;
            ct++;
        }
        else if(s[i] == 'b' && ct) {
            cnts.push_back(ct);
            ct = 0;
        }
    }
    cnts.push_back(ct);
    ll ans = 1;
    if(cnts.size() > 1){
        for(int i = cnts.size()-1 ; i >= 0; i--) ans = (ans*(cnts[i] + 1))%MOD;
        ans = (ans - 1 + MOD)%MOD;
    }
    else ans  = act;
    cout << ans << '\n';
    return 0;
}
