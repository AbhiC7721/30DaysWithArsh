/*
	Problem => Prerequisite tasks
	Problem Link => https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/
*/

class Solution {
	public:
		bool isPossible(int n, vector<pair<in, int>>& prerequisites){
			vector<vector<int>>graph(n);
		    vector<int> deg(n, 0);
		    vector<int>bfs;
	    	for(auto x: prerequisites){
	    		graph[x.second].push_back(x.first);
	        	deg[x.first]++;
	    	}

	    	for(int i=0; i<n; i++){
	        	if(!deg[i])
	        		bfs.push_back(i);
	    	}

	    	for(int i=0; i<bfs.size(); i++){
	     	  for(int j: graph[bfs[i]])
	     	  	if(--deg[j]==0) bfs.push_back(j);
	    	}

	    	return bfs.size() == n;
		} 
};