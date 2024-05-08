
#include <iostream>
using namespace std;
#include<bits/stdc++.h>
void removeX(char input[]) {
    if(input[0]=='\0') return;
    if(input[0]!='x') removeX(input+1);
    if(input[0]=='x'){
        for(int i=1;i<=strlen(input);i++){
            input[i-1] = input[i];
        }
        removeX(input);
    }

}
int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
