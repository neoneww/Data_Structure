// we have to return the no of config of valid nqueen config 

class Solution {
public:

    bool isSafeConfig(vector<vector<string>> &chess,int row,int col)
    {
        for(int i = row-1; i>=0 ;i--) {
			if(chess[i][col] == "Q") return false;
		}

		for(int i=row-1,j=col-1; i>=0&&j>=0; i--,j--){
			if(chess[i][j] == "Q") return false;
		}

		for(int i=row-1,j=col+1; i>=0&&j<chess[0].size(); i--,j++) {
			if(chess[i][j] == "Q") return false;
		}

		return true;

    }

    void noOfConfig(set<vector<vector<string>>> &temp,vector<vector<string>> &map,int row)
    {
        if(row == map.size())
        {
            temp.insert(map);
            return;
        }

        for(int col=0;col<map.size();col++)
        {
            if(isSafeConfig(map,row,col) == true)
            {
                map[row][col] = "Q";
                noOfConfig(temp,map,row+1);
                map[row][col] = ".";
            }
        }
    }
    int totalNQueens(int n)
    {
        set<vector<vector<string>>> temp;   // no of valid config
        vector<vector<string>> map(n,vector<string>(n,"."));   //this is a map
        
        noOfConfig(temp,map,0);

        return temp.size();
    }
};
