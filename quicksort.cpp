#include<bits/stdc++.h>
using namespace std;
int partitionArray(int arr[], int start, int end) {
	int pivot = arr[end];
	int i = start-1;
	for(int j =start;j<end;j++){
		if(arr[j]<pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[end]);
	 return i+1;
}
void quickSort(int input[], int start, int end) {
	if(start<end){
		int pi = partitionArray(input,start,end);
		quickSort(input,start,pi-1);
		quickSort(input,pi+1, end);
	}
}