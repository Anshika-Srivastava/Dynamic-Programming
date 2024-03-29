#include <bits/stdc++.h>
#define MAX 10
using namespace std;

bool subsetSum(int arr[], int sum, int n){
	bool t[n+1][sum+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=sum;j++){
			if(i==0)
				t[i][j]=false;
			if(j==0)
				t[i][j]=true;
		}
		
	for(int i=1;i<=n;i++)
		for(int j=1;j<=sum;j++){
			if(arr[i-1]<=j)
				t[i][j]=(t[i-1][j-arr[i-1]]) || (t[i-1][j]);
			else
				t[i][j]=t[i-1][j];
		}
		
	/*for (int i = 0; i <= n; i++){
       for (int j = 0; j <= sum; j++)
          cout<<t[i][j]<<"\t";
       printf("\n");
	}*/
	
	return t[n][sum];
}

bool EqualSum(int arr[], int n){
	int sum=0;
	for(int i=0;i<n;i++)
		sum=sum+arr[i];
	if(sum%2!=0)
		return false;
		 
	return subsetSum(arr,sum/2,n);
		
}
signed main(){
	int arr[MAX], sum, n;
	cout<<"Enter the number of elements in the array: "<<endl;
	cin>>n;
	cout<<"Enter the elements of array: "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	if(EqualSum(arr,n))
	cout<<"True";
	else
	cout<<"False";
	return 0;
}
