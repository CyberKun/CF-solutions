#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> vec(n);

        int m[n];

        for (int i = 0; i < n; i++)
        {
            cin >> m[i];
            vec[i].resize(m[i]); // Ensure the vector has enough space before accessing elements
            for (int j = 0; j < m[i]; j++)
            {
                cin >> vec[i][j];
            }
            sort(vec[i].begin(), vec[i].end()); // Sort each inner vector
        }

        if (n > 1)
        {
            int diff[n];
            int maxdif = 0;
            int indexofmaxdif;

            for (int i = 0; i < n; i++)
            {
                diff[i] = vec[i][1] - vec[i][0]; // Ensure vec[i] has at least 2 elements
                if (diff[i] > maxdif)
                {
                    maxdif = diff[i];
                    indexofmaxdif = i;
                }
            }
            int indexofmin = 0, min = vec[0][0];

            for (int i = 0; i < n; i++)
            {
                if (i != indexofmaxdif)
                {
                    if (vec[i][0] < min)
                    {
                        min = vec[i][0];
                        indexofmin = i;
                    }
                }
            }
            int sum = 0;

            for (int i = 0; i < n; i++)
            {
                if (i != indexofmin)
                {
                    sum = sum + vec[i][1]; // Ensure vec[i] has at least 2 elements
                }
            }
            if (vec[indexofmaxdif][0] > min)
                sum = sum + min;
            else
                sum = sum + vec[indexofmaxdif][0];

            cout << sum << endl;
        }
        else
        {
            int min = vec[0][0];
            for (int i = 1; i < m[0]; i++)
            {
                if (vec[0][i] < min)
                    min = vec[0][i];
            }
            cout << min << endl;
        }
    }
    return 0;
}
