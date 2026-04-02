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

map<ll , ll> fq;

vector<ll> generate(vector<ll> &a) {
    int n = a.size();
    vector<ll> sms;

    for (int mask = 0; mask < (1 << n); mask++) {
        ll sum = 0;
        ll cnt = (ll)__builtin_popcountll(mask); 

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) sum += a[i];
        }

        if (fq.find(sum) == fq.end()) {
            fq[sum] = cnt;
            sms.push_back(sum);
        }
        else fq[sum] = min((ll)fq[sum], cnt);
    }
    return sms;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    vector<ll> vec;
    ll nm = 2;
    for(int i = 3 ; i <= 14 ; i++) {
        nm *= i;
        vec.push_back(nm);
    }
    vector<ll> sms = generate(vec);

    while (t--) {
        ll n;
        cin >> n;
        ll ans = __builtin_popcountll(n);
        for(int i = 0 ; i < sms.size() ; i++) {
            if(sms[i] <= n) ans = min(ans , (ll)(__builtin_popcountll(n - sms[i]) + fq[sms[i]]));
        }
        cout << ans << '\n';
    }
    return 0;
}
