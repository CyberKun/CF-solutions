#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1,str2;
    getline(cin ,str1);
    getline(cin ,str2);

    int l1,a1=0,a2=0;
    l1=str1.length();

    
    for (int i = 0; i < a1 - 1; i++) {
        for (int j = i+1; j < a1 ; j++) {
            if (str2[j]<str2[i])
        {
            int temp=str2[i];
            str2[i]=str2[j];
            str2[j]=temp;
        }
        }
    }

    for (int i = 0; i < a1 - 1; i++) {
        for (int j = i+1; j < a1 ; j++) {
            if (str1[j]<str1[i])
        {
            int temp=str1[i];
            str1[i]=str1[j];
            str1[j]=temp;
        }
        }
    }

    int flag=0;
    

        for(int i=0;i<l1;i++)
        {
            if(str1[i]>96)
              str1[i]-=32;
            if(str2[i]>97)
              str2[i]-=32;
              if(str1[i]<str2[i]) 
              {
                cout << -1;
                flag=1;
                break;
              } 
              if(str1[i]>str2[i])
              {
                cout << 1;
                flag=1;
                break;
              }
        }
        if(flag=0) cout << 0;
    return 0;
}