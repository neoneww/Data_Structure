class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> temp;
        for(int i=0;i<matrix.size();i++)
        {
            temp.push_back(matrix[i][0]);
        }
        if(temp.size() <= 1)
        {
            for(int i=0;i<matrix.size();i++)
            {
                for(int j=0;j<matrix[i].size();j++)
                {
                    if(matrix[i][j] == target)
                    {
                        return true;
                    }
                }
            }
            
            return false;
        }
        int pp = 0;
        for(int i=1;i<temp.size();i++)
        {
            if(target == temp[i])
            {
                return true;
            }
            
            if(target > temp[i-1] && target < temp[i])
            {
                pp = i-1;
                break;
            }
        }
        
        for(int i=0;i<matrix[pp].size();i++)
        {
            if(matrix[pp][i] == target)
            {
                return true;
            }
        }
        for(int i=0;i<matrix[matrix.size()-1].size();i++)
        {
            if(matrix[matrix.size()-1][i] == target)
            {
                return true;
            }
        }
        
        return false;
    }
};
