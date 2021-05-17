class Solution {
public:
	vector<string> returnSolutionCur(vector<vector<int> > chess)
	{
		vector<string> ans;
		for(int i=0 ;i<chess.size(); i++)
		{
			string strAns = "";
			for(int j=0; j<chess[0].size(); j++)
			{
				strAns += (chess[i][j] == 0 ? "." : "Q");
			}

			ans.push_back(strAns);

		}

		return ans;
	}
	bool isSafe(vector<vector<int> > chess , int row , int col)
	{
		for(int i = row-1; i>=0 ;i--) {
			if(chess[i][col] == 1) return false;
		}

		for(int i=row-1,j=col-1; i>=0&&j>=0; i--,j--){
			if(chess[i][j] == 1) return false;
		}

		for(int i=row-1,j=col+1; i>=0&&j<chess[0].size(); i--,j++) {
			if(chess[i][j] == 1) return false;
		}

		return true;
	}

	void nQueens(vector<vector<int> > chess , int row  , vector<vector<string> > &Ans)
	{

		if(row == chess.size()) {

			vector<string> currentConfig = returnSolutionCur(chess);
			Ans.push_back(currentConfig);
			return;
		}


		for(int col=0 ;col<chess[0].size(); col++)
		{
			if(isSafe(chess,row,col)) {

				chess[row][col] = 1;
				nQueens(chess,row+1,Ans);
				chess[row][col] = 0; 
			}
		}
	}
    vector<vector<string>> solveNQueens(int n) {
        

    	vector<vector<int> > chess(n,vector<int>(n,0));
    	vector<vector<string> > ans;
    	nQueens(chess,0,ans); return ans;



    }
};
