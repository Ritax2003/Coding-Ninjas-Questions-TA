#include<iostream>
using namespace std;
long long int decimaltobinary(int n){
	long long int binary = 0, product = 1;
		  while (n!= 0) {
		      int remainder = n % 2;
			  binary = binary + (remainder * product);
			  n = n / 2;
			  product *= 10;
		}
	return binary;
}
int main() {
	int decimalnumber;
	cin>>decimalnumber;
	cout<<decimaltobinary(decimalnumber)<<endl;
 	return 0;
}
