//Lenght of longest common Subsequence
#include <bits/stdc++.h>

using namespace std;

const int D = 1001;
int t[D][D];

int LCS(string X,string Y,int n,int m){
	if(n==0||m==0) //Base case
		t[n][m]=0;
	if(t[n][m] != -1) 
		return t[n][m];
	if(X[n-1]==Y[m-1]) //When the last character is same
		t[n][m]=1+LCS(X,Y,n-1,m-1);
	else
		t[n][m]=max(LCS(X,Y,n,m-1),LCS(X,Y,n-1,m));
		
	return t[n][m];
}

int main(){
	string X,Y;
	cin>>X>>Y;	
	int n=X.size(), m=Y.size();
	memset(t, -1, sizeof(t));

	cout << LCS(X, Y, n, m) << endl;
	return 0;
}

