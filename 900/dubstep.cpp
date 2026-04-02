#include <iostream>
#include <string>
using namespace std;

int main() {

    string str1,str2;
    getline(cin,str1);
    str2.resize(200, '\0');

    int n=str1.length();
    int flag=0;
    
    int i=0,j=0;
    while(str1[i]!='\0')
    {
        if( str1[i]=='W' && str1[i+1]=='U' && str1[i+2]=='B' )
        {
            if(flag==1 && j!=0)
           { str2[j]=' ';
            flag=0;
            j++;}
            i+=3;
        }
        else
        {
            str2[j]=str1[i];
            flag=1;
            j++;
            i++;
        }
    }
    str2[j]='\0';

    for(int i=0;i<j;i++)
    {
        cout << str2[i];
    }

    return 0;
    }