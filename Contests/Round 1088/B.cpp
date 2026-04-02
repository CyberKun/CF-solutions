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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        vector<ll> vec;
        for (int i = 0; i < x; i++)
            vec.push_back(1);
        for (int i = 0; i < y; i++)
            vec.push_back(-1);
        // vector<ll> pref(x+y) , suf(x+y);
        // pref[0] = vec[0];
        // for(int i = 1 ; i < x+y ; i++) pref[i] = pref[i-1] + vec[1];
        // suf[(x+y)-1] = vec[abs(x+y)-1];
        // for(int i = x+y-2 ; i >= 0 ; i++) suf[i] = suf[i+1] + vec[i];
        ll num = abs(x - y);
        ll a = 1;
        for (int i = 2; i <= abs(x - y); i++)
        {
            if (num % i == 0)
                a++;
        }
        cout << a << '\n';
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << ' ';
        cout << '\n';
        // if(x != 0 || y != 0) {

        // }
    }
    return 0;
}
