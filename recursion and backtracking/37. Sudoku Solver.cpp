class Solution {
public:

	bool rakhSakteHai(vector<vector<char>>& mat, int i,int j,int n,char num){

		for(int x = 0 ; x < n ; x++){
			if(mat[x][j]==num || mat[i][x]==num) return false; //value agar already exsist karti hai tho false return kardo 
		}
        int rn = 3;
		int sx = (i/3)*3;
		int sy = (j/3)*3;

        //check the submatrix 
		for(int x = sx ; x < sx+rn ; x++){
			for(int y = sy ; y < sy+rn ; y++){

				if(mat[x][y]==num) return false;

			}
		}
		return true;
	}

	bool solve(vector<vector<char>>& board, int i,int j,int n){

		if(i == n) return true;

		if(j == n) return solve(board,i+1,0,n);

		if(board[i][j] != '.') return solve(board,i,j+1,n);


		for(char num = '1' ; num <= '9' ; num++){

			if(rakhSakteHai(board,i,j,n,num)){
				board[i][j] = num;

				if(solve(board,i,j+1,n))return true;

				board[i][j] = '.';
			}

		}
		return false;
	}

	void solveSudoku(vector<vector<char>>& board) {

		int n = board.size();
		solve(board,0,0,n);
		return;

	}
};
