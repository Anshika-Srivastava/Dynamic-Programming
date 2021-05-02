#include<iostream>
#define MAX 5
using namespace std;

int knapsack(int wt[], int val[], int n, int W){
	int t[n+1][W+1];
	for(int i=0;i<n+1;i++)
		for(int j=0;j<W+1;j++)
			if(i==0||j==0)
				t[i][j]=0;
	
	for(int i=0;i<n+1;i++)
		for(int j=0;j<W+1;j++){
			if(wt[i-1]<=j){
				t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
			}
			else
				t[i][j]=t[i-1][j];
		}
		
	return t[n][W];
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

Time Complexity: O(N*W). 
where ‘N’ is the number of weight element and ‘W’ is capacity.
As for every weight element we traverse through all weight capacities 1<=w<=W.
 
Auxiliary Space: O(N*W). 
The use of 2-D array of size ‘N*W’.*/
