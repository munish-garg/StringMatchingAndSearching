#include<bits/stdc++.h>
#define int long long int
#define MAX 1000001 
using namespace std;
int32_t main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> prime(MAX);
	int n = prime.size();
	for(int i=0;i<n;i++){
		//Marking all the numbers as prime..
		prime[i] = 1;
	}
	prime[0] = prime[1] = 0;
	for(int i=2;i<n;i++){
		for(int j = i*i;j<n;j+=i){
			prime[j] = 0;
		}
	}
	int t; cin>>t;
	while(t--){
		int l, r; cin>>l>>r;
		int size = r-l+1;
		int a[size];
		for(int i=0;i<size;i++) a[i] = 1;
		for(int i=l;i<=r;i++){
			for(int j=2;j<=sqrt(i);j++){
				if(i%j==0){
					//It means that the particular number is not prime..
					a[i-l] = 0;
					break;
				}
			}
		}
		for(int i=0;i<size;i++){
			if(a[i] == 1 and l+i!=1){
				int ans = l+i;
				cout<<ans<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}