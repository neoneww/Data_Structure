vector<vector<int>> solve(vector<vector<int>>& matrix)
{
    vector<vector<int>> temp(matrix.size(),vector<int> (matrix.size()));
    int n = matrix.size();
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[i].size();j++)
        {
            temp[n-1-j][n-1-i] = matrix[i][j];
        }

       // reverse(temp[n-1-i].begin(),temp[n-1-i].end());
    }   
    for(int i=0;i<temp.size();i++)
    {
        reverse(temp[i].begin(),temp[i].end());
    }
    return temp;
}

// all horizontal are converted to vertical
