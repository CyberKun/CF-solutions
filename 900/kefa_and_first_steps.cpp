#include <iostream>
using namespace std;

int main() {
    int n,a;
    cin >> a;
    int arr[a];
    getchar();
    
    for(int i=0;i<a;i++)
    {
        cin >> arr[i];
    }

    int count1=1,count2=1;

    for(int i=0;i<a-1;i++)
        {
            if(arr[i]<=arr[i+1])
            {
                count1++;
                if(count1>count2)
                count2=count1;
            }
            else
            count1=1;
        }

    cout << count2 << endl;

    return 0;
}