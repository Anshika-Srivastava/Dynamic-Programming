#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s,int i,int j){
	while (i <= j) {
		if (s[i] != s[j])
			return false;
		i++, j--;
	}

	return true;
}

int Solve(string s,int i,int j){
	if(i>=j)
		return 0;
	if(isPalindrome(s,i,j)==true)
		return 0;
	int mn=INT_MAX;
	for(int k=i;k<=j-1;k++){
		int tempans=1+Solve(s,i,k)+Solve(s,k+1,j);
		if(tempans<mn)
			mn=tempans;
	}
	return mn;
}

int main(){
	string s;
	cout<<"Enter the string:\t";
	cin>>s;
	cout<<"\nNumber of partitions:\t"<<Solve(s,0,s.length()-1);
	return 0;
}
