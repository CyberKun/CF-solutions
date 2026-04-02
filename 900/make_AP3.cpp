#include <iostream>
#include <vector>
#include <algorithm> // Include the algorithm header for std::min_element and std::max_element
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long int a, b, c;
        cin >> a >> b >> c;

        long long int d1 = b - c;
        long long int a1 = b + d1;

        long long int d2 = b - a;
        long long int c1 = b + d2;

        if ((a + c) % (2 * b) == 0)
        {
            cout << "YES" << endl;
        }
        else if (a1 % a == 0 && a1 > 0)
        {
            cout << "YES" << endl;
        }
        else if (c1 % c == 0 && c1 > 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}