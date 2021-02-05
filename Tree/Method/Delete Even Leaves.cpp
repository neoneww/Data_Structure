Tree* solve(Tree* root) {
     if(root == NULL)
    {
        return NULL;
    }
    root->left = solve(root->left);
    root->right = solve(root->right);

    if(root->val%2 == 0 && root->left == NULL && root->right == NULL)
    {
        return NULL;
    }

    return root;
}
