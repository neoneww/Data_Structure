class Solution {
public:
    
    bool getNodetoRootPath(TreeNode *root,TreeNode *target,vector<TreeNode*> &paths) {
        if(root == NULL) return false;

        if(root == target) {
            paths.push_back(target);
            return true;
        }
        bool res = getNodetoRootPath(root->left,target,paths) || getNodetoRootPath(root->right,target,paths);

        if(res){
            paths.push_back(root);
            return true;
        }

        return false;

    }

    void getKdown(TreeNode *root,TreeNode *block,int k,vector<int> &ans)
    {
        if(root == NULL || k < 0 || root == block)  return;
        if(k==0){
            ans.add(root->val);
            return;
        }
        getKdown(root->left,block,k-1,ans);
        getKdown(root->right,block,k-1,ans);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> path,ans;
        getNodetoRootPath(root,target,path);
        TreeNode *block = NULL;
        for(int i=0;i<path.size();i++){
            getKdown(path[i],block,k-i,ans);
            block = path[i];
        }
        return ans;
    }
};



