#include<iostream>
using namespace std;

int LCS(string X,string Y,int n,int m){
	if(n==0||m==0)
		return 0;
	if(X[n-1]==Y[m-1])
		return 1+LCS(X,Y,n-1,m-1);
	else
		 return max(LCS(X,Y,n,m-1),LCS(X,Y,n-1,m));
	return 0;
}

int main(){
	string X,Y;
	cin>>X>>Y;
	
	int n=X.size();
	int m=Y.size();
	cout<<LCS(X,Y,n,m);
	return 0;
}
