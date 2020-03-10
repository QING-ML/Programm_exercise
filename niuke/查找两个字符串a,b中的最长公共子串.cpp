#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string str_1;
    string str_2;
    while(getline(cin, str_1) && getline(cin, str_2)){
        int row;
        int col;
        vector<char> inverse_result;
        int LongOfSub = 0;
        //str1 short, str2 long
        string str1;
        string str2;
        if(str_1.size() < str_2.size()){
            str1 = str_1;
            str2 = str_2;
        }
        else{
            str1 = str_2;
            str2 = str_1;
        }

        
        int** Array2D = new int* [str1.size()];
        //initialize Array
        for(int i = 0; i < str1.size(); i++){
            Array2D[i] = new int [str2.size()];
        }
        for(int i = 0; i < str1.size(); i++){
            if(i == 0){
                for(int j = 0; j < str2.size(); j++){
                    if(str1[i] == str2[j] ){
                        Array2D[i][j] = 1;
                    }
                    else{
                        Array2D[i][j] = 0;
                    }
                }
            }
            else{
                if(str1[i] == str2[0]){
                    Array2D[i][0] = 1;
                }
                else{
                    Array2D[i][0] = 0;
                }
            }
        }
        //find longest substr
        for(int i = 1; i < str1.size(); i++){
            for(int j = 1; j < str2.size(); j++ ){
                if(str1[i] == str2[j]){
                    Array2D[i][j] = Array2D[i-1][j-1] + 1;
                }
                else{
                     Array2D[i][j] = 0;
                }
                if(Array2D[i][j] > LongOfSub){
                    //judge
                    
                    row = i;
                    col = j;
                    LongOfSub = Array2D[i][j];
                }
            }
        }
        //output
        while(Array2D[row][col]){
            inverse_result.push_back(str1[row]);
            row -= 1;
            col -= 1;
            if(row < 0 || col < 0)
                break;
        }
        for(int i = inverse_result.size() - 1;  i >= 0; i--){
            cout<< inverse_result[i];
        }
        cout << endl;
        delete []Array2D;
    }
}