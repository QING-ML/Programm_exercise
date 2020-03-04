#include <vector>
#include <string>
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<vector<int>> mark;
        vector<string> location;
        //initialize map and location
        for(int i = 0; i < n; i++){
            mark.push_back(std::vector<int>()); // !!!error initialize
            for(int j = 0; j < n; j++){
                mark[i].push_back(0); //build map
            }
            location.push_back("");// !!!! initialize            
            location[i].append(n, '.');
            //location.push_back("");
        }
        generate(0, n, mark, location, result);
        return result;
    }
private:
    void put_down_queen(int x, int y,
                       vector<vector<int>> &mark){
        static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
        mark[x][y] = 1;
        for(int i = 1; i < mark.size(); i++){
            for(int j = 0; j < 8; j++){
                int new_x = x + i * dx[j];
                int new_y = y + i * dy[j];
                if(new_x >= 0 && new_x < mark.size() &&
                  new_y >= 0 && new_y < mark.size()){
                    mark[new_x][new_y] = 1;
                }
            }
            
        }
        
    }
    
    void generate(int k, int n, vector<vector<int>> &mark, 
                  vector<string> &location,
                 vector<vector<string>> &result){
        if( k == n ){
            result.push_back(location);
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(mark[k][i] == 0){
                vector<vector<int>> temp_mark = mark;
                location[k][i] = 'Q';
                put_down_queen(k, i, mark);
                generate(k+1, n, mark, location, result);
                mark = temp_mark;
                location[k][i] = '.';
                
            }
        }
    }

};
