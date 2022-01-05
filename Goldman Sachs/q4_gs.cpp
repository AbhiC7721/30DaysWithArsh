#include <bits/stdc++.h>
using namespace std;

string encode(string src);    

int main() {

	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;

		cout<<encode(str)<<endl;
	}

	return 0;
}

string encode(string src)
{
	int num =1;
    string ans = "";
    int i;
    for(i=1; i<src.length(); i++){
    	if(src[i]==src[i-1])
            num++;
        else{
            ans+=src[i-1];
            ans+=to_string(num);
            num=1;
            }    
    }
    ans+=src[i-1];
    ans+=to_string(num);

    return ans;
} 