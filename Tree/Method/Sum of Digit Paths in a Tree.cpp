/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

void sum(Tree *root, string s, vector<string> &temp) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        s += to_string(root->val);
        temp.push_back(s);
    }
    s += to_string(root->val);
    sum(root->left, s, temp);
    sum(root->right, s, temp);
    return;
}

int solve(Tree *root) {
    if (root == NULL) return 0;
    int ans = 0;
    vector<string> temp;
    sum(root, "", temp);
    for (int i = 0; i < temp.size(); i++) {
        ans += stoi(temp[i]);
    }
    return ans;
}
