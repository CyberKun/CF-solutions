#include <iostream>
#include <vector>
using namespace std;

// Function to check if a knight move attacks both the king and the queen
bool checkAttack(int a, int b, int xK, int yK, int xQ, int yQ, int dx, int dy) {
    int knightX = xK + dx;
    int knightY = yK + dy;
    return (knightX == xQ && knightY == yQ);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, xK, yK, xQ, yQ;
        cin >> a >> b >> xK >> yK >> xQ >> yQ;

        int moves[8][2] = {{a, b}, {a, -b}, {-a, b}, {-a, -b},
                           {b, a}, {b, -a}, {-b, a}, {-b, -a}};
        
        int count = 0;
        for (int i = 0; i < 8; ++i) {
            if (checkAttack(a, b, xK, yK, xQ, yQ, moves[i][0], moves[i][1])) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}
