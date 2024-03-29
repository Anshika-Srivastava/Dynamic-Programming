#include<iostream>

using namespace std;

int count(int arr[],int sum,int n){
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
				t[i][j]= t[i-1][j]+t[i-1][j-arr[i-1]];
			else
				t[i][j]= t[i-1][j];
		}
		
	return t[n][sum];
}

int countSubset(int arr[],int n,int diff){
	int range=0,s1;
	for(int i=0;i<n;i++)
		range+=arr[i];
	
	if ((range + diff) % 2 != 0)
		return 0;
	else
		return count(arr,(range + diff) / 2,n);
}

int main(){
	int n,diff;
	cout<<"Please input number of elements:\t"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Please input the array element:\t"<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Please input the difference:\t"<<endl;
	cin>>diff;
	cout<<"The count is: \t"<<countSubset(arr,n,diff);
	return 0;
}
