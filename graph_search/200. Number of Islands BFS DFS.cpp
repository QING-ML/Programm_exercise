class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int island_num = 0;
        vector<vector<int>> Mark;
        //initialize Mark
        for(int i = 0; i < grid.size(); i++){
            Mark.push_back(vector<int>());
            for(int j = 0; j < grid[i].size(); j++){
                Mark[i].push_back(0);             
            }
        }
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(Mark[i][j] == 0 && grid[i][j] == '1'){
                    BFS(Mark, grid, i, j);
                    island_num ++;
                }
            }
        }
        return island_num;
    }

private:
    void DFS(vector<vector<int>> &Mark, vector<vector<char>>& grid,
       int x, int y){
        Mark[x][y] = 1;
        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};
        for(int i = 0; i < 4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(new_x < 0 || new_x >= grid.size() ||
              new_y < 0 || new_y >= grid[new_x].size() ){
                continue;
            }
            
            if(Mark[new_x][new_y] == 0 && grid[new_x][new_y] == '1'){
                DFS(Mark, grid, new_x, new_y);
            }
        }
    }
    void BFS(vector<vector<int>> &Mark, vector<vector<char>>& grid,
       int x, int y){
        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};
        queue<pair<int, int>> Q;
        Q.push(make_pair(x,y));
        while(!Q.empty()){
            x = Q.front().first;
            y = Q.front().second;
            Q.pop();
            
            Mark[x][y] = 1;
            for(int i = 0; i < 4; i++){
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if(new_x < 0 || new_x >= grid.size() ||
                    new_y < 0 || new_y >= grid[new_x].size() ){
                continue;
                }
                if(Mark[new_x][new_y] == 0 && grid[new_x][new_y] == '1'){
                    Q.push(make_pair(new_x, new_y));
                }                
            }
        }
    }
};