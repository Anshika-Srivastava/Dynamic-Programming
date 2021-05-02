#include<iostream>
#include <cstring>
#define MAX 5
using namespace std;
int t[MAX+1][MAX+1];

int knapsack(int wt[], int val[], int n, int W){
	if(n==0||W==0)
		return 0;
	if(t[n][W]!=-1)
		return t[n][W];
	if(wt[n-1]<=W){
		return t[n][W]=max(val[n-1]+knapsack(wt,val,n-1,W-wt[n-1]),knapsack(wt,val,n-1,W));
	}
	else
		return t[n][W]=knapsack(wt,val,n-1,W);
}


int main(){
	int wt[MAX], val[MAX], n, W, profit;
	cout<<"Enter no. of objects: "<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Enter weight for object "<<i+1<<" : "<<endl;
		cin>>wt[i];
		cout<<"Enter value for object "<<i+1<<" : "<<endl;
		cin>>val[i];
	}
	cout<<"Enter weight of the bag: "<<endl;
	cin>>W;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= W; j++)
			t[i][j] = -1;
	profit = knapsack(wt,val,n,W);
	cout<<"Maximum profit will be: "<<profit<<endl;
	return 0;
}
/*Complexity Analysis: 

Time Complexity: O(N*W). 
As redundant calculations of states are avoided.

Auxiliary Space: O(N*W). 
The use of 2D array data structure for storing intermediate states-:*/
