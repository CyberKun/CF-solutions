#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, size = 0;
        cin >> n;

        if (n <= 5)
        {
            cout << 'a';
            size++;

            if (size < n)
                cout << 'e';
            size++;

            if (size < n)
                cout << 'i';
            size++;

            if (size < n)
                cout << 'o';
            size++;

            if (size < n)
                cout << 'u';
            size++;
        }
        else
        {
            if (n % 5 == 0)
            {
                for (int i = 0; i < n / 5; i++)
                    cout << 'a';

                for (int i = 0; i < n / 5; i++)
                    cout << 'e';

                for (int i = 0; i < n / 5; i++)
                    cout << 'i';

                for (int i = 0; i < n / 5; i++)
                    cout << 'o';

                for (int i = 0; i < n / 5; i++)
                    cout << 'u';
            }
            else
            {
                int counta = n / 5, counte = n / 5, counti = n / 5, counto = n / 5, countu = n / 5;

                int b = n % 5;

                while (b > 0)
                {
                    counta++;
                    b--;

                    if (b > 0)
                        counte++;
                    b--;

                    if (b > 0)
                        counti++;
                    b--;

                    if (b > 0)
                        counto++;
                    b--;
                }

                for (int i = 0; i < counta; i++)
                    cout << 'a';

                for (int i = 0; i < counte; i++)
                    cout << 'e';

                for (int i = 0; i < counti; i++)
                    cout << 'i';

                for (int i = 0; i < counto; i++)
                    cout << 'o';

                for (int i = 0; i < countu; i++)
                    cout << 'u';
            }
        }

        cout << endl;
    }

    return 0;
}
