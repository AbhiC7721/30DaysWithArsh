#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
typedef long long ll;
class Solution{
public:	
	ull getNthUglyNo(int n) {
	    int p2=0, p3=0, p5=0;
	    vector<ll>dp(n, 0);
	    dp[0] = 1;
	    for(int i=1; i<n; i++){
	        ll v2 = dp[p2]*2;
	        ll v3 = dp[p3]*3;
	        ll v5 = dp[p5]*5;
	        ll mini =  min(v2, min(v3, v5));
	        dp[i] = mini;
	        if(mini == v2)
	            p2++;
	        if(mini == v3)
	            p3++;
	        if(mini == v5)
	            p5++;
	    }
	    
	    	return dp[n-1];
	}
};

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>> n;
		auto ans = ob.getNthUglyNo(n);
		cout<<ans<<"\n";
	}

	return 0;
}