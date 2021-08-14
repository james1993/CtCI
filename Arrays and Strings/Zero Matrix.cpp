#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
/*
Write an algorithm such that if an element in an M x N matrix is 0, its entire row and column are set to 0.
*/

//O(M x N) time, O(1) space- use first row and col as marker
    void setZeroes(vector<vector<int>>& matrix) {
        bool is_first_row_zero = false;
        bool is_first_col_zero = false;
        
        for(int i = 0; i < (int)matrix[0].size(); i++)
            if(matrix[0][i] == 0) is_first_row_zero = true;
        for(int i = 0; i < (int)matrix.size(); i++)
            if(matrix[i][0] == 0) is_first_col_zero = true;
        
        for(int i = 1; i < (int)matrix.size(); i++)
        {
            for(int j = 1; j < (int)matrix[i].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < (int)matrix.size(); i++)
        {
            for(int j = 1; j < (int)matrix[i].size(); j++)
                if(matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
        }
        if(is_first_row_zero)
        {
            for(int i = 0; i < (int)matrix[0].size(); i++)
                matrix[0][i] = 0;
        }
        if(is_first_col_zero)
        {
            for(int i = 0; i < (int)matrix.size(); i++)
                matrix[i][0] = 0;
        }
    }

int main() {
    vector<vector<int>> matrix = {{0,1,1},{1,1,1},{1,1,0}};
    setZeroes(matrix);
    
    for(int i = 0; i < (int)matrix.size(); i++)
    {
        for(int j = 0; j < (int)matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}