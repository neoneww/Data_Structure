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
class Solution {
public:
// simple bfs find the max of each level
// we are also goint to store the level
    int maxLevelSum(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        int sum = root->val;
        int level = 1;
        int curlevel = 1;
        queue<TreeNode*> pendingNode;
        queue<TreeNode*> removal;
        pendingNode.push(root);

        while(pendingNode.empty() != true)
        {
            int cnt = pendingNode.size();
            while(cnt--)
            {
                TreeNode *front = pendingNode.front();
                pendingNode.pop();
                if(front->left != NULL)
                {
                    pendingNode.push(front->left);
                    removal.push(front->left);
                }
                if(front->right != NULL)
                {
                    pendingNode.push(front->right);
                    removal.push(front->right);
                }
            }
            if(pendingNode.size() > 0)
            {
                curlevel++;
            }
            int ans = 0;
            while(removal.empty() != true)
            {
                TreeNode *lol = removal.front();
                removal.pop();
                ans+=lol->val;
            }
            if(sum < ans)
            {
                sum = ans;
                level = curlevel;
            }
        }
        return level;
    }
};
