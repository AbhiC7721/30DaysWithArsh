/*
	problem => First Non repeating character in a stream
	Problem Link https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
*/

class Solution {
public:
	string FirstNonRepeating(string A){
		int n = A.length();
		queue<char>q;
		string ans;

		vector<int>freq(26, 0);
		for(int i=0; i<n; i++){
			freq[A[i]-'a']++;
			if(freq[A[i]-'a']==1)
				q.push(A[i];)
			while(!q.empty() && freq[q.front()-'a']!=1)
				q.pop();

			if(q.empty())
				ans += '#';
			else
				ans += q.front();
		}

		return ans;
	}
}