//Link :https://leetcode.com/problems/course-schedule-ii/description/

// this is same like course schedule 1 but here we have to return the order of courses in which we can take the courses

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
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
        vector<int>result;
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
            result.push_back(u);

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
            return result;
        }
        else
        {
            result.clear();
            return result;
        }
    }
};