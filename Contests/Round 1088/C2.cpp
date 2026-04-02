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
        ll n , k;
        cin >> n >> k;
        vector<ll> vec1(n) , vec2(n);
        for (int i = 0; i < n; i++) cin >> vec1[i];
        for (int i = 0; i < n; i++) cin >> vec2[i];
        bool mody = true;
        for(int i = 0 ; i < k ; i++) {
            for(int j = i+k ; j < n ; j += k) {
                if(vec1[j] != vec1[i]) {
                    mody = false;
                    break;
                }
            }
        }

        if(mody) {
            map<ll,ll> fq1;
            bool psbl = true;

            for(int i = 0 ; i < k ; i++) {
                ll v = vec2[i];
                for(int j = i+k ; j < n ; j += k) {
                    if(v == -1) v = vec2[j];
                    else if(vec2[j] != -1 && vec2[j] != v) {
                        psbl = false;
                        break;
                    }
                }
                if(!psbl) break;
                vec2[i] = v;
            }

            for(int i = 0 ; i < k ; i++) fq1[vec1[i]]++;
            for(int i = 0 ; i < k ; i++) {
                if(vec2[i] != -1) {
                    if(fq1[vec2[i]]) fq1[vec2[i]]--;
                    else {
                        psbl = false;
                        break;
                    }
                }
            }

            if(psbl) cout << "YES\n";
            else cout << "NO\n";
        }
        else {
            if (k == n) {
                cout << "YES" << '\n';
                continue;
            }

            int st = k - 1, ed = n - k;
            bool psbl = true;
            for (int i = 0; i < n; i++) {
                if (i >= ed && i <= st) continue;
                if (vec2[i] == -1) continue;
                if (vec1[i] != vec2[i]) {
                    psbl = false;
                    // cout << i << '\n';
                    break;
                }
            }

            map<ll, ll> fq;
            for (int i = ed; i <= st; i++) {
                fq[vec1[i]]++;
            }

            for (int i = ed; i <= st; i++) {
                if (vec2[i] != -1 && fq[vec2[i]] == 0) {
                    psbl = false;
                    break;
                }
            }

            if (psbl) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }

    }
    return 0;
}
