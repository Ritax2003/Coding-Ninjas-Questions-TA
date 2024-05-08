#include<bits/stdc++.h>
using namespace std;
int recurringele(int arr[],int n){
    unordered_map<int,int>mp;
    int most_freq = 0;
    int common_element =0;
    for(int i = 0;i<n;i++){
        mp[arr[i]]++;
        if(mp[arr[i]]> most_freq){
            most_freq = mp[arr[i]];           
            common_element = arr[i];
        }
    }
    return common_element;
}
int main(){
    int arr[] = {1,2,3,3,2,2,1};
    cout<<recurringele(arr,7)<<endl;
}
/*
  mp[1] =0 , mp[1]=1 
  mp[2] =0 , mp[2]= 1;
  mp[3] = 0, mp[3] =1;
  mp[3]= 2
  mp[2] =2
  mp[2]=3
  mp[1]=2

  1 = 2
  2 = 3 
  3 = 1 */