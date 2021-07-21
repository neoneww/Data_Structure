
void mirrorTree(BinaryTreeNode<int> *root) {
    if(root == NULL) return;
    BinaryTreeNode<int> *left = root->left;
    BinaryTreeNode<int> *right = root->right;
    root->left = right;
    root->right = left;
    mirrorTree(root->left);
    mirrorTree(root->right);
}
