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

    ll t = 1;
    // cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        vector<string> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];
        vector<pair<char,char>> v;
        for (int i = 0; i < n - 1; i++) {
            bool f = false;
            for(int j = 0 ; j < min(vec[i].size() , vec[i + 1].size()) ; j++) {
                if(vec[i][j] != vec[i + 1][j]) {
                    v.push_back({vec[i][j]  , vec[i + 1][j]});
                    f = true;
                    break;
                }
            }
            if(!f && vec[i].size() > vec[i + 1].size()) {
                cout << "Impossible\n";
                return 0;
            }
        }
        // set<pair<char, char>> st;
        // for (auto p : v) {
        //     char x = p.first, y = p.second;
        //     if (st.count({y, x})) {
        //         cout << "Impossible\n";
        //         return 0;
        //     }
        //     st.insert({x, y});
        // }
        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);

        for (auto p : v) {
            int u = p.first - 'a' , w = p.second - 'a';
            adj[u].push_back(w);
            indegree[w]++;
        }

        queue<int> q;
        for (int i = 0; i < 26; i++) 
            if (indegree[i] == 0) q.push(i);
        

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto nxt : adj[node]) {
                indegree[nxt]--;
                if (indegree[nxt] == 0) q.push(nxt);
            }
        }

        if(topo.size() != 26) cout << "Impossible" << '\n';
        else {
            for (auto x : topo) cout << char(x + 'a');
            cout << "\n";
        }
    }
    return 0;
}
