#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

vector<int> isSubPoss(int arr[],int n,int range){
	bool t[n+1][range+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=range;j++){
			if(i==0)
				t[i][j]=false;
			if(j==0)
				t[i][j]=true;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=range;j++){
			if (arr[i - 1] <= j)
				t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
			else
				t[i][j] = t[i - 1][j];
		}
	}
	
	vector<int> v; // contains all subset sums possible with n elements
	for (int j = 0; j <= range; j++)
		if (t[n][j] == true)
			v.push_back(j);

	return v;
}

int MinSubSum(int arr[],int n){
	int range=0;
	for(int i=0;i<n;i++)
		range+=arr[i];
		
	vector<int> v = isSubPoss(arr,n,range);
	int mn=INT_MAX;
	for(int i=0;i<v.size();i++)
		mn=min(mn,abs(range-2*v[i]));
		
	return mn;
}

int main(){
	int n;
	cout<<"Please input the number of elements"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Please input the array:"<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Minimum Subset Sum Difference:\t"<<MinSubSum(arr,n);
	return 0;
}
