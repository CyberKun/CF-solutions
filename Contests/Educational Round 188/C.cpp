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

ll lcm(ll x, ll y, ll m) {
    if (x == 0 || y == 0)
        return 0;
    ll g = __gcd(x, y);
    ll temp = x / g;
    if (m / temp < y)
        return m + 1; 
    return temp * y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        ll a , b , c , m;
        cin >> a >> b >> c >> m;
        ll alc = (6 * (m / a)) - (3 *( m / (lcm(a , b , m)))) - (3 *( m / (lcm(a , c , m)))) + (2 * (m / (lcm(lcm(a , b , m) , c , m))));
        ll bob = (6 * (m / b)) - (3 *( m / (lcm(a , b , m)))) - (3 * (m / (lcm(b , c , m)))) + (2 * (m / (lcm(lcm(a , b , m) , c , m))));
        ll crl = (6 * (m / c)) - (3 *( m / (lcm(c , b , m)))) - (3 * (m / (lcm(a , c , m)))) + (2 * (m / (lcm(lcm(a , b , m) , c , m))));
        cout << alc << ' ' << bob << ' ' << crl << '\n';
    }
    return 0;
}
