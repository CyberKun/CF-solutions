#include <iostream>
using namespace std;

int main() {
    int n,a;
    cin >> a;
    int arr[a];
    
    for(int i=0;i<a;i++)
    {
        cin >> arr[i];
    }

    for(int i=0;i<a;i++)
        {
            for(int j=i+1;j<a;j++)
            {
                if(arr[j]<arr[i])
                {
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                    }
            } 
        }

    for(int i=0;i<a;i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}