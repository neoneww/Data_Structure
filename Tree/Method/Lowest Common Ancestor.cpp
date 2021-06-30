/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
bool nodeToRootPath(Tree *root, int data, vector<int> &ans) {
    if (root == NULL) return false;
    if (root->val == data) {
        ans.push_back(root->val);
        return true;
    }
    bool qq = nodeToRootPath(root->left, data, ans) || nodeToRootPath(root->right, data, ans);
    if (qq) {
        ans.push_back(root->val);
    }
    return qq;
}

int solve(Tree *root, int a, int b) {
    vector<int> p, q;
    nodeToRootPath(root, a, p);
    nodeToRootPath(root, b, q);
    int lac = 0;
    cout<<p.size()<<q.size()<<"\n";
    for (int i = 0; i < p.size(); i++) {
        if (i == q.size()) break;
        if (p[p.size()-1-i] == q[q.size()-1-i]) {
            lac = p[p.size()-1-i];
        }else{
            break;
        }
    }
    return lac;
}
