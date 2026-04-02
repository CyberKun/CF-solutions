#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string words[n];
    int count=0;
    
    for (int i = 0; i < n; i++){
        cin >> words[i];}

    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            if (words[i][j]=='+'){
                count++;
                break;}
            if (words[i][j]=='-'){
                count--;
                break;}}}

    cout << count;


    return 0;
}