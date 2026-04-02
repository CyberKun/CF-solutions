#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> str(n);

    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < str[i].size() - 1;)
        {
            if (str[i][j] != str[i][j + 1])
            {
                str[i].erase(j, 2);
                count++;
                if (j >= 1)
                    j--;
            }
            else
                j++;

            if (str[i].size() == 0)
                break;
        }

        if (count % 2 == 0)
            cout << "NET" << endl;
        else
            cout << "DA" << endl;
    }

    return 0;
}