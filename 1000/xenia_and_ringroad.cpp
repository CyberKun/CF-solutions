#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(m);

    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }

    long long int time = a[0] - 1;

    for (int i = 1; i < m; i++)
    {
        if (a[i - 1] < a[i])
        {
            time = time + a[i] - a[i - 1];
        }
        else if (a[i - 1] > a[i])
        {
            time = time + (n + a[i] - a[i - 1]);
        }
    }

    cout << time;

    return 0;
}