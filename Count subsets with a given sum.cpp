#include <bits/stdc++.h>
#define MAX 10
using namespace std;

int Count_Subset(int arr[],int sum,int n){
	int t[n+1][sum+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=sum;j++){
			if(i==0)
				t[i][j]=0;
			if(j==0)
				t[i][j]=1;
		}
		
	for(int i=1;i<=n;i++)
		for(int j=1;j<=sum;j++){
			if(arr[i-1]<=j)
				t[i][j]=t[i-1][j]+t[i-1][j-arr[i-1]];
			else
				t[i][j]=t[i-1][j];
		}
	
	return t[n][sum];
}

int main(){
	int arr[MAX], sum, n, count;
	cout<<"Enter the number of elements in the array: "<<endl;
	cin>>n;
	cout<<"Enter the elements of array: "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Enter the sum: "<<endl;
	cin>>sum;
	count=Count_Subset(arr,sum,n);
	cout<<count;
	return 0;
}
