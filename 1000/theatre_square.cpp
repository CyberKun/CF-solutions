#include <iostream>
using namespace std;

int main()
{
    long long int n, m, a;
    cin >> n >> m >> a;
    long long sum = 0, count3 = n / a, count4 = m / a;
    sum = count3 * a;
    if (sum < n)
    {
        sum = sum + a;
        count3++;
    }

    sum = count4 * a;

    if (sum < m)
    {
        sum = sum + a;
        count4++;
    }

    cout << count3 * count4;

    return 0;
}