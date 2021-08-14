#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
/*
Given an image represented by an M x N matrix, where each pixel in the image is 4 bytes, write a method to rotate the image 90 degrees. 
Can you do this in place?
*/

//O(M x N) time, O(1) space- transpose then rotate
void rotate(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
     
    //transpose
    for(int i = 0; i < rows; i++)
    {
        for(int j = i; j < cols; j++)
            swap(matrix[i][j], matrix[j][i]);
    }
    //reverse
    for(int i = 0; i < rows/2; i++)
    {
        for(int j = 0; j < cols; j++)
            swap(matrix[i][j],matrix[rows-i-1][j]);
    }
}

int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(matrix);
    
    for(int i = 0; i < (int)matrix.size(); i++)
    {
        for(int j = 0; j < (int)matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}