#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeStr(const string& s, int& i) {
        string res;
        
        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i]))
                res += s[i++];
            else {
                int n = 0;
                while (i < s.length() && isdigit(s[i]))
                    n = n * 10 + s[i++] - '0';
                    
                i++; // '['
                string t = decodeStr(s, i);
                i++; // ']'
                
                while (n-- > 0)
                    res += t;
            }
        }
        
        return res;
    }

    string decodedString(string s) {
        int i = 0;
        return decodedStr(s, i);
    }
};

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
        cin>>s;

        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
	}

    return 0;
}