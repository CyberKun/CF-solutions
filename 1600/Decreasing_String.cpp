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

struct Fenwick{
    int n;
    vector<ll> bit;

    Fenwick(int n){
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int i, int val){
        for (; i <= n; i += i & -i)
            bit[i] += val;
    }

    ll query(int i){
        ll sum = 0;
        for (; i > 0; i -= i & -i) sum += bit[i];
        return sum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        ll pos;
        cin >> pos;
        
        if(pos <= s.size()) {
            cout << s[pos-1];
            continue;
        }

        vector<ll> rank(s.size(),-1);
        vector<int> st; 
        ll num = 1;

        for (int i = 0; i < s.size(); i++){
            while (!st.empty() && s[st.back()] > s[i]){
                rank[st.back()] = num;
                num++;
                st.pop_back();
            }
            st.push_back(i);
        }

        while (!st.empty()){
            rank[st.back()] = num;
            num++;
            st.pop_back();
        }

        ll lo = 2 , hi = s.size();
        bool fnd = false;
        while(lo <= hi) {
            ll mid = (hi+lo)/2;
            ll st = (mid - 1) * s.size() - ((mid - 1) * (mid - 2)) / 2 + 1;
            ll ed = st + s.size() - mid;
            if(st <= pos && ed >= pos) {
                ll posy = st;
                for(int i = 0 ; i < s.size() ; i++) {
                    if(rank[i] >= mid) {
                        if(posy == pos) {
                            cout << s[i];
                            fnd = true;
                            break;
                        }
                        posy++;
                    }
                }
                if(fnd) break;
            }
            else if(st > pos) {
                hi = mid-1;
            }
            else lo = mid+1;
        }
    }
    return 0;
}
