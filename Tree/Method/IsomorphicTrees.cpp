bool checkIsomorphism(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2){
    if(root1 == NULL && root2 != NULL || root1 != NULL && root2 == NULL)
    {
        return false;
    }
    if(root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if(root1->data != root2->data)
    {
        return false;
    }
    vector<vector<int>> finalAns1,finalAns2;
    vector<int> ans1,ans2;
    queue<BinaryTreeNode<int>*> pendingNodes1,pendingNodes2;
    pendingNodes1.push(root1);
    pendingNodes2.push(root2);

    while(pendingNodes1.size() != 0)
    {
        int cnt = pendingNodes1.size();
        while(cnt--)
        {
            BinaryTreeNode<int>* front = pendingNodes1.front();
            pendingNodes1.pop();    
            if(front->left != NULL)
            {
                pendingNodes1.push(root1->left);
                ans1.push_back(front->left->data);
            }
            if(front->right != NULL)
            {
                pendingNodes1.push(front->right);
                ans1.push_back(front->right->data);
            }
        }
        finalAns1.push_back(ans1);
        ans1.clear();
    }
    while(pendingNodes2.size() != 0)
    {
        int cnt = pendingNodes2.size();
        while(cnt--)
        {
            BinaryTreeNode<int>* front = pendingNodes2.front();
            pendingNodes2.pop();    
            if(front->left != NULL)
            {
                pendingNodes2.push(front->left);
                ans2.push_back(front->left->data);
            }
            if(root1->right != NULL)
            {
                pendingNodes1.push(front->right);
                ans2.push_back(front->right->data);
            }
        }
        reverse(ans2.begin(),ans2.end());
        finalAns2.push_back(ans2);
        ans2.clear();
    }

    if(finalAns1 == finalAns2)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
