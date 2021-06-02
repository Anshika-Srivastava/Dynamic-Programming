//Unbounded knapsack
#include<bits/stdc++.h>

using namespace std;

int unKnapsack(int wt[], int val[], int n, int W){
	int t[W+1];
	memset(t, 0, sizeof t);
	
	for (int i=0; i<=W; i++)
      for (int j=0; j<n; j++)
         if (wt[j] <= i)
            t[i] = max(t[i], t[i-wt[j]] + val[j]);
		
	return t[W];
}

int main(){
	int n,W;
	cout<<"Please enter number of objects:\t"<<endl;
	cin>>n;
	int wt[n], val[n];
	for(int i=0;i<n;i++){
		cout<<"Enter weight and value of object "<<i<<endl;
		cin>>wt[i]>>val[i];
	}
	cout<<"Enter weight of knapsack";
	cin>>W;
	cout<<unKnapsack(wt,val,n,W);
	return 0;
}
