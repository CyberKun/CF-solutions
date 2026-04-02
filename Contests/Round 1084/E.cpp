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

const int N = 1e6;
int spf[N + 1];

void buildSPF() {
    for (int i = 1; i <= N; i++) spf[i] = i;

    for (int i = 2; i * i <= N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= N; j += i){
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

bool hasAtLeastTwoPrimeDivisors(int x) {
    int count = 0;

    while (x > 1) {
        int prime = spf[x];
        count++;

        while (x % prime == 0)
            x /= prime;

        if (count >= 2)
            return true;
    }

    return false;
}

pair<int, int> getMinMaxPrime(int x)
{
    int minPrime = spf[x]; 
    int maxPrime = spf[x];

    while (x > 1)
    {
        int p = spf[x];
        maxPrime = p; 

        while (x % p == 0)
            x /= p;
    }

    return {minPrime, maxPrime};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    buildSPF();

    while (t--) {
        ll n;
        cin >> n;
        vector<ll> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        bool psbl = false;
        vector<ll> srtd = vec;
        sort(srtd.begin() , srtd.end());
        if(srtd == vec) {
            cout << "Bob" << '\n';
            continue;
        }

        vector<pair<ll,ll>> mnmx;
        
        for(int i = 0 ; i < n ; i++) {
            mnmx.push_back(getMinMaxPrime(vec[i]));
            if (hasAtLeastTwoPrimeDivisors(vec[i])) {
                psbl = true;
                break;
            }
        }

        for(int i = 0 ; i < mnmx.size() - 1 ; i++) {
            if(mnmx[i].second > mnmx[i + 1].first) {
                psbl = true;
                break;
            }
        }
        
        if(psbl) cout << "Alice" << '\n';
        else cout << "Bob" << '\n';
    }
    return 0;
}
