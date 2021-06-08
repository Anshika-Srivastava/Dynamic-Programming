//length og longest common substring
#include<iostream>
using namespace std;

int LCSub(string X,string Y,int n,int m){
	int t[n+1][m+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++){
			if(i==0||j==0)
				t[i][j]=0;
		}
		
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(X[i-1]==Y[j-1])
				t[i][j]=1+t[i-1][j-1];
			else
				t[i][j]=0;
		}
		
	int mx = INT_MIN;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			mx = max(mx, t[i][j]);
		
	return mx;
}

int main(){
	string X,Y;
	cin>>X>>Y;
	int n=X.size(),m=Y.size();
	cout<<"Length of longest common substring:\t"<<LCSub(X,Y,n,m);
	return 0;
}
