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
        vector<double> c(n) , p(n);
        for (int i = 0; i < n; i++) cin >> c[i] >> p[i];
        vector<double>suf(n + 1 , 0.0);
        for(int i = n - 1 ; i >= 0 ; i--) {
            double inc = (c[i] + (1 - p[i] / 100.0) * suf[i + 1]);
            double dec = suf[i + 1];
            if(inc > dec) suf[i] = inc;
            else suf[i] = dec;
        }
        // double ans = 0.0 , s = 1.0;
        // for(int i = 0 ; i < n ; i++) {
        //  //   if(i != n - 1 ){
        //         double dec =(s *(p[i] / 100.0)* suf[i + 1]); 
        //         double inc = s * c[i];
        //         if(inc > dec) {
        //             ans += inc;
        //             s = s * (1 - p[i] / 100.0);
        //         }
        //     // }
        //     // else ans += s * (1 - p[i] / 100.0) * c[i];
        // }
        cout << fixed << setprecision(10) <<  suf[0] << '\n';
    }
    return 0;
}
