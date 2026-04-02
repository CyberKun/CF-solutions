#include <iostream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

// Function to generate all products of elements in the array
void generateProducts(const vector<long long int> &arr, vector<long long int> &products)
{
    long long int n = arr.size();
    long long int totalCombinations = pow(2, n);
    set<long long int> uniqueProducts;
    for (int i = 1; i < totalCombinations; i++)
    {
        long long int product = 1;
        for (int j = 0; j < n; j++)
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

        vector<int> arr = {2, 3, 5};
        vector<long long int> products;
        generateProducts(size, products);
        cout << "Products of elements in the array: ";
        for (long long int prod : products)
        {
            cout << prod << ' ';
        }
        cout << endl;

        // for (size_t i = 0; i < size.size(); i++)
        // {
        //     cout << size[i] << ' ';
        // }
        // cout << endl;
    }
    return 0;
}
