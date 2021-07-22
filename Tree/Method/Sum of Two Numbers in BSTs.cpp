/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

void traverse(Tree *root,unordered_map<int,int> &temp){
    if(root == NULL) return;
    temp[root->val]++;
    traverse(root->left,temp);
    traverse(root->right,temp);
}

bool returnAns(Tree *root,unordered_map<int,int> &temp,int target)
{
    if(root == NULL) return false;
    if(temp.find(target-root->val) != temp.end() || temp.find(root->val-target) != temp.end()){
        return true;
    }
    return returnAns(root->left,temp,target) || returnAns(root->right,temp,target);
}

bool solve(Tree* a, Tree* b, int target) {
    unordered_map<int,int> temp;
    traverse(a,temp);
    return returnAns(b,temp,target);
}
