#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int l, n, m, o;
    l = a + b + c;
    m = a * b * c;
    n = (a + b) * c;
    o = a * (b + c);

    int num[4] = {l, m, n, o};
    int maxnum = *max_element(num, num + 4);

    cout << maxnum;

    return 0;
}