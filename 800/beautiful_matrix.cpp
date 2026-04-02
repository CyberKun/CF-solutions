#include <iostream>
using namespace std;

int main() {
    int m,n,mat[5][5];

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin >> mat[i][j];}}
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(mat[i][j]==1){
                m=i-2;
                n=j-2;}}}

    if(m<0){m=m*(-1);}
    if(n<0){n=n*(-1);}

    cout << (m+n);
    return 0;
}