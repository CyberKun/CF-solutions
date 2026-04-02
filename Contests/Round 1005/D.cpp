#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int &x : a) cin >> x;

    // Compute initial score
    set<int> unique_elements(a.begin(), a.end());
    int initial_score = n - unique_elements.size();

    // If no duplicates, remove the full array
    if (initial_score == 0) {
        cout << "1 " << n << "\n";
        return;
    }

    // Map to store leftmost and rightmost occurrences
    unordered_map<int, int> left, right;
    for (int i = 0; i < n; i++) {
        if (left.find(a[i]) == left.end()) left[a[i]] = i;
        right[a[i]] = i;
    }

    // Find the best segment to remove
    int best_l = 0, best_r = 0, max_gain = 0, min_length = n;

    for (auto &[val, l] : left) {
        int r = right[val]; // Get rightmost index of val
        int unique_removed = (r - l + 1) - 1; // Elements removed except 1 copy
        int new_score = initial_score + unique_removed;

        int length = n - (r - l + 1); // Remaining array length

        // Choose best improvement with min length
        if (new_score > max_gain || (new_score == max_gain && length < min_length)) {
            max_gain = new_score;
            best_l = l + 1;
            best_r = r + 1;
            min_length = length;
        }
    }

    cout << best_l << " " << best_r << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
