#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        priority_queue<pair<int, int>> pq;
        vector<int> health(n);

        for (int i = 0; i < n; i++) {
            cin >> health[i];
            pq.push({health[i], -i}); // Use negative index to prioritize smaller index in case of tie
        }

        vector<int> deathOrder;

        while (!pq.empty()) {
            auto [hp, idx] = pq.top();
            pq.pop();

            int index = -idx; // Convert back to positive index

            if (health[index] > 0) {
                deathOrder.push_back(index + 1); // Store 1-based index of the monster
                health[index] -= k;
                if (health[index] > 0) {
                    pq.push({health[index], idx}); // Push back with updated health
                }
            }
        }

        for (int i : deathOrder) {
            cout << i << ' ';
        }
        cout << endl;
    }

    return 0;
}
