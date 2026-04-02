#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// Function to generate products using dynamic programming
void generateProductsDP(const vector<long long int>& factors, set<long long int>& products) {
    products.insert(1); // Include 1 as a product of the empty subset

    for (long long int factor : factors) {
        set<long long int> newProducts;
        for (long long int product : products) {
            newProducts.insert(product * factor);
        }
        products.insert(newProducts.begin(), newProducts.end());
    }
}

long long int findMaxConsecutive(const set<long long int>& products) {
    if (products.empty()) return 0;

    long long int maxConsecutive = 1;
    long long int currentConsecutive = 1;
    auto it = products.begin();
    auto prev = it;
    ++it;

    for (; it != products.end(); ++it) {
        if (*it == *prev + 1) {
            currentConsecutive++;
        } else {
            maxConsecutive = max(maxConsecutive, currentConsecutive);
            currentConsecutive = 1;
        }
        prev = it;
    }

    maxConsecutive = max(maxConsecutive, currentConsecutive);
    return maxConsecutive;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long int n;
        cin >> n;

        vector<long long int> factors;
        long long int x = n;

        // Factorize x and collect prime factors
        for (long long int i = 2; i * i <= x; i++) {
            while (x % i == 0) {
                x = x / i;
                factors.push_back(i);
            }
        }

        // If there is any prime factor greater than sqrt(n)
        if (x > 1) {
            factors.push_back(x);
        }

        set<long long int> products;
        generateProductsDP(factors, products);

        long long int maxConsecutive = findMaxConsecutive(products);
        cout << maxConsecutive << endl;
    }

    return 0;
}
