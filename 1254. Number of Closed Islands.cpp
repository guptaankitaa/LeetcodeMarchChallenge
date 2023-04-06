class Solution {
public:
    
    int m, n;
    
    bool dfs(vector<vector<int>>& grid, int r, int c){
        
        if(r >= m || r < 0 || c >= n || c < 0)   //out of bound
            return false;        //not closed
            
        if(grid[r][c] == 1){     //water
            return true;         //closed hai is side se
        }  
            grid[r][c] = 1;      //mark visited
            
            bool left_closed = dfs(grid, r, c-1);
            bool right_closed = dfs(grid, r, c+1);
            bool up_closed = dfs(grid, r-1, c);
            bool down_closed = dfs(grid, r+1, c);
            
            return left_closed && right_closed && up_closed && down_closed;    //closed ilaand
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        
        m = grid.size();
        n = grid[0].size();
        
        int count = 0;
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                
                if(grid[i][j] == 0){     //load
                    if(dfs(grid, i, j) == true) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};
