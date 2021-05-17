bool check(vector<vector<int>> &matrix,int row,int col,int val)
{
    unordered_set<int> temp;
    int sx = (row/3)*3;
    int sy = (col/3)*3;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            temp.insert(matrix[sx+i][sy+j]);
        }
    }

    for(int i=1;i<=9;i++)
    {
        if(temp.find(i) == temp.end())
        {
            return false;
        }
    }

    int pp = matrix[row][col];
    matrix[row][col] = -1;
    for(int i=0;i<matrix.size();i++)
    {
        if(matrix[i][col] == val || matrix[row][i] == val)
        {
            return false;
        }
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(matrix[i+sx][j+sy] == val)
            {
                return false;
            }
        }
    }

    matrix[row][col] = pp;
    return true;
}



bool solve(vector<vector<int>>& matrix)
{
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix.size();j++)
        {
            if(check(matrix,i,j,matrix[i][j]) == false)
            {
                return false;
            }
        }
    }

    return true;

}





/*
    my stratergy is to first check each submatrix and check if it contains all the number from 1 to 9
*/
