#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void generateProducts(const vector<long long int> &arr, vector<long long int> &products, int x)
{
    long long int n = arr.size();
    long long int totalCombinations = 1 << n; // 2^n

    set<long long int> uniqueProducts;
    uniqueProducts.insert(1); // Include 1 as a product of the empty subset
    if (x % 2 == 0)
        uniqueProducts.insert(2);

    for (long long int i = 1; i < totalCombinations; i++)
    {
        long long int product = 1;
        for (long long int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                product *= arr[j];
            }
        }
        uniqueProducts.insert(product);
    }

    for (long long int prod : uniqueProducts)
    {
        products.push_back(prod);
    }
}

long long int findMaxConsecutive(vector<long long int> &products)
{
    if (products.empty())
        return 0;

    sort(products.begin(), products.end());

    long long int maxConsecutive = 1;
    long long int currentConsecutive = 1;

    for (size_t i = 1; i < products.size(); i++)
    {
        if (products[i] == products[i - 1] + 1)
        {
            currentConsecutive++;
        }
        else
        {
            maxConsecutive = max(maxConsecutive, currentConsecutive);
            currentConsecutive = 1;
        }
    }

    maxConsecutive = max(maxConsecutive, currentConsecutive);

    return maxConsecutive;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long int n;
        cin >> n;

        vector<long long int> size;
        size.push_back(1);

        long long int x = n;

        // Check for smallest factors up to sqrt(n)
        for (long long int i = 2; i * i <= x; i++)
        {
            while (x % i == 0)
            {
                x = x / i;
                size.push_back(i);
            }
        }

        // If there is any prime factor greater than sqrt(n)
        if (x > 1)
        {
            size.push_back(x);
        }

        vector<long long int> products;
        generateProducts(size, products, n);

        // cout << "Products of elements in the array: ";
        // for (long long int prod : products)
        // {
        //     cout << prod << ' ';
        // }
        // cout << endl;

        long long int maxConsecutive = findMaxConsecutive(products);
        cout << maxConsecutive << endl;
    }

    return 0;
}
