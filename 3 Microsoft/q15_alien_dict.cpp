/*
	Problem => Alien Dictionary
	Problem Link => https://practice.geeksforgeeks.org/problems/alien-dictionary/1/
*/

class Soution {

	void topoSort(int src, vector<int>& adj[], vector<int>&visited, stack<int>&s){
		visited[src] = 1;
		for(int i=0; i<adj[src].size(); i++){
			if(!visited[adj[src][i]])
				topoSort(adj[src][i], adj, visited, s);
		}

		s.push(src);
	}

	string findOrder(string dict[], int N, int K){
		vector<int>adj[K];
		int u, v;
		for(int i=0; i<N; i++){
			string str1 = dict[i-1];
			string str2 = dict[i];
			for(int j=0; j<min(str1.size(), str2.size()); j++){
				if(str1[j] != str2[j]){
					u = str1[j] - 'a';
					v = str2[j] - 'a';
					adj[u].push_back(v);
					// break because the characters after the dissimilar character doesn't matter
					break;
				}
			}
		}
		
		vector<int>visited(K, 0);
		stack<int>s;

		for(int i=0; i<n; i++){
			if(!visited[i])
				topoSort(i, adj, visited, s);
		}

		string ans = "";
		while(!s.empty()){
			ans += (char)(s.top() + 'a');
			s.pop();
		}

		return ans;
	}

	

	
	
};