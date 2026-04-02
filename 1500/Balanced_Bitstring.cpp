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
        ll n , k;
        cin >> n >> k;
        string s;
        cin >> s;
        ll ct1 = 0 , ct0 = 0;

        bool psbl = true;
        for(int i = 0 ; i < k ; i++) {
            char c = s[i];
            for(int j = i + k ; j < n ; j += k) {
                if(c == '?') c = s[j];
                else if(s[j] != '?' && c != s[j]) {
                    psbl = false;
                    break;
                }
                s[i] = c;
            }
            if(!psbl) break;
        }

        for (int i = 0; i < k; i++) {
            if (s[i] == '0') ct0++;
            else if (s[i] == '1') ct1++;
        }
        if (max(ct0, ct1) > k / 2 || (!psbl)) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
