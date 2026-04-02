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
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> edges(n, vector<ll>());
        vector<vector<char>> matrix(n, vector<char>(m));
        pair<ll,ll> start , end ;
        for (int i = 0; i < n; i++) {
            for(int j = 0 ; j < m ; j++) {
                cin >> matrix[i][j];
                if(matrix[i][j] == 'A') start = {i,j};
                if(matrix[i][j] == 'B') end = {i, j};
            }
        }
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<pair<ll,ll>>> parent(n, vector<pair<ll,ll>>(m));
        vector<vector<char>> matty(n, vector<char>(m));

        function<void(pair<ll,ll>)> bfs = [&](pair<ll,ll> node) {
            queue<pair<ll,ll>> q;
            q.push(node);
            visited[node.first][node.second] = true;

            while (!q.empty()) {
                auto curr = q.front();
                if(curr == end) break;
                q.pop();
                if (curr.first != n - 1 && matrix[curr.first + 1][curr.second] != '#' && visited[curr.first + 1][curr.second] != true) {
                    visited[curr.first + 1][curr.second] = true;
                    matty[curr.first + 1][curr.second] = 'D';
                    q.push({curr.first + 1 , curr.second});
                    parent[curr.first + 1][curr.second] = curr;
                }
                if (curr.second != m - 1 && matrix[curr.first][curr.second + 1] != '#' && visited[curr.first][curr.second + 1] != true) {
                    visited[curr.first][curr.second + 1] = true;
                    matty[curr.first][curr.second + 1] = 'R';
                    q.push({curr.first, curr.second + 1});
                    parent[curr.first][curr.second + 1] = curr;
                }
                if (curr.first != 0 && matrix[curr.first - 1][curr.second] != '#' && visited[curr.first - 1][curr.second] != true) {
                    visited[curr.first - 1][curr.second] = true;
                    matty[curr.first - 1][curr.second] = 'U';
                    q.push({curr.first - 1, curr.second});
                    parent[curr.first - 1][curr.second] = curr;
                }
                if (curr.second != 0 && matrix[curr.first][curr.second - 1] != '#' && visited[curr.first][curr.second - 1] != true) {
                    visited[curr.first][curr.second - 1] = true;
                    matty[curr.first][curr.second - 1] = 'L';
                    q.push({curr.first, curr.second - 1});
                    parent[curr.first][curr.second - 1] = curr;
                }
            }
        };

        bfs(start);
        vector<char> ans;
        if (visited[end.first][end.second]) {
            cout << "YES" << '\n';
            auto curr = end;
            while (curr != start) {
                ans.push_back(matty[curr.first][curr.second]);
                curr = parent[curr.first][curr.second];
            }
            reverse(ans.begin(), ans.end());
            cout << ans.size() << '\n';
            for (auto c : ans) cout << c;
        }
        else cout << "NO" << '\n';
    }
    return 0;
}
