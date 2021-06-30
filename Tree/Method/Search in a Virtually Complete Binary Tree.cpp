/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
bool solve(Tree* root, int target) {
    if(root == NULL) return false;
    queue<Tree*> pendingNode;
    pendingNode.push(root);
    if(root->val == target) return true;
    while(pendingNode.empty() == false)
    {
        int cnt = pendingNode.size();
        while(cnt--)
        {
            Tree* front = pendingNode.front();
            pendingNode.pop();
            if(front->val == target) return true;
            if(front->left != NULL) pendingNode.push(front->left);
            if(front->right != NULL) pendingNode.push(front->right);
        }
    }

    return false;
}
