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
        bool done = false;
        for(int i = 1 ; i <= 2*n - 2 ; i+=2) {
            cout << '?' << ' ' << i << ' ' << i + 1 << endl;
            ll x;
            cin >> x;
            if(x == 1) {
                cout << '!' << ' ' << i << endl;
                done = true;
                break;
            }
        }
        if(!done) {
            cout << '?' << ' ' << 2*n - 1 << ' ' << 1 << endl;
            ll y;
            cin >> y;
            if(y == 1) {
                cout << '!' << ' ' << 1 << endl;
            }
            else {
                cout << '?' << ' ' << 2*n - 1 << ' ' << 2 << endl;
                ll z;
                cin >> z;
                if(z == 1) {
                    cout << '!' << ' ' << 2*n - 1 << endl;
                }
                else {
                    cout << '!' << ' ' << 2*n << endl;
                }
            }
        }
    }
    return 0;
}
