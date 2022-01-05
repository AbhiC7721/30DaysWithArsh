#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
	string printMinNumberForPattern(string s){
		string ans =  "";
		int i =0, digit =1, dec=0, j, k;
		while(i<s.length()){

			if(i==0 && s[i]=='I'){
				ans += to_string(digit);
				digit++;
			}

			if(s[i]=='D')
				dec++;

			j = i+1;
			while(j < s.legnth() && s[j]=='D'){
				dec++;
				j++;
			} 

			k = dec;
			while(dec>=0){
				ans += to_string(cur+dec);
				dec--;
			}

			digit += (k+1);
			dec=0;
			i = j;
		}

		return ans;
	}

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		Solution ob;
		cout << ob.printMinNumberForPattern(S) << endl;
	}

	return 0;
}