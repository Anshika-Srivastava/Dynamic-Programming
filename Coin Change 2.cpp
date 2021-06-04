#include<iostream>
using namespace std;

int minCoins(int coins[],int n,int sum){
	int t[n+1][sum+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=sum;j++){
			if(i==0)
				t[i][j]= INT_MAX-1;
			if(j==0)
				t[i][j]= 0;
			if(i==1)
				if(j%coins[0]==0)
					t[i][j]=j/coins[0];
				else
					t[i][j]=INT_MAX-1;
		}
		
	for(int i=2;i<=n;i++)
		for(int j=1;j<=sum;j++){
		if(coins[i-1]<=j)
			t[i][j]=min(1+t[i][j-coins[i-1]],t[i-1][j]);
		else
			t[i][j]=t[i-1][j];
	}
	
	return t[n][sum];
}

int main(){
	int n,sum;
	cin>>n;
	int coin[n];
	for(int i=0;i<n;i++)
		cin>>coin[i];
	cin>>sum;
	cout<<"Min number of coins:\t"<<minCoins(coin,n,sum);
	return 0;
}
