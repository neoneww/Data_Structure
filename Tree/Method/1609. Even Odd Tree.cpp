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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> pendingNode;
        pendingNode.push(root);
        if(root->val % 2 == 0) return false;
        int cnt1 = 0;
        
        while(pendingNode.empty() == false)
        {
            cnt1++;
            vector<int> a;
            int cnt = pendingNode.size();
            while(cnt--)
            {
                TreeNode *front = pendingNode.front();
                pendingNode.pop();
                
                if(front->left != NULL)
                {
                    pendingNode.push(front->left);
                    a.push_back(front->left->val);
                }
                
                if(front->right != NULL)
                {
                    pendingNode.push(front->right);
                    a.push_back(front->right->val);
                }
            }
            if(cnt1%2 != 0 && a.size() > 1)
            {
                for(int i=1;i<a.size();i++)
                {
                    if(a[i]%2 != 0) return false;
                    if(a[i] >= a[i-1]) return false;
                }
            }
            else if(cnt1%2 ==0 && a.size() > 1)
            {
                for(int i=1;i<a.size();i++)
                {
                    if(a[i]%2 == 0) return false;
                    if(a[i] <= a[i-1]) return false;
                }
            }
            if(a.size() == 1)
            {
                cout<<cnt1 <<" "<<a[0]<<"\n";
                if(cnt1%2 != 0 && a[0]%2 != 0) return false;
                if(cnt1%2 == 0 && a[0]%2 == 0) return false;
            }

        }
        
        return true;
    }
};
