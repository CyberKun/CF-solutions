#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        float a, b, xK, yK, xQ, yQ;
        cin >> a >> b >> xK >> yK >> xQ >> yQ;

        if (xQ >= xK && yQ >= yK)
        {
            float x1 = xQ - a;
            float y1 = yQ - b;
            float x2 = xK + a;
            float y2 = yK + b;

            float slope1 = (y2 - y1) / (x2 - x1 + 0.0001f);
            float slope2 = (yQ - yK) / (xQ - xK + 0.0001f);

            int ans = round(slope1 * slope2);

            if (x1 == x2 && y1 == y2)
            {
                cout << 1 << endl;
            }
            else if (xQ == xK || yQ == yK)
            {
                if (x2 - x1 == 0 || (y2 - y1) / (x2 - x1) == 1)
                {
                    cout << 2 << endl;
                }
                else
                {
                    cout << 0 << endl;
                }
            }
            else if (ans == (-1))
            {
                cout << 2 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else if (xK >= xQ && yK >= yQ)
        {
            float x1 = xK - a;
            float y1 = yK - b;
            float x2 = xQ + a;
            float y2 = yQ + b;

            float slope1 = (y2 - y1) / (x2 - x1 + 0.0001f);
            float slope2 = (yQ - yK) / (xQ - xK + 0.0001f);

            int ans = round(slope1 * slope2);

            if (x1 == x2 && y1 == y2)
            {
                cout << 1 << endl;
            }
            else if (xQ == xK || yQ == yK)
            {
                if (x2 - x1 == 0 || (y2 - y1) / (x2 - x1) == 1)
                {
                    cout << 2 << endl;
                }
                else
                {
                    cout << 0 << endl;
                }
            }
            else if (ans == (-1))
            {
                cout << 2 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else if (xK + yK == xQ + yQ)
        {
            int x = xK;
            int y = yK;
            if ((x + y) % 2 == 0)
            {

                if (xK > xQ)
                {
                    float x1 = (xK + a) / 2;
                    float y1 = (yQ + b) / 2;

                    if (x1 == y1)
                    {
                        cout << 1 << endl;
                    }
                    else
                    {
                        cout << 0 << endl;
                    }
                }
                else
                {
                    float x1 = (xQ + a) / 2;
                    float y1 = (yK + b) / 2;

                    if (x1 == y1)
                    {
                        cout << 1 << endl;
                    }
                    else
                    {
                        cout << 0 << endl;
                    }
                }
            }
            else
            {
                if (xK > xQ)
                {
                    int x1 = xK - a;
                    int y1 = yK + b;

                    int x2 = xQ + a;
                    int y2 = yQ - b;

                    float slope1 = (y2 - y1) / (x2 - x1 + 0.0001f);
                    float slope2 = (yQ - yK) / (xQ - xK + 0.0001f);

                    int ans = round(slope1 * slope2);

                    if (x1 == x2 && y1 == y2)
                    {
                        cout << 1 << endl;
                    }
                    else if (xQ == xK || yQ == yK)
                    {
                        if (x2 - x1 == 0 || (y2 - y1) / (x2 - x1) == 1)
                        {
                            cout << 2 << endl;
                        }
                        else
                        {
                            cout << 0 << endl;
                        }
                    }
                    else if (ans == (-1))
                    {
                        cout << 2 << endl;
                    }
                    else
                    {
                        cout << 0 << endl;
                    }
                }
                else
                {
                    int x1 = xQ - a;
                    int y1 = yQ + b;

                    int x2 = xK + a;
                    int y2 = yK - b;

                    float slope1 = (y2 - y1) / (x2 - x1 + 0.0001f);
                    float slope2 = (yQ - yK) / (xQ - xK + 0.0001f);

                    int ans = round(slope1 * slope2);

                    if (x1 == x2 && y1 == y2)
                    {
                        cout << 1 << endl;
                    }
                    else if (xQ == xK || yQ == yK)
                    {
                        if (x2 - x1 == 0 || (y2 - y1) / (x2 - x1) == 1)
                        {
                            cout << 2 << endl;
                        }
                        else
                        {
                            cout << 0 << endl;
                        }
                    }
                    else if (ans == (-1))
                    {
                        cout << 2 << endl;
                    }
                    else
                    {
                        cout << 0 << endl;
                    }
                }
            }
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}