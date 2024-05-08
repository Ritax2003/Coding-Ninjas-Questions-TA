#include <iostream>
using namespace std;

void reverseStringWordWise(char input[]) {
    // Write your code here
    int count=0;
    for (int i=0;input[i]!='\0';i++){
        count++;
    }

int i=0;
int j=count-1;

while (i<j){

    int temp=input[i];
    input[i]=input[j];
    input[j]=temp;
    i++;
    j--;
}
int start=0;

for (int i=0;i<=count;i++){
    
if (input[i]==' '|| input[i]=='\0'){
     int end=i-1;
    while (start<end){
        int temp=input[start];
        input[start]=input[end];
        input[end]=temp;
        start++;
        end--;
    }
    start=i+1;
}
}
    
}

int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}
