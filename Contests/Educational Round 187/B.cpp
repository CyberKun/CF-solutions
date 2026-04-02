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
        ll x;
        cin >> x;
        // cout << x << '\n';
        vector<ll> vec;
        while(x) {
            vec.push_back(x%10);
            x /= 10;
        }
        ll ac = vec[vec.size() - 1];
        sort(vec.begin() , vec.end());
        ll nu = accumulate(vec.begin(), vec.end(), 0ll);

         if (nu <= 9){
            cout << 0 << '\n';
            continue;
        }

        ll ct = 0 , sm = 0;
        for(int i = 0 ; i < vec.size() ; i++) {
            ct = i;
            if(sm + vec[i] > 9) {
                if(vec[i- 1] < ac && sm == 9) ct--;
                break;
            }
            sm += vec[i];
        }
        cout << vec.size() - ct << '\n';
    }
    return 0;
}
