/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

// we have to return wheter the target is a sub tree of the tree

bool check(Tree* a, Tree* b)  // function to check for subtree
{
    if (a == NULL && b == NULL) {
        return true;
    }
    if (a != NULL && b == NULL || a == NULL && b != NULL) {
        return false;
    }
    if (a->val != b->val) {
        return false;
    }

    return check(a->left, b->left) && check(a->right, b->right);
}

Tree* rootRet(Tree* a, Tree* b) {
    if (a == NULL) {
        return NULL;
    }
    if (a->val == b->val) {
        return a;
    }
    Tree* c = rootRet(a->left, b);
    Tree* d = rootRet(a->right, b);

    if (c != NULL) {
        return c;
    }

    return d;
}

bool solve(Tree* root, Tree* target)
{
    root = rootRet(root,target);
    return check(root,target);
}
