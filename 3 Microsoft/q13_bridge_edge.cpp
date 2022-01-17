/* Problem => Bridge Edge
	Problem Link => https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1
*/

class Solution {
	public:
		int dfs(int src, vector<int>adj[], int c, int d, vector<int>&visited){
	    	visited[src] = 1; 
	    	for(auto dest: adj[src]){
	        	if(src ==  c && dest == d)
	        		continue;
	        	if(!visited[dest])
	            	dfs(dest, adj, c, d, visited);
	        }

	        return 0;
	    }


	    int isBridge(int V, vector<int> adj[], int c, int d) 
    	{

    		 vector<int>visited(V+1,0);
        	 dfs(c, adj, c, d, visited);

        	 return (!visited[d]);
    	}

};

