#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, xK, yK, xQ, yQ;
        cin >> a >> b >> xK >> yK >> xQ >> yQ;

        vector<pair<long long int, long long int>> veck;
        veck.push_back(make_pair(xK - a, yK - b));
        veck.push_back(make_pair(xK - a, yK + b));
        veck.push_back(make_pair(xK + a, yK - b));
        veck.push_back(make_pair(xK + a, yK + b));
        veck.push_back(make_pair(xK - b, yK - a));
        veck.push_back(make_pair(xK - b, yK + a));
        veck.push_back(make_pair(xK + b, yK - a));
        veck.push_back(make_pair(xK + b, yK + a));

        vector<pair<long long int, long long int>> vecq;
        vecq.push_back(make_pair(xQ - a, yQ - b));
        vecq.push_back(make_pair(xQ - a, yQ + b));
        vecq.push_back(make_pair(xQ + a, yQ - b));
        vecq.push_back(make_pair(xQ + a, yQ + b));
        vecq.push_back(make_pair(xQ - b, yQ - a));
        vecq.push_back(make_pair(xQ - b, yQ + a));
        vecq.push_back(make_pair(xQ + b, yQ - a));
        vecq.push_back(make_pair(xQ + b, yQ + a));

        for (int i = 0; i < veck.size(); i++)
        {
            for (int j = i + 1; j < veck.size(); j++)
            {
                if (veck[i] == veck[j])
                {
                    veck.erase(veck.begin() + j);
                    j--;
                }
            }
        }

        for (int i = 0; i < vecq.size(); i++)
        {
            for (int j = i + 1; j < vecq.size(); j++)
            {
                if (vecq[i] == vecq[j])
                {
                    vecq.erase(vecq.begin() + j);
                    j--;
                }
            }
        }

        int count = 0;

        for (int i = 0; i < veck.size(); i++)
        {
            for (int j = 0; j < vecq.size(); j++)
            {
                if (veck[i] == vecq[j])
                {
                    count++;
                    break;
                }
            }
        }

        cout << count << endl;
    }
    return 0;
}

// for (int i = 0; i < veck.size(); i++)
//         {
//             cout << veck[i].first << ' ' << veck[i].second << endl;
//         }
//         cout << endl;

//         for (int i = 0; i < vecq.size(); i++)
//         {
//             cout << vecq[i].first << ' ' << vecq[i].second << endl;
//         }
//         cout << endl;