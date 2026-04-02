#include <iostream>
#include <string>
using namespace std;

int main()
{
    int k, n, w;
    cin >> k >> n >> w;

    int cost = 0;

    for (int i = 0; i < w; i++)
    {
        cost = cost + (i + 1) * k;
    }

    if (cost < n)
    {
        cout << 0;
    }
    else
    {
        cout << cost - n;
    }

    return 0;
}