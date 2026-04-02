#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t, n, i, ans;
    while(t--){
        cin >> s;
        n = s.size();
        ans = 0;
        for (i = 0; i < n; i++)
            ans += s[i] - '0';
        cout << ans << '\n';
    }
    return 0;
}