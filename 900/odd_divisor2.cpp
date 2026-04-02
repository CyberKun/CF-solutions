#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long int num[n];

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    for (int i = 0; i < n; i++)
    {
        while(num[i]%2==0)
        {
            num[i]=num[i]/2;
        }
        if(num[i]==1)
        cout << "NO" << endl;
        else
        cout << "YES" << endl;
    }

    return 0;
}