/**********************************************************
    Following is the Binary Tree Node class structure.

    template <typename T>
    class BinaryTreeNode {
    public :
	    T data;
	    BinaryTreeNode<T> *left;
	    BinaryTreeNode<T> *right;

	    BinaryTreeNode(T data) {
	        this -> data = data;
	        left = NULL;
	        right = NULL;
	    }
    };

***********************************************************/
#include<bits/stdc++.h>

vector<vector<int>> diognal(BinaryTreeNode<int>* root){
    vector<vector<int>> ans;
    queue<BinaryTreeNode<int>*> pendingNode;
    pendingNode.push(root);
    
    while(pendingNode.empty() == false){
        int cnt = pendingNode.size();
        vector<int> temp;
        while(cnt--){
            BinaryTreeNode<int>* front = pendingNode.front();
            pendingNode.pop();
            while(front != NULL){
                temp.push_back(front->data);
                if(front->left != NULL){
                    pendingNode.push(front->left);
                }
                front = front->right;
            }
        }
            sort(temp.begin(),temp.end());
          ans.push_back(temp);
    }
      return ans;
}

bool diagonalAnagram(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
   if(root1 == NULL && root2 == NULL) return true;
   if(root1 != NULL && root2 == NULL || root1 == NULL && root2 != NULL) return false;
   vector<vector<int>> ans1,ans2;
    ans1 = diognal(root1);
    ans2 = diognal(root2);
    if(ans1.size() != ans2.size()) return false;
    
    for(int i=0;i<ans1.size();i++){
        if(ans1[i].size() != ans2[i].size()) return false;
        for(int j=0;j<ans1[i].size();j++){
            if(ans1[i][j] != ans2[i][j]) return false;
        }
    }
    return true;
}

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
