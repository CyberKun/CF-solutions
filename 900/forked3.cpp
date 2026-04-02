#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long a, b, xK, yK, xQ, yQ;
        cin >> a >> b >> xK >> yK >> xQ >> yQ;

        vector<pair<long long, long long>> knightMovesKing = {
            {xK - a, yK - b}, {xK - a, yK + b}, {xK + a, yK - b}, {xK + a, yK + b}, {xK - b, yK - a}, {xK - b, yK + a}, {xK + b, yK - a}, {xK + b, yK + a}};

        vector<pair<long long, long long>> knightMovesQueen = {
            {xQ - a, yQ - b}, {xQ - a, yQ + b}, {xQ + a, yQ - b}, {xQ + a, yQ + b}, {xQ - b, yQ - a}, {xQ - b, yQ + a}, {xQ + b, yQ - a}, {xQ + b, yQ + a}};

        set<pair<long long, long long>> uniqueMovesKing(knightMovesKing.begin(), knightMovesKing.end());
        set<pair<long long, long long>> uniqueMovesQueen(knightMovesQueen.begin(), knightMovesQueen.end());

        int count = 0;
        for (const auto &move : uniqueMovesKing)
        {
            if (uniqueMovesQueen.find(move) != uniqueMovesQueen.end())
            {
                count++;
            }
        }

        cout << count << endl;
    }
    return 0;
}
