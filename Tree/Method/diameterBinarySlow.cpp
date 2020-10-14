int height(Node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}

int diameter(Node* root) {
if(root ==  NULL)
    {
        return 0;
    }

    int option1 = (height(root->left) + height(root->right)) + 1;
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return max(option1,max(option2,option3));
}
