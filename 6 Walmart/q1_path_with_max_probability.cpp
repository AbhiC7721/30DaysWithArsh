/*
    Problem => Path with maximum probability
    Problem Link => https://leetcode.com/problems/path-with-maximum-probability/
*/

class Solution {
public:
    
    void dijkstraOptimized(int src, vector<vector<pair<int, double>>>& graph, vector<double>&dist, vector<bool>&visited){
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        
        pq.push(make_pair(0, src));
        dist[src] = 0;
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            visited[u] = true;
            for(auto v: graph[u]){
                if(!visited[v.first] && dist[v.first] > dist[u] + v.second){
                    dist[v.first] = dist[u] + v.second;
                    pq.push(make_pair(dist[v.first], v.first));
                }
            }
            
        }
    }
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>>graph(n);
        vector<double>dist(n, INT_MAX);
        vector<bool>visited(n, false);
        int u, v;
        double p;
        
        for(int i=0; i<edges.size(); i++){
            p = -log10(succProb[i]);
            u = edges[i][0];
            v = edges[i][1];
            graph[u].push_back(make_pair(v, p));
            graph[v].push_back(make_pair(u, p));
        }
        
        dijkstraOptimized(start, graph, dist, visited);
        if(dist[end]==INT_MAX)
            return 0.0;
        return pow(10, -dist[end]);
    }
};
