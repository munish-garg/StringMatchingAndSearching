//size -> the array containing the size of each item...
//value -> the array conyaining the value of each item...
//items -> the number of items...
//C -> the size of the bag...
//max-value -> the capacity of the bag utilized till that state...
#include<bits/stdc++.h>
#define int long long int
using namespace std;
int knapsackSolution(int* size, int* value, int items, int C, int i, int j, int max_value){
	if(C == 0 || items == 0){
		//base case..
		return 0;
	}
	int op1, op2;
	op1 = op2 = INT_MIN;
	if(max_value + size[i]<=C){
		op1 = value[i] + knapsackSolution(size, value, items-1, C-size[i], i+1, j+1,max_value + size[i]);		
	}
	op2 = knapsackSolution(size, value, items-1, C, i+1, j+1, max_value);
	return max(op1, op2);
}
int32_t main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,s;
	//n-> the total number of values..
	//s-> the size of the bag...
	cin>>n>>s;
	int size[n];
	int value[n];
	for(int i=0;i<n;i++) cin>>size[i];
	for(int i=0;i<n;i++) cin>>value[i];
	int max_value = 0;
	int ans = knapsackSolution(size, value, n, s, 0, 0, max_value);
	// cout<<"Execution has reached here again..";
	cout<<ans<<endl;
	return 0;
}