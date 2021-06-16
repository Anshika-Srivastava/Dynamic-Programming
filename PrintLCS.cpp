#include<bits/stdc++.h>
using namespace std;

string PrintLCS(string X, string Y){
	int n=X.size(), m=Y.size(); 
	int t[n + 1][m + 1]; // DP - matrix

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				t[i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1])
				t[i][j] = 1 + t[i - 1][j - 1];
			else 
				t[i][j] = max(t[i][j - 1], t[i - 1][j]);
	string S="";
	int i=n, j=m;
	while(i>0 && j>0){
		if(X[i-1]==Y[j-1]){
			S.push_back(X[i-1]);
			i--;
			j--;
		}
		else
		{
			if(t[i][j-1]>t[i-1][j])
				j--;
			else
				i--;
		}
	}
	reverse(S.begin(),S.end());
	return S;
}

int main(){
	string X,Y;
	cout<<"Enter first String:\t";
	cin>>X;
	cout<<"\nEnter second String:\t";
	cin>>Y;
	cout<<PrintLCS(X,Y);
	return 0;
}
