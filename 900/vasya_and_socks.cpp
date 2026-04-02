#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int count = 0;
    int day = 1;

    while (n > 0)
    {
        count++;
        n--;
        if (day % m == 0)
            n++;
        day++;
    }

    cout << count;

    return 0;
}