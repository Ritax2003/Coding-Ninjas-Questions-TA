#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;
#include<bits/stdc++.h>
double geometricSum(int n) {
    if(n!=0) return 1/pow(2,n) + geometricSum(n-1);
    if(n==0) return 1;
}



int main() {
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;   
}
