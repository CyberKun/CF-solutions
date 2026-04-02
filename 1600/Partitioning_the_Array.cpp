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
        vector<ll> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }
        
        vector<ll> sizes;
        sizes.push_back(1);
        for(int i = 2 ; i*i<= n ; i++) {
            if(n % i == 0) {
                sizes.push_back(i);
                if(n/i != i) sizes.push_back(n/i);
            }
        }
        sort(sizes.begin() , sizes.end());
        ll ct = 1;
        for(int i = 0 ; i < sizes.size() ; i++) {
            ll mxgc = 0;
            bool psbl = true;
            for(int k = 0 ; k < sizes[i] ; k++) {
                ll gc = 0;
                for(int j = sizes[i] + k ; j < n ; j += sizes[i]) {
                    gc = __gcd(gc , abs(vec[j] - vec[j - sizes[i]]));
                }
                mxgc = __gcd(gc , mxgc);
            }
            if(mxgc != 1) ct++;
        }
        cout << ct << '\n';


    }
    return 0;
}
