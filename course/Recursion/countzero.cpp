#include <iostream>

using namespace std;
int countZeros(int input) {
if(input==0){return 1;}
if(input<10){return 0;}
else if(input%10==0){
         return 1+countZeros(input/10);
   }
    return countZeros(input/10);
}

int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}
