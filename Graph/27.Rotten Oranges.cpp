//Link : https://leetcode.com/problems/rotting-oranges/
// We follow BFS here, because in one instance all rotten oranges spread simultaneously every minute.
// So we need to process oranges level by level : That's exactly what BFS + Queue does.
// One BFS level = one minute.

class Solution {
public:

    bool isValid(vector<vector<int>>& grid,int i,int j,int m,int n)
    {
        if(i>=0 && i<m && j>=0 && j<n && grid[i][j]==1)
        {
            return true;
        }
        return false;
    }

    int orangesRotting(vector<vector<int>>& grid) {

        // we follow BFS here, because in one instance all rotten oranges spread ////simultaneously every minute.
        //So we need to process oranges level by level : That's exactly what BFS + Queue does.
        // // One BFS level = one minute.

        int m = grid.size();
        int n = grid[0].size();

        int fresh = 0;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    fresh++;
                }
                else
                {
                    if(grid[i][j]==2)
                    {
                        //if rotten add to queue 
                        q.push({i,j});
                    }
                }
            }
        }
        if(fresh==0)
        {
            // if no fresh oranges present, time will be 0 ; 
            return 0 ;

        }

        // process queue level by level - BFS
        int time = 0;
        while(q.empty()==false && fresh>0)
        {

            int size = q.size();

            while(size!=0)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                if(isValid(grid,i,j+1,m,n))
                {
                    grid[i][j+1] = 2;
                    fresh--;
                    q.push({i,j+1});
                }
                if(isValid(grid,i,j-1,m,n))
                {
                    grid[i][j-1] = 2;
                    fresh--;
                    q.push({i,j-1});
                }
                if(isValid(grid,i+1,j,m,n))
                {
                    grid[i+1][j] = 2;
                    fresh--;
                    q.push({i+1,j});
                }
                if(isValid(grid,i-1,j,m,n))
                {
                    grid[i-1][j] = 2;
                    fresh--;
                    q.push({i-1,j});
                }
                size--;
            }
            time++;
        }

        if(fresh==0)
            return time;
        else
            return -1;

    }
};