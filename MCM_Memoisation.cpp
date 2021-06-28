# include<bits/stdc++.h>
using namespace std;

int t[1001][1001];
int Solve(int arr[],int i,int j){
	if(i>=j)
		return 0;
		
	if(t[i][j] != -1)
		return t[i][j];
	int mn=INT_MAX;
	for(int k=i;k<j;k++){
		int tempans=Solve(arr,i,k)+Solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
		if(tempans<mn)
			mn=tempans;
	}
	return t[i][j]=mn;
}

int main(){
	int n;
	memset(t,-1,sizeof(t));
	cout<<"\nEnter array size";
	cin>>n;
	int arr[n];
	cout<<"\nEnter array elements:\n";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<Solve(arr,1,n-1);
	return 0;
}
