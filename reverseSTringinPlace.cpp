#include<iostream>
using namespace std;
#include<cstring>
void func(char *str) 
{
    int n = strlen(str);
    int i =0 ;
    int j = n-1;
    while(i<j){
        char c = str[i];
        str[i]=str[j];
        str[j]=c;
        i++;
        j--;
    }
    
}

int main()
{
    char ch[100001];
    int t;
    cin>>t;
    while(t--)
    {
        cin>>ch;
        func(ch);
        cout<<ch;
	cout<<endl;
    }
}