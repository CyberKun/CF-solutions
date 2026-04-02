#include <iostream>
using namespace std;

int main()
{
    long long int n, b, d;
    cin >> n >> b >> d;

    long long int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    long long int count = 0, size = 0, sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= b)
        {
            sum = sum + arr[i];
        }
        if (sum > d)
        {
            sum = 0;
            count++;
        }
    }
    cout << count;

    return 0;
}