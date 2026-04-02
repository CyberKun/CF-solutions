#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
     string str;
     getline(cin,str);
     int flag=0,i=0;
     while(str[i]!='\0')
     {
        if(str[i]=='H' || str[i]=='Q' || str[i]=='9' || str[i]=='+')
        {
           flag=1;
           break;
        }
        i++;
     }
     if(flag)
     cout << "YES";
     else
     cout << "NO";

    return 0;
}