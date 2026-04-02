//way_too_long_words.cpp

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string str;
    cin >> n;
    cout << endl;
    for(int i=0;i<=n;i++)
    {
    getline(cin,str);

    int j=0,count=0;
    while(str[j]!='\0')
    {
        j++;
        count++;
    }

    if(count>10){cout <<str[0]<<(count-2)<<str[count-1];}
    else{cout << str;}
    }

    return 0;
}