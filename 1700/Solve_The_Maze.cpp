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
    cin >> t;

    while (t--)
    {
        ll n , m;
        cin >> n >> m;
        vector<vector<char>> adj(n, vector<char>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> adj[i][j];

        ll ct = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if(adj[i][j] == 'G') ct++;

        // vector<vector<ll>> edges(n + 1, vector<ll>());
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (adj[i][j])
        //         {
        //             edges[i + 1].push_back(j + 1);
        //         }
        //     }
        // }

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        function<bool(pair<ll,ll>)> bfs = [&](auto node) -> bool {
            queue<pair<ll,ll>> q;
            q.push(node);
            visited[node.first][node.second] = true;
            ll ct1 = 0;

            while (!q.empty())
            {
                auto b = q.front();
                while(!q.empty() && ((b.first != 0 && adj[b.first - 1][b.second] == 'B') || (b.second != 0 && adj[b.first][b.second - 1] == 'B') || (b.first != n - 1 && adj[b.first + 1][b.second] == 'B') || (b.second != m - 1 && adj[b.first][b.second + 1] == 'B'))) {
                    q.pop();
                    if(q.empty()) return ct1 == ct;
                    b = q.front();
                }
                q.pop();

                if(adj[b.first][b.second] == 'G') ct1++;
                if (b.first != n - 1 && adj[b.first + 1][b.second] != '#' && visited[b.first + 1][b.second] != true){
                    visited[b.first + 1][b.second] = true;
                    q.push({b.first + 1, b.second});
                }
                if (b.second != m - 1 && adj[b.first][b.second + 1] != '#' && visited[b.first][b.second + 1] != true){
                    visited[b.first][b.second + 1] = true;
                    q.push({b.first, b.second + 1});
                }
                if (b.first != 0 && adj[b.first - 1][b.second] != '#' && visited[b.first - 1][b.second] != true){
                    visited[b.first - 1][b.second] = true;
                    q.push({b.first - 1, b.second});
                }
                if (b.second != 0 && adj[b.first][b.second - 1] != '#' && visited[b.first][b.second - 1] != true){
                    visited[b.first][b.second - 1] = true;
                    q.push({b.first, b.second - 1});
                }
                
            }
            return ct1 == ct;
        };
        // for (int i = 1; i <= n; i++)
        // {
        //     ll ans = bfs(i);
        //     cout << (ans == -1 ? "NO WAY" : to_string(ans)) << ' ';
        //     fill(visited.begin(), visited.end(), false);
        // }
        // cout << '\n';
        if(bfs({n-1 , m-1})) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
