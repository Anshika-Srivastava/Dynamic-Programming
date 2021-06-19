//Longest Repeating Subsequence
#include<bits/stdc++.h>

using namespace std;

int LCS(string X,string Y,int n,int m){
	int t[n+1][m+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++){
			if(i==0||j==0)
				t[i][j]=0;
		}
		
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){	
		if(X[i-1]==Y[j-1] && i!=j)
				t[i][j]=1+t[i-1][j-1];
			else
				t[i][j]=max(t[i-1][j],t[i][j-1]);
		}
	return t[n][m];
}

int main(){
	string X;
	cin>>X;
	
	int n=X.size();
	cout<<LCS(X,X,n,n);
	return 0;
}
