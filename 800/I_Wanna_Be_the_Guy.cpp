#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n, p, q, x;

    cin >> n;
    set<int> levels;

    cin >> p;
    for (int i = 0; i < p; i++)
    {
        cin >> x;
        levels.insert(x);
    }

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> x;
        levels.insert(x);
    }
    
    if (n == levels.size())
    {
        cout << "I become the guy." << endl;
    }
    else
    {
        cout << "Oh, my keyboard!" << endl;
    }

    return 0;
}
