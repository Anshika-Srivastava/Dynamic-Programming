	#include<bits/stdc++.h>
	using namespace std;

    string LCS(string x, string y){
        int n=x.size(),m=y.size();
        int t[n+1][m+1];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++){
                if(i==0||j==0)
                    t[i][j]=0;
            }
        
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                if(x[i-1]==y[j-1])
                    t[i][j]=1+t[i-1][j-1];
                else
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        
        int i=n,j=m;
        string S="";
        while(i>0 && j>0){
		if(x[i-1]==y[j-1]){
			S.push_back(x[i-1]);
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
    bool isSubsequence(string s, string t) {
        if(LCS(s,t)==s)
            return true;
        else
            return false;
    }
    int main(){
    	string x,y;
    	cin>>x>>y;
    	if(isSubsequence(x,y)==1)
    		cout<<"true";
    	else
    		cout<<"false";
    	return 0;
	}
