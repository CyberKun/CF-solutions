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

vector<int> getFirstNPrimes(int n) {
    vector<int> primes;
    primes.reserve(n);
    int num = 2;
    while (primes.size() < n) {
        bool isPrime = true;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) { isPrime = false; break; }
        }
        if (isPrime) primes.push_back(num);
        num++;
    }
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> primes = getFirstNPrimes(10005);

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        cout << 1 << ' ';
        for(int i = 0 ; i < n-1 ; i++) cout << primes[i]*primes[i+1] << ' ';
        cout << '\n';
    }
    return 0;
}
