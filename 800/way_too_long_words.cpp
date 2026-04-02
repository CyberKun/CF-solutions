#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string words[n];
    
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    for (int i = 0; i < n; i++) {
        if (words[i].length() > 10) {
            int len = words[i].length();
            cout << words[i][0] << len - 2 << words[i][len - 1] << endl;
        } else {
            cout << words[i] << endl;
        }
    }

    return 0;
}
