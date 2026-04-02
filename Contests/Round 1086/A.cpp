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
        ll arr[n][n];
        map<ll, ll> fq;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                cin >> arr[i][j];
                fq[arr[i][j]]++;
            }
        }
        ll ct = 0;
        ll maxy = fq[1] , scdmaxy = fq[2];
        for(int i = 1 ; i <= n*n ; i++) {
            if(fq[i] > 0) ct++;
            maxy = max(maxy , fq[i]);
        }
        if(maxy <= (n*n - (n))) cout << "YES" << '\n';
        else cout << "NO" << '\n';
       
    }
    return 0;
}
