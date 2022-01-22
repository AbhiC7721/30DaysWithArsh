/*
	Problem => Ammend the sentence
	Problem Link => https://practice.geeksforgeeks.org/problems/amend-the-sentence3235/1
*/

class Solution {
public:
	string ammendSentence(string s){
		string ans = "";
		for(int i=0; i<s.length(); i++){
			if(isupper(s[i]) && i!=0)
				ans += " ";
			ans += tolower(s[i]);
		}

		return ans;
	}
};