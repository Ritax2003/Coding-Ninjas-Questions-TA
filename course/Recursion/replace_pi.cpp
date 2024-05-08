

#include <iostream>
using namespace std;
#include <bits/stdc++.h>
void helper(char str[],int start){
	if(str[start]=='\0' || str[start+1]=='\0') return ;
    
        helper(str,start+1);
    
	

	if(str[start]=='p' and str[start+1]=='i'){
          for (int i = strlen(str); i >= start + 2; i--) {
            	str[i + 2] = str[i];
          }
          str[start] = '3';
          str[start + 1] = '.';
          str[start + 2] = '1';
          str[start + 3] = '4';
	 }
}
void replacePi(char input[]) {
	helper(input,0);
}

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
