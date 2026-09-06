//GFG : Replace O's with X's
//Link : https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1

//Leetcode : 130.Surrounded Regions
// Link : https://leetcode.com/problems/surrounded-regions/


class Solution {
public:
    bool isValid(vector<vector<char>>& board,int i,int j,int m,int n)
    {
        if( i>=0 && i<m && j>=0 && j<n && board[i][j]=='O')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void DFSRec(vector<vector<char>>& board,int i,int j,int m,int n)
    {
        board[i][j] = 'S';
        if(isValid(board,i+1,j,m,n))
            DFSRec(board,i+1,j,m,n);
        if(isValid(board,i-1,j,m,n))
            DFSRec(board,i-1,j,m,n);
        if(isValid(board,i,j+1,m,n))
            DFSRec(board,i,j+1,m,n);
        if(isValid(board,i,j-1,m,n))
            DFSRec(board,i,j-1,m,n);
        
    }
   
    void solve(vector<vector<char>>& board) {
        

        int m = board.size();
        int n = board[0].size();
        
        // first row and first column
        for(int j=0;j<n;j++)
        {
            //first row , row = 0;
            if(board[0][j]=='O')
                DFSRec(board,0,j,m,n);
            
            // last row , row = m-1;
            if(board[m-1][j]=='O')
                DFSRec(board,m-1,j,m,n);
        }

        // first column and last column;

        for(int i=0;i<m;i++)
        {
            // first column, col = 0;
            if(board[i][0]=='O')
                DFSRec(board,i,0,m,n);
            
            // last column , col = n-1;
            if(board[i][n-1]=='O')
                DFSRec(board,i,n-1,m,n);

        }

        // now on board, edge O are changed to S, 
        // we can change O surrounded by X , inside the board to X , easily

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O')
                {
                    board[i][j] = 'X';
                }
                else
                {
                    if(board[i][j]=='S')
                    {
                        //change to back original O
                        board[i][j]='O';
                    }
                }
            }
        }
        
    }
};