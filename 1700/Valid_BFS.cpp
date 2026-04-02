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

    ll t = 1;
    // cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        vector<ll> adj[n + 1],  vec(n) , slot[n + 1];
        for (int i = 1; i < n; i++) {
            ll u , v;
            cin >> u >> v;
            adj[v].push_back(u);
            adj[u].push_back(v);
        }

        for(int i = 0 ; i < n ; i++) cin >> vec[i];

        if (vec[0] != 1) {
            cout << "No\n";
            continue;
        }

        ll curr = 0 , curr1 = 0;
        map<ll,ll> fq;
        vector<bool> visited(n + 1 , false);
        bool psbl = true;
        for(auto child : adj[1]) {
            slot[curr1].push_back(child);
        }
        curr1++;
        visited[1] = true;

        for(int i = 1 ; i < n ; i++) {
            while(fq.empty()) {
                for(int j = 0 ; j < slot[curr].size() ; j++) fq[slot[curr][j]]++;
                curr++;
            }
            
            if(visited[vec[i]] == false) {
                visited[vec[i]] = true;
                if(!(fq[vec[i]])) {
                    psbl = false;
                    break;
                }
                else {
                    fq.erase(vec[i]);
                    for(auto child : adj[vec[i]]) {
                        if(visited[child] == false)slot[curr1].push_back(child);
                    }
                    curr1++;
                }
            }
        }

        if(psbl) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}
