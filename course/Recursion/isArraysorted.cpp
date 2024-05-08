#include <iostream>
using namespace std;

bool is_sorted(int a[],int size){
  if(size == 0 || size==1) return true;
if (a[0] > a[1]) return false;
bool isSmallerSorted = is_sorted(a + 1, size - 1);
if (isSmallerSorted)return true;
return false;
}
int main() {
    int arr[8] = {0,1,2,3,4,5,6,7};
    if(is_sorted(arr,8)) cout<<"sorted";
    else cout<<"not sorted";
}
