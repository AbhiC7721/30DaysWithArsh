/*
	Problem => Course Schedule 2
	Problem Link => https://leetcode.com/problems/course-schedule-ii/
*/

class Solution {
public:
    
    // This is basically toposort using a bfs bsed approach
    // This approach basically uses a degree to maintain the topological ordering of all the vertices
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // taking graph in the form of a adjacency list
        vector<vector<int>>adj(numCourses);
        
        vector<int>toposort;
        
        //construct the graph and also degree of each vertex
        //this helps in turn to create the 
        vector<int>degree(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            degree[prerequisites[i][0]]++;
        }
        
        // push all thedegree 0 vertices at first
        for(int i=0; i<numCourses; i++){
            if(degree[i]==0)
                toposort.push_back(i);
        }
        
        // with all the degree 0 vertices, push all the corresponding 
        // vertices to the toposort and then the corresponding vertices
        // in order of their degree.
        for(int i=0; i<toposort.size(); i++){
            for(auto j:adj[toposort[i]]){
                degree[j]--;
                if(degree[j]==0){
                    toposort.push_back(j);
                }
            }
        }
        
        if(toposort.size()<numCourses)
            return {};
        
        // for(auto i: toposort)
        //     cout<<i<<" ";
        
        return toposort;
    }
};