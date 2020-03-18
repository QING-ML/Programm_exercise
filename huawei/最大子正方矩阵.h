//最大子正方矩阵
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> map;
        int LongOfedge = 0;
        //initialize
        for(int i = 0; i < matrix.size(); i++){
            map.push_back(vector<int>());
            if(i == 0){
                for(int j = 0; j < matrix[i].size(); j++){
                    if(matrix[i][j] == '0'){
                         map[i].push_back(0);
                    }
                    else{
                        map[i].push_back(1);
                        LongOfedge = 1;
                    }
                }
            }
            else{
                for(int j = 0; j < matrix[i].size(); j++){
                    if(j == 0){
                        if(matrix[i][j] == '0'){
                            map[i].push_back(0);
                        }
                        else{
                            map[i].push_back(1);
                            LongOfedge = 1;
                        }
                    }
                    else{
                        map[i].push_back(0);
                    }
                }
            }
        }
        
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j< matrix[i].size(); j++){
                if(matrix[i][j] == '1'){
                    map[i][j] = min(map[i-1][j], min(map[i-1][j-1], map[i][j-1])) + 1;
                    if(map[i][j] > LongOfedge){
                        LongOfedge = map[i][j];
                    }                    
                }
                else{
                    map[i][j] = 0;
                }
            }
        }
        return LongOfedge * LongOfedge;
    }
};