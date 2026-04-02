#include <iostream>
#include <string>
using namespace std;

int main() {
    int n,l,count=0;
    cin >> n >> l;
    int num[n];
    
    for (int i = 0; i < n; i++) {
        cin >> num[i];}
    
    for(int i=0;i<n;i++){
        if (num[i] < num[l-1] || num[i]==0)
        break;
        count++;}
    cout << count;

    return 0;}