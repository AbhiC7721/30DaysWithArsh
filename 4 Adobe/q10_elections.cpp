/*
	Problem => Eelctions
	Problem Link => https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1/
*/

class Solution {
	static bool compare(pair<string,int>a. pair<string, int>b){
		if(a.second>b.second){
            return true;
        }
        else if(a.second ==  b.second)
            return a.first < b.first;   
        else
            return false;
	}
	
	vector<string> winner(string arr[],int n)
    {
    	map<string, int>mp;
        for(int i=0; i<n; i++){
        	mp[arr[i]]++;
        }

        string name;
        int maxi = 0;
        vector<pair<string,int>>v;
        for(auto it: mp)
        	v.push_back(it);
        sort(v.begin(), v.end(), compare);
        
        string votes = to_string(v[0].second);
        return {v[0].first, votes};
    }
};