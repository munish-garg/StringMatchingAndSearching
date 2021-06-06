//In recursive approaches or dp....
//We must only know that the how to break the problem into subroblems..
//And how to attain the answer at that instant or that state..
//The recursive algorithm which you have written in the form of code will compute for all the cases...
#include<bits/stdc++.h>
#define int long long int 
using namespace std;
int lcs(string a, string b, int i, int j){
	if(i==a.size() || j==b.size()){
		return 0;
	}
	int op1, op2;
	op1 = op2 = 0;
	if(a[i] == b[j])
		return 1 + lcs(a, b, i+1, j+1);
	op1 = lcs(a, b, i, j+1);
	op2 = lcs(a, b, i+1, j);
	return max(op1, op2);
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	string a, b;
	cin>>a>>b;
	int ans = lcs(a, b, 0, 0);
	cout<<ans<<endl;
	return 0;
}