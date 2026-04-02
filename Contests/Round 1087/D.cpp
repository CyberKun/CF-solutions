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
        ll r, g, b;
        cin >> r >> g >> b;

        if(r == 0 && g == 0) {
            cout << 'B' << '\n';
            continue;
        }

        if(r == 0 && b == 0) {
            cout << 'G' << '\n';
            continue;
        }

        if (g == 0 && b == 0) {
            cout << 'R' << '\n';
            continue;
        }

        if(r == 0) {
            cout << "GB" << '\n';
            continue;
        }

        if (g == 0) {
            cout << "RB" << '\n';
            continue;
        }

        if (b == 0) {
            cout << "RG" << '\n';
            continue;
        }

        vector<string> s = {"RGB" , "RBG" , "GRB" , "GBR" , "BRG" , "BGR"};
        r-- , g-- , b--;
        for(int i = 0 ; i < 6 ; i++) {
            while(1) {
                if (s[i][s[i].size() - 2] == 'R') {
                    if(r == 0) break;
                    s[i] += 'R';
                    r--;
                }

                if (s[i][s[i].size() - 2] == 'G') {
                    if (g == 0)
                        break;
                    s[i] += 'G';
                    g--;
                }

                if (s[i][s[i].size() - 2] == 'B') {
                    if (b == 0) break;
                    s[i] += 'B';
                    b--;
                }
            }
        }
        sort(s.rbegin() , s.rend());
        cout << s[0] << '\n';
    }
    return 0;
}