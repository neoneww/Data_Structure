vector<vector<int>> solve(vector<vector<int>>& matrix) {
    for(int i=0;i<matrix.size();i++)
    {
        reverse(matrix[i].begin(),matrix[i].end());
    }

    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[i].size();j++)
        {
            if(matrix[i][j] == 1)
            {
                matrix[i][j] = 0;
            }
            else
            {
                matrix[i][j] = 1;
            }
        }
    }

    return matrix;
}
