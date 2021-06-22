/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
// map contains row and pair of column and val
void Traverse(Tree *root, map<int, pair<int, int>> &temp, int x, int y) {  // x -> row y->col
    if (root == NULL) return;
    if (temp.find(x) == temp.end() or y < temp[x].first) {
        temp[x] = make_pair(y, root->val);
    }
    Traverse(root->left, temp, x - 1, y + 1);
    Traverse(root->right, temp, x + 1, y + 1);
}
vector<int> solve(Tree *root) {
    vector<int> ans;
    map<int, pair<int, int>> temp;
    if (root == NULL) return ans;
    Traverse(root, temp, 0, 0);
    for (auto i : temp) {
        ans.push_back(i.second.second);
    }
    return ans;
}
