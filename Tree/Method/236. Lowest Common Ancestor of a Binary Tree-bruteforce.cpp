class Solution
{
public:
    bool nodeToRoot(TreeNode *root, TreeNode *target, vector<TreeNode *> &ans)
    {
        if (root == NULL)
            return false;

        if (root == target)
        {
            ans.push_back(root);
            return true;
        }

        bool res = nodeToRoot(root->left, target, ans) || nodeToRoot(root->right, target, ans);

        if (res)
        {
            ans.push_back(root);
            return true;
        }

        return false;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> temp1;
        vector<TreeNode *> temp2;
        nodeToRoot(root, p, temp1);
        nodeToRoot(root, q, temp2);
        TreeNode *lca = nullptr;
        int i = 0;
        while (i < temp1.size() && i < temp2.size())
        {
            if (temp1[temp1.size() - 1 - i] == temp2[temp2.size() - 1 - i])
            {
                lca = temp1[temp1.size() - 1 - i];
            }
            i++;
        }

        return lca;
    }
};
