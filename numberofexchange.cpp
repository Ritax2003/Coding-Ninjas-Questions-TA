#include <iostream>
using namespace std;
#include<vector>
#include <bits/stdc++.h>

int helper(vector<vector <int> > &dp,int c[],int n,int v){
    if(v<0)
        return 0;
    if(v==0)
        return 1;
    if(n==0)
        return 0;
    ///alredy present
    if(dp[n][v]!=0)
        return dp[n][v];
    
    //Either include nth coin or don't include
    int ans=helper(dp,c,n,v-c[n-1])+helper(dp,c,n-1,v);
    dp[n][v]=ans;
    return ans;
}
int countWaysToMakeChange(int denominations[], int numDenominations, int value){
vector <vector <int> > dp(numDenominations+1,vector<int>(value+1,0));
    int ans=helper(dp,denominations,numDenominations,value);
    
    return ans;
	}
int main()
{

	int numDenominations;
	cin >> numDenominations;
	
	int *denominations = new int[numDenominations];

	for (int i = 0; i < numDenominations; i++)
	{
		cin >> denominations[i];
	}
    int value;
	cin >> value;

	cout << countWaysToMakeChange(denominations, numDenominations, value);

	delete[] denominations;

}