#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,count=0;
    cin >> n;
    char str[n];

    for(int i=0;i<n;i++){
        cin >> str[i];
    }

    for(int i=0;i<n-1;i++){
        if(str[i]==str[i+1])
        count++;
    }

    cout << count;
    return 0;
}