#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(int i=0;i<n;i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0, lim-1);
    return uid(rang);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t;
    cin >> t;
    while (t--) {
        ll n, l, r, sum1 = 0, sum2 = 0, suminitial = 0;
        cin >> n >> l >> r;
        vi v(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            if (i >= l and i <= r) {
                suminitial += v[i];
            }
        }
        sort(v.begin() + l, v.begin() + r + 1);
        sort(v.begin(), v.begin() + l);
        sort(v.begin() + r + 1, v.end());

        int j = r, count = 0;

        // Calculate sum1 by comparing elements before l and within [l, r]
        for (int i = 1; i < l; i++) {
            if (v[i] < v[j] and j >= l and count != r - l + 1) {
                sum1 += (v[i] - v[j]);
                count++, j--;
            }
        }

        j = r, count = 0;
        // Calculate sum2 by comparing elements after r and within [l, r]
        for (int i = r + 1; i <= n; i++) {
            if (v[i] < v[j] and j >= l and count != r - l + 1) {
                sum2 += (v[i] - v[j]);
                count++, j--;
            }
        }

        int mini = min(sum1, sum2);
        cout << suminitial + mini << "\n";
    }
    return 0;
}
