/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
vector<int> solve(Tree* root) {
    vector<int> ans;
    if (root == NULL) return ans;

    queue<Tree*> pendingNode;
    pendingNode.push(root);

    while (pendingNode.empty() == false) {
        int cnt = pendingNode.size();
        int sum = 0;
        while (cnt--) {
            Tree* front = pendingNode.front();
            pendingNode.pop();
            while (front != NULL) {
                if (front->left != NULL) {
                    pendingNode.push(front->left);
                }
                sum += front->val;
                front = front->right;
            }
        }
        ans.push_back(sum);
    }
    return ans;
}
