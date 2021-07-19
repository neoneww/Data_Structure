class Solution {
public:

    int ans(Node *root,int finAns){
        if(root == NULL) return 0;
        finAns = 0;
        for(int i=0;i<root->children.size();i++){
            finAns = max(finAns,ans(root->children[i],finAns));
        }
        return 1 + finAns;
    }

    int maxDepth(Node* root) {
        if(root == NULL) return 0;
        int finAns = 0;
        return ans(root,finAns);
    }
};
