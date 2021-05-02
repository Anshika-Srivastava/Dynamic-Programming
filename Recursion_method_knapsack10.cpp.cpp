#include<iostream>
#define MAX 5
using namespace std;
int knapsack(int wt[], int val[], int n, int W){
	if(n==0||W==0)
		return 0;
	if(wt[n-1]<=W){
		return max(val[n-1]+knapsack(wt,val,n-1,W-wt[n-1]),knapsack(wt,val,n-1,W));
	}
	else
		return knapsack(wt,val,n-1,W);
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
	profit = knapsack(wt,val,n,W);
	cout<<"Maximum profit will be: "<<profit<<endl;
	return 0;
}

/*Complexity Analysis: 

Time Complexity: O(2n). 
As there are redundant subproblems.

Auxiliary Space :O(1). 
As no extra data structure has been used for storing values.*/

