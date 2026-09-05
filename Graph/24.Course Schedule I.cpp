//Link : https://leetcode.com/problems/course-schedule/description/
// Comapany : i got this question in Microsoft round 1 interview
// Solved this question and got moved to round 2 interview
// Time Complexity : O(V+E) , V = number of vertices, E = number of edges



class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        int V = numCourses;
        // build adjacency list first

        vector<vector<int>>adj(V);
        for(auto x: prerequisites)
        {
            int u = x[0];
            int v = x[1];
            // there is an edge from v to u;
            // so adj[v].push_back(u)

            adj[v].push_back(u);
        }


        vector<int>indegree(V,0);
        for(auto x:prerequisites)
        {
            int u = x[0];
            int v = x[1];
            // means there is an edge from v to u in [u,v] ( because v should come first before u); ( v ---> u)
            indegree[u]++;
        }

        queue<int>q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        // Topological sorting algo
        int count = 0;
        while(q.empty()==false)
        {
            int u = q.front();
            q.pop();

            for(auto v:adj[u])
            {
                if(--indegree[v]==0)
                {
                    q.push(v);
                }
            }
            count++;
        }

        if(count == V)
        {
            //means all vertices processsed, there is no cycle
            // hence, courses can be taken in order
            return true;
        }
        else
        {
            return false;
        }
        
    }
};

/*
Notes :
1. We use topologic sort here, 
2. At the end, we checking if there is cycle, means we cannot process all vertices
3. hence, we return false, 

This alog" is helpful in DAG 

*/