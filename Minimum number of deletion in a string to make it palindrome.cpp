//Minimum number of deletion in a string to make it palindrome
#include<bits/stdc++.h>

using namespace std;

int LCS(string X,string Y){
	int n=X.size(), m=Y.size();
	int t[n+1][m+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++){
			if(i==0||j==0)
				t[i][j]=0;
		}
		
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(X[i-1]==Y[j-1])
				t[i][j]= 1+t[i-1][j-1];
			else
				t[i][j]= max(t[i-1][j],t[i][j-1]);
		}
		
	return t[n][m];
}

int main(){
	string x,y;
	cout<<"Enter string:\t";
	cin>>x;
	y=x;
	reverse(x.begin(),x.end());
	cout<<"Minimum number of deletion in this string to make it palindrome:\t"<<x.size()-LCS(y,x);
}
