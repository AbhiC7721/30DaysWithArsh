#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:

	int CountWays(string s){
		int n = s.length();
		vector<long long>dp(n+1, 0);
		dp[0] = 1;
		if(s[0]=='0')
            dp[1] = 0;
        else
            dp[1] = 1;
        int opt1, opt2;
        for(int i=2; i<=n; i++){
            opt1 = stoi(s.substr(i-1, 1));
            opt2 = stoi(s.substr(i-2, 2));
            if(opt1>=1 && opt1<=9)
                dp[i] = (dp[i] + dp[i-1])%((long long)1e9+7);
            if(opt2>=10 && opt2<=26)
                dp[i] = (dp[i] + dp[i-2])%((long long)1e9+7);
        }
        
        return dp[n]%((long long)1e9+7);
    }

};

int main(){
	int tc;
	cin>>tc;
	while(t--){
		string str;
		cin>>str;
		Solution obj;
		int ans = obj.Countways(str);
		cout<<ans<<"\n";
	}
	return 0;
}