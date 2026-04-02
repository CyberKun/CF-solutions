#include<iostream>
using namespace std;

int main()
{
    int n,sum1=0,sum2=0,count=0;
    cin >> n;
    int num[n];

    for(int i=0;i<n;i++)
    {cin >> num[i];
     sum1+=num[i];}

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(num[i]>num[j]){
                int temp=num[i];
                num[i]=num[j];
                num[j]=temp;}}}

    for(int i=n-1;i>=0;i--){
        sum2+=num[i];
        count++;
        if(sum2>sum1/2)
        break;}
    cout << count;

    return 0;
}