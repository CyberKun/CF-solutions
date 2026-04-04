#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--){
        ll x, y;
        cin >> x >> y;
        if (x > y || (x == 0 && (y % 2 == 0))){
            cout << "NO" << '\n';
            continue;
        }

        cout << "YES" << '\n';
        if (x == 0){
            for (int i = 2; i <= y; i++)
                cout << 1 << ' ' << i << '\n';
            continue;
        }
        if (x == y){
            for (int i = 1; i < x + y; i++)
                cout << i << ' ' << i + 1 << '\n';
            continue;
        }

        if ((y - x) % 2 == 1){
            ll sex = 2 * x + 1;
            for (ll i = 1; i < sex; i++)
                cout << i << ' ' << i + 1 << '\n';
            for (ll i = 1; i <= y - x - 1; i++)
                cout << sex << ' ' << sex + i << '\n';
            continue;
        }

        vector<pair<ll, ll>> vec;
        for (int i = 1; i < (x + y); i++){
            vec.push_back({i, i + 1});
        }
        ll n = (y - x) / 2;
        int i = vec.size() - 1;
        vector<ll> num;
        ll ct = 1;
        while (ct <= n){
            num.push_back(vec[i].second);
            i--;
            ct++;
        }
        for (int i = 1; i <= n; i++){
            vec[vec.size() - n + i - 1] = {vec[i].first, num[i - 1]};
        }
        for (int i = 0; i < (x + y) - 1; i++) cout << vec[i].first << ' ' << vec[i].second << '\n';
    }
    return 0;
}