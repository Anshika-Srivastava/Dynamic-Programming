# include<bits/stdc++.h>
using namespace std;

int Solve(int arr[],int i,int j){
	if(i>=j)
		return 0;
	int mn=INT_MAX;
	for(int k=i;k<j;k++){
		int tempans=Solve(arr,i,k)+Solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
		if(tempans<mn)
			mn=tempans;
	}
	return mn;
}

int main(){
	int n;
	cout<<"\nEnter array size";
	cin>>n;
	int arr[n];
	cout<<"\nEnter array elements:\n";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<Solve(arr,1,n-1);
	return 0;
}
