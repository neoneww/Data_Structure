/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
    TreeNode *makeTree(vector<int> &pre, int psi, int pei, vector<int> &ino, int isi, int iei)
    {
        if (psi > pei)
            return NULL;

        int idx = isi;
        while (ino[idx] != pre[psi])
        {
            idx++;
        }
        int tnel = idx - isi;
        TreeNode *root = new TreeNode(pre[psi]);
        root->left = makeTree(pre,psi+1,psi+tnel,ino,isi,idx-1);
        root->right = makeTree(pre,psi+tnel+1,pei,ino,idx+1,iei);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if(preorder.size() == 0) return NULL;
        int n = preorder.size();
        return makeTree(preorder,0,n-1,inorder,0,n-1);
    }
};
